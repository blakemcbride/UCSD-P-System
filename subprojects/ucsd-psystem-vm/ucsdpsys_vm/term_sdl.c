/*
 * UCSD p-System virtual machine
 * Copyright (C) 2000 Mario Klebsch
 * Copyright (C) 2010 Peter Miller
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>
 */

/*
 * The SDL3 window console backend: an 80x24 text screen drawn with a
 * terminal-style font (see console_font.py), keyboard input from SDL events, and Turtle Graphics
 * shown in the same window (GRAFMODE / TEXTMODE switch between them,
 * and so does F2, since the system doesn't return to text by itself
 * when a graphics program ends).
 */

#include <stddef.h>

#include <ucsdpsys_vm/term_sdl.h>

#ifdef HAVE_SDL

#include <stdlib.h>
#include <string.h>
#include <SDL3/SDL.h>

#include <lib/turtle.h>
#include <ucsdpsys_vm/console_font.h>
#include <ucsdpsys_vm/term.h>

#define COLUMNS         80
#define ROWS            24
#define FOREGROUND      0xD8D8D8
#define BACKGROUND      0x000000
#define FRAME_MS        33      /* refresh at most this often while busy */

static int              Active;
static SDL_Window       *Window;
static SDL_Renderer     *Renderer;
static SDL_Texture      *TextTexture;

/* The font size in use, chosen for the display's pixel density. */
static const unsigned char *Glyphs;
static int              CellW;
static int              CellH;
static int              TextW;
static int              TextH;
static Uint32           *TextPixels;
static SDL_Texture      *GraphicsTexture;
static int              GraphicsMode;
static int              Dirty;
static Uint64           LastPresent;

static unsigned char    Screen[ROWS][COLUMNS];
static int              CursorX;
static int              CursorY;

/* Keys typed but not yet read. */
static unsigned char    KeyQueue[256];
static unsigned         KeyHead;
static unsigned         KeyTail;


/* ---------- the text screen ------------------------------------------- */

static void
scroll_up(void)
{
    memmove(Screen[0], Screen[1], sizeof(Screen) - sizeof(Screen[0]));
    memset(Screen[ROWS - 1], ' ', COLUMNS);
}


static void
line_feed(void)
{
    if (CursorY < ROWS - 1)
        CursorY++;
    else
        scroll_up();
}


static void
changed(void)
{
    Dirty = 1;
}


static void
sdl_put(char c)
{
    unsigned char ch = c;

    switch (ch)
    {
    case '\n':
        line_feed();
        break;

    case '\r':
        CursorX = 0;
        break;

    case '\b':
        if (CursorX > 0)
            CursorX--;
        break;

    case '\t':
        CursorX = (CursorX + 8) & ~7;
        if (CursorX >= COLUMNS)
            CursorX = COLUMNS - 1;
        break;

    default:
        if (ch < ' ')
            return;
        if (CursorX >= COLUMNS)
        {
            CursorX = 0;
            line_feed();
        }
        Screen[CursorY][CursorX++] = ch;
        break;
    }
    changed();
}


static void
sdl_bell(void)
{
}


static void
sdl_newline(void)
{
    CursorX = 0;
    line_feed();
    changed();
}


static void
sdl_clear_eol(void)
{
    if (CursorX < COLUMNS)
        memset(&Screen[CursorY][CursorX], ' ', COLUMNS - CursorX);
    changed();
}


static void
sdl_clear_eos(void)
{
    int y;

    sdl_clear_eol();
    for (y = CursorY + 1; y < ROWS; y++)
        memset(Screen[y], ' ', COLUMNS);
}


static void
sdl_clear_screen(void)
{
    memset(Screen, ' ', sizeof(Screen));
    CursorX = 0;
    CursorY = 0;
    changed();
}


static void
sdl_insert_line(void)
{
    memmove(Screen[CursorY + 1], Screen[CursorY],
        (ROWS - 1 - CursorY) * sizeof(Screen[0]));
    memset(Screen[CursorY], ' ', COLUMNS);
    changed();
}


static void
sdl_home(void)
{
    CursorX = 0;
    CursorY = 0;
    changed();
}


static void
sdl_right(void)
{
    if (CursorX < COLUMNS - 1)
        CursorX++;
    changed();
}


static void
sdl_up(void)
{
    if (CursorY > 0)
        CursorY--;
    changed();
}


static void
sdl_gotoxy(int x, int y)
{
    CursorX = x < 0 ? 0 : x >= COLUMNS ? COLUMNS - 1 : x;
    CursorY = y < 0 ? 0 : y >= ROWS ? ROWS - 1 : y;
    changed();
}


/* ---------- drawing ---------------------------------------------------- */

static Uint32
blend(int a, Uint32 fg, Uint32 bg)
{
    Uint32 c = 0;
    int shift;

    for (shift = 0; shift < 24; shift += 8)
    {
        int f = (fg >> shift) & 0xFF;
        int b = (bg >> shift) & 0xFF;
        c |= (Uint32)(b + (f - b) * a / 255) << shift;
    }
    return c;
}


static void
render_text(void)
{
    static Uint32   Normal[256];
    static Uint32   Inverse[256];
    int             row;
    int             col;

    if (!Normal[255])
    {
        int a;

        for (a = 0; a < 256; a++)
        {
            Normal[a] = blend(a, FOREGROUND, BACKGROUND);
            Inverse[a] = blend(a, BACKGROUND, FOREGROUND);
        }
    }
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLUMNS; col++)
        {
            unsigned char c = Screen[row][col];
            const Uint32 *lut =
                (row == CursorY && col == CursorX) ? Inverse : Normal;
            const unsigned char *g = NULL;
            int y;

            if (c >= CONSOLE_FONT_FIRST && c <= CONSOLE_FONT_LAST)
                g = Glyphs + (size_t)(c - CONSOLE_FONT_FIRST) * CellW * CellH;
            for (y = 0; y < CellH; y++)
            {
                Uint32 *p = TextPixels + (size_t)(row * CellH + y) * TextW +
                    col * CellW;
                int x;

                for (x = 0; x < CellW; x++)
                    p[x] = lut[g ? g[y * CellW + x] : 0];
            }
        }
    }
    SDL_UpdateTexture(TextTexture, NULL, TextPixels, TextW * sizeof(Uint32));
}


static void
render_graphics(void)
{
    static Uint32   Pixels[TURTLE_HEIGHT][TURTLE_WIDTH];
    int             x;
    int             y;

    /* Turtle y runs upward, SDL y downward. */
    for (y = 0; y < TURTLE_HEIGHT; y++)
        for (x = 0; x < TURTLE_WIDTH; x++)
            Pixels[TURTLE_HEIGHT - 1 - y][x] = turtle_rgb(turtle_pixel(x, y));
    SDL_UpdateTexture(GraphicsTexture, NULL, Pixels, sizeof(Pixels[0]));
}


static void
present(void)
{
    if (GraphicsMode)
    {
        render_graphics();
        SDL_SetRenderLogicalPresentation(Renderer, TURTLE_WIDTH,
            TURTLE_HEIGHT, SDL_LOGICAL_PRESENTATION_INTEGER_SCALE);
    }
    else
    {
        render_text();
        SDL_SetRenderLogicalPresentation(Renderer, TextW, TextH,
            SDL_LOGICAL_PRESENTATION_LETTERBOX);
    }
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    SDL_RenderClear(Renderer);
    SDL_RenderTexture(Renderer, GraphicsMode ? GraphicsTexture : TextTexture,
        NULL, NULL);
    SDL_RenderPresent(Renderer);
    Dirty = 0;
    LastPresent = SDL_GetTicks();
}


static void
present_if_needed(int now)
{
    if (GraphicsMode && turtle_take_dirty())
        Dirty = 1;
    if (Dirty && (now || SDL_GetTicks() - LastPresent >= FRAME_MS))
        present();
}


/* ---------- keyboard and window events --------------------------------- */

static void
key_add(unsigned char c)
{
    if (KeyTail - KeyHead < sizeof(KeyQueue))
        KeyQueue[KeyTail++ % sizeof(KeyQueue)] = c;
}


static void
key_down(const SDL_KeyboardEvent *k)
{
    switch (k->key)
    {
    case SDLK_F2:
        /* look at the other screen; the p-System doesn't see this key */
        GraphicsMode = !GraphicsMode;
        Dirty = 1;
        return;

    case SDLK_RETURN:
    case SDLK_KP_ENTER:
        key_add('\r');
        return;

    case SDLK_BACKSPACE:
    case SDLK_LEFT:
        key_add(0x08);
        return;

    case SDLK_TAB:
        key_add('\t');
        return;

    case SDLK_ESCAPE:
        key_add(0x1b);
        return;

    case SDLK_DELETE:
        key_add(0x7f);
        return;

    case SDLK_UP:
        key_add(0x0b);
        return;

    case SDLK_DOWN:
        key_add(0x0a);
        return;

    case SDLK_RIGHT:
        key_add(0x15);
        return;
    }

    /* Control characters; these arrive as no text input. */
    if ((k->mod & SDL_KMOD_CTRL) && !(k->mod & SDL_KMOD_ALT))
    {
        if (k->key >= SDLK_A && k->key <= SDLK_Z)
            key_add(k->key - SDLK_A + 1);
        else if (k->key == SDLK_LEFTBRACKET)
            key_add(0x1b);
        else if (k->key == SDLK_BACKSLASH)
            key_add(0x1c);
        else if (k->key == SDLK_RIGHTBRACKET)
            key_add(0x1d);
    }
}


static void
handle_event(const SDL_Event *ev)
{
    switch (ev->type)
    {
    case SDL_EVENT_QUIT:
    case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
        /* like hanging up the terminal */
        TermClose();
        exit(0);

    case SDL_EVENT_KEY_DOWN:
        key_down(&ev->key);
        break;

    case SDL_EVENT_TEXT_INPUT:
        {
            const unsigned char *s = (const unsigned char *)ev->text.text;

            /* Ctrl combinations were handled as key presses. */
            if (SDL_GetModState() & SDL_KMOD_CTRL)
                break;
            for (; *s; s++)
                if (*s >= ' ' && *s < 0x7f)
                    key_add(*s);
        }
        break;

    case SDL_EVENT_WINDOW_EXPOSED:
    case SDL_EVENT_WINDOW_RESIZED:
    case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
        Dirty = 1;
        break;
    }
}


static void
pump(void)
{
    SDL_Event ev;

    while (SDL_PollEvent(&ev))
        handle_event(&ev);
}


char
term_sdl_read(void)
{
    while (KeyHead == KeyTail)
    {
        SDL_Event ev;

        present_if_needed(1);
        if (SDL_WaitEventTimeout(&ev, 100))
        {
            handle_event(&ev);
            pump();
        }
    }
    return KeyQueue[KeyHead++ % sizeof(KeyQueue)];
}


int
term_sdl_stat(void)
{
    pump();
    present_if_needed(0);
    return KeyHead != KeyTail;
}


/*
 * Output goes through here too, so the window keeps up while a program
 * writes without reading.
 */
static void
sdl_after_write(void)
{
    if (SDL_GetTicks() - LastPresent >= FRAME_MS)
    {
        pump();
        present_if_needed(1);
    }
}


#define WRAP0(name) static void name##_w(void) { name(); sdl_after_write(); }
WRAP0(sdl_bell)
WRAP0(sdl_newline)
WRAP0(sdl_clear_eos)
WRAP0(sdl_clear_screen)
WRAP0(sdl_insert_line)
WRAP0(sdl_home)
WRAP0(sdl_right)
WRAP0(sdl_clear_eol)
WRAP0(sdl_up)
static void sdl_put_w(char c) { sdl_put(c); sdl_after_write(); }
static void sdl_gotoxy_w(int x, int y) { sdl_gotoxy(x, y); sdl_after_write(); }


static const struct term_ops sdl_ops =
{
    sdl_put_w,
    sdl_bell_w,
    sdl_newline_w,
    sdl_clear_eos_w,
    sdl_clear_screen_w,
    sdl_insert_line_w,
    sdl_home_w,
    sdl_right_w,
    sdl_clear_eol_w,
    sdl_gotoxy_w,
    sdl_up_w,
};


/* ---------- opening and closing ----------------------------------------- */

const struct term_ops *
term_sdl_open(void)
{
    /* Let ^C reach the p-System as a key, and the shell as usual. */
    SDL_SetHint(SDL_HINT_NO_SIGNAL_HANDLERS, "1");
    if (!SDL_Init(SDL_INIT_VIDEO))
        return NULL;
    /* sized like an 80x24 terminal */
    if (!SDL_CreateWindowAndRenderer("UCSD p-System (F2: text/graphics)",
            COLUMNS * CONSOLE_FONT_1X_W, ROWS * CONSOLE_FONT_1X_H,
            SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY, &Window,
            &Renderer))
    {
        SDL_Quit();
        return NULL;
    }
    if (SDL_GetWindowPixelDensity(Window) >= 1.5f)
    {
        Glyphs = &console_font_2x[0][0];
        CellW = CONSOLE_FONT_2X_W;
        CellH = CONSOLE_FONT_2X_H;
    }
    else
    {
        Glyphs = &console_font_1x[0][0];
        CellW = CONSOLE_FONT_1X_W;
        CellH = CONSOLE_FONT_1X_H;
    }
    TextW = COLUMNS * CellW;
    TextH = ROWS * CellH;
    TextPixels = malloc((size_t)TextW * TextH * sizeof(Uint32));
    TextTexture = SDL_CreateTexture(Renderer, SDL_PIXELFORMAT_XRGB8888,
        SDL_TEXTUREACCESS_STREAMING, TextW, TextH);
    GraphicsTexture = SDL_CreateTexture(Renderer, SDL_PIXELFORMAT_XRGB8888,
        SDL_TEXTUREACCESS_STREAMING, TURTLE_WIDTH, TURTLE_HEIGHT);
    if (!TextPixels || !TextTexture || !GraphicsTexture)
    {
        SDL_DestroyRenderer(Renderer);
        SDL_DestroyWindow(Window);
        SDL_Quit();
        return NULL;
    }
    /* smooth when the window is resized, like a terminal font */
    SDL_SetTextureScaleMode(TextTexture, SDL_SCALEMODE_LINEAR);
    SDL_SetTextureScaleMode(GraphicsTexture, SDL_SCALEMODE_NEAREST);
    SDL_StartTextInput(Window);

    memset(Screen, ' ', sizeof(Screen));
    Active = 1;
    present();
    return &sdl_ops;
}


void
term_sdl_close(void)
{
    if (!Active)
        return;
    Active = 0;
    SDL_StopTextInput(Window);
    SDL_DestroyTexture(TextTexture);
    free(TextPixels);
    SDL_DestroyTexture(GraphicsTexture);
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}


int
term_sdl_active(void)
{
    return Active;
}


int
term_sdl_width(void)
{
    return COLUMNS;
}


int
term_sdl_height(void)
{
    return ROWS;
}


void
term_sdl_graphics_mode(int on)
{
    if (GraphicsMode != !!on)
    {
        GraphicsMode = !!on;
        present();
    }
}

#else /* !HAVE_SDL */

const struct term_ops *term_sdl_open(void) { return NULL; }
void term_sdl_close(void) { }
int term_sdl_active(void) { return 0; }
char term_sdl_read(void) { return 0; }
int term_sdl_stat(void) { return 0; }
int term_sdl_width(void) { return 80; }
int term_sdl_height(void) { return 24; }
void term_sdl_graphics_mode(int on) { (void)on; }

#endif /* HAVE_SDL */
