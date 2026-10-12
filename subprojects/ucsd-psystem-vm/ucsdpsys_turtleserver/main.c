/*
 * UCSD p-System virtual machine
 * Copyright (C) 2000 Mario Klebsch
 * Copyright (C) 2006, 2010 Peter Miller
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
 * Turtle graphics server.  ucsdpsys_vm starts this program and sends it
 * turtle commands, one per line, on stdin; answers go back on stdout.
 * The picture is drawn into an off-screen bitmap and shown in an SDL
 * window.  Without a display, the bitmap is still kept, so programs
 * that read it back (SCREENBIT) keep working.
 */

#include <errno.h>
#include <getopt.h>
#include <libexplain/malloc.h>
#include <poll.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <SDL3/SDL.h>

#include <lib/progname.h>
#include <lib/turtle.h>
#include <lib/version.h>


#define SCALE 2                 /* initial window size, in screen pixels */

static SDL_Window       *Window;
static SDL_Renderer     *Renderer;
static SDL_Texture      *Texture;
static bool             NoVideo;
static bool             Dirty;

/* Copy the bitmap to the window.  Turtle y runs upward, SDL y downward. */
static void Present(void)
{
  static Uint32 Pixels[TURTLE_HEIGHT][TURTLE_WIDTH];
  int           x, y;

  if (!Texture)
    return;
  for (y=0; y<TURTLE_HEIGHT; y++)
    for (x=0; x<TURTLE_WIDTH; x++)
      Pixels[TURTLE_HEIGHT-1-y][x] = turtle_rgb(turtle_pixel(x, y));
  SDL_UpdateTexture(Texture, NULL, Pixels, sizeof(Pixels[0]));
  SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
  SDL_RenderClear(Renderer);
  SDL_RenderTexture(Renderer, Texture, NULL, NULL);
  SDL_RenderPresent(Renderer);
  Dirty = false;
}

static void OpenWindow(void)
{
  if (Window || NoVideo)
    return;

  /* Let ^C reach us normally, like the VM. */
  SDL_SetHint(SDL_HINT_NO_SIGNAL_HANDLERS, "1");
  if (!SDL_Init(SDL_INIT_VIDEO) ||
      !SDL_CreateWindowAndRenderer("Turtle Graphics", TURTLE_WIDTH*SCALE,
                                   TURTLE_HEIGHT*SCALE, SDL_WINDOW_RESIZABLE,
                                   &Window, &Renderer))
    {
      fprintf(stderr, "%s: no graphics display (%s), drawing off screen\n",
              progname_get(), SDL_GetError());
      NoVideo = true;
      Window = NULL;
      return;
    }
  Texture = SDL_CreateTexture(Renderer, SDL_PIXELFORMAT_XRGB8888,
                              SDL_TEXTUREACCESS_STREAMING, TURTLE_WIDTH,
                              TURTLE_HEIGHT);
  SDL_SetTextureScaleMode(Texture, SDL_SCALEMODE_NEAREST);
  SDL_SetRenderLogicalPresentation(Renderer, TURTLE_WIDTH, TURTLE_HEIGHT,
                                   SDL_LOGICAL_PRESENTATION_INTEGER_SCALE);
}

static void InitTurtle(void)
{
  OpenWindow();
  if (Window)
    SDL_ShowWindow(Window);
  turtle_init();
}

static unsigned char *BufEnd=NULL;
static unsigned char *RdPtr=NULL;

static int tgetchar(void)
{
  static unsigned char buffer[4096];
  if (RdPtr >= BufEnd)
    {
      ssize_t Len=read(0, buffer, sizeof(buffer));
      if ( Len < 1 )
        return(EOF);
      BufEnd = buffer + Len;
      RdPtr = buffer;
    }
  return *RdPtr++;
}

static void TurtleCommandHandler(void)
{
  int   i;
  int   ch;
  char  buffer[80];
  char  *p;

  do
    {
      for (i=0,p=buffer; i<79; i++,p++)
        {
          ch=tgetchar();
          if (ch == EOF)
            exit(0);    /* the VM has gone away */
          if (ch == '\n')
            break;
          *p=ch;
        }
      *p='\0';

      p = strchr(buffer, ' ');
      if (p)
        *p++='\0';
      else
        p = buffer + strlen(buffer);

      if (strcmp(buffer, "INITTURTLE")==0)
        InitTurtle();
      else if (strcmp(buffer, "TURN")==0)
        {
          if (sscanf( p, "%d", &i)==1)
            turtle_turn(i);
        }
      else if (strcmp(buffer, "TURNTO")==0)
        {
          if (sscanf( p, "%d", &i)==1)
            turtle_turnto(i);
        }
      else if (strcmp(buffer, "MOVE")==0)
        {
          if (sscanf( p, "%d", &i)==1)
            turtle_move(i);
        }
      else if (strcmp(buffer, "MOVETO")==0)
        {
          int y;
          int x;
          if (sscanf( p, "%d %d", &x, &y)==2)
            turtle_moveto(x, y);
        }
      else if (strcmp(buffer, "PENCOLOR")==0)
        {
          if (sscanf( p, "%d", &i)==1)
            turtle_pencolor(i);
        }
      else if (strcmp(buffer, "TEXTMODE")==0)
        {
          if (Window)
            SDL_HideWindow(Window);
        }
      else if (strcmp(buffer, "GRAFMODE")==0)
        {
          if (Window)
            SDL_ShowWindow(Window);
        }
      else if (strcmp(buffer, "FILLSCREEN")==0)
        {
          if (sscanf( p, "%d", &i)==1)
            turtle_fillscreen(i);
        }
      else if (strcmp(buffer, "VIEWPORT")==0)
        {
          int yMax;
          int yMin;
          int xMax;
          int xMin;
          if (sscanf(p, "%d %d %d %d", &xMin, &xMax, &yMin, &yMax)==4)
            turtle_viewport(xMin, xMax, yMin, yMax);
        }
      else if (strcmp(buffer, "TURTLEX")==0)
        {
          printf("%d\n",turtle_x());
          fflush(stdout);
        }
      else if (strcmp(buffer, "TURTLEY")==0)
        {
          printf("%d\n",turtle_y());
          fflush(stdout);
        }
      else if (strcmp(buffer, "TURTLEANG")==0)
        {
          printf("%d\n",turtle_angle());
          fflush(stdout);
        }
      else if (strcmp(buffer, "SCREENBIT")==0)
        {
          int y;
          int x;
          int bit = 0;
          if (sscanf(p, "%d %d",&x, &y)==2)
            bit = turtle_screenbit(x, y);
          printf("%c\n", bit ? '1' : '0');
          fflush(stdout);
        }
      else if (strcmp(buffer, "DRAWBLOCK")==0)
        {
          int x;
          int Mode;
          int YScreen;
          int XScreen;
          int Height;
          int Width;
          int YSkip;
          int XSkip;
          int RowSize;

          if (sscanf( p, "%d %d %d %d %d %d %d %d",
                      &RowSize, &XSkip, &YSkip,
                      &Width, &Height, &XScreen, &YScreen, &Mode)==8 &&
              Width > 0 && Height > 0)
            {
              /* each row is sent as the bytes its bits occupy */
              int  RowBytes = ((XSkip&7) + Width + 7) / 8;
              unsigned char *Data =
                explain_malloc_or_die((size_t)RowBytes * Height);

              (void)RowSize;
              (void)YSkip;
              for (x=0; x<RowBytes*Height; x++)
                {
                  int c = tgetchar();
                  if (c == EOF)
                    exit(0);
                  Data[x] = c;
                }
              turtle_drawblock(Data, RowBytes, XSkip, Width, Height,
                               XScreen, YScreen, Mode);
              free(Data);
            }
        }
      else if (strcmp(buffer, "WCHAR")==0)
        {
          if (sscanf(p, "%d",&i)==1)
            turtle_wchar(i&0xff);
        }
      else if (strcmp(buffer, "WSTRING")==0)
        {
          int  Len;
          int  j;
          if (sscanf(p, "%d",&Len)==1)
            for (j = 0; j < Len; j++)
              {
                ch = tgetchar();
                if (ch == EOF)
                  exit(0);
                turtle_wchar(ch);
              }
        }
      else if (strcmp(buffer, "CHARTYPE")==0)
        {
          if (sscanf(p, "%d", &i)==1)
            turtle_chartype(i);
        }
    }  while (RdPtr < BufEnd);
}

/* Handle window events; returns how long to wait for the next command. */
static int PumpEvents(void)
{
  SDL_Event     ev;

  if (!Window)
    return -1;
  while (SDL_PollEvent(&ev))
    {
      switch (ev.type)
        {
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
          /* The VM may still be drawing; just hide until GRAFMODE. */
          SDL_HideWindow(Window);
          break;

        case SDL_EVENT_WINDOW_EXPOSED:
        case SDL_EVENT_WINDOW_RESIZED:
        case SDL_EVENT_WINDOW_SHOWN:
          Dirty = true;
          break;
        }
    }
  if (turtle_take_dirty())
    Dirty = true;
  if (Dirty)
    Present();
  return 16;    /* about 60 times a second */
}

static const struct option options[] =
{
    { "version", 0, 0, 'V' },
    { 0, 0, 0, 0 }
};

static void
usage(void)
{
    const char *prog;

    prog = progname_get();
    fprintf(stderr, "Usage: %s\n", prog);
    fprintf(stderr, "       %s --version\n", prog);
    exit(1);
}

int
main(int argc, char **argv)
{
  progname_set(argv[0]);
  for (;;)
  {
    int             c;

    c = getopt_long(argc, argv, "V", options, 0);
    if (c < 0)
      break;
    switch (c)
    {
    case 'V':
      version_print();
      return 0;

    default:
      usage();
    }
  }
  if (optind < argc)
    usage();

  for (;;)
    {
      struct pollfd     pfd;
      int               n;

      pfd.fd = 0;
      pfd.events = POLLIN;
      pfd.revents = 0;
      n = poll(&pfd, 1, PumpEvents());
      if (n < 0 && errno != EINTR)
        {
          perror("poll");
          return 1;
        }
      if (n > 0)
        TurtleCommandHandler();
    }
}
