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
 * The console.  TermWrite interprets the p-System screen control codes
 * and passes the resulting operations to one of three backends:
 *
 *   batch  stdin/stdout, no screen control (used by the tests)
 *   sdl    an SDL3 window, see term_sdl.c (HAVE_SDL)
 *   tty    the controlling terminal via termios and terminfo (HAVE_CURSES)
 */

#include <fcntl.h>
#include <libexplain/write.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include <lib/psystem.h>
#include <lib/memory.h>
#include <ucsdpsys_vm/term.h>
#include <ucsdpsys_vm/term_sdl.h>
#include <ucsdpsys_vm/term_tty.h>


static const struct term_ops *Ops;
static int BatchMode = 0;
static int TermIn = -1;
static int TermOut = -1;


/* ---------- batch backend ---------------------------------------------- */

static void
batch_put(char ch)
{
    explain_write_or_die(TermOut, &ch, 1);
}


static void
batch_newline(void)
{
    batch_put('\n');
}


static void
batch_nothing(void)
{
}


static void
batch_gotoxy(int x, int y)
{
    (void)x;
    (void)y;
}


static const struct term_ops batch_ops =
{
    batch_put,
    batch_nothing,      /* bell */
    batch_newline,
    batch_nothing,      /* clear_eos */
    batch_nothing,      /* clear_screen */
    batch_nothing,      /* insert_line */
    batch_newline,      /* home */
    batch_nothing,      /* right */
    batch_nothing,      /* clear_eol */
    batch_gotoxy,
    batch_nothing,      /* up */
};


/* ---------- control code interpretation -------------------------------- */

/*
 * erase line=0
 * erase to end of screen=11
 * erase screen=12
 * insert line=22
 * move cursor home=25
 * move cursor right=28
 * erase to end of line=29
 * gotoxy=30
 * move cursor up=31
 */

void
TermWrite(char ch, word Mode)
{
    static int state = 0;
    static int x;
    int y;

    switch (state)
    {
    case 0:
        switch (ch)
        {
        case 0:
            /* erase line ??? */
            if (Mode & 0x8)
                Ops->put(ch);
            break;

        case 7:
            Ops->bell();
            break;

        case 11:
            Ops->clear_eos();
            break;

        case 12:
            Ops->clear_screen();
            break;

        case 13:
            /* carriage return */
            if (!(Mode & 0x4))
                Ops->newline();
            else
                Ops->put(ch);
            break;

        case 16:
            /* DLE prefix */
            if (!(Mode & 0x8))
                state = 3;
            break;

        case 22:
            Ops->insert_line();
            break;

        case 25:
            Ops->home();
            break;

        case 28:
            Ops->right();
            break;

        case 29:
            Ops->clear_eol();
            break;

        case 30:
            /* gotoxy */
            state = 1;
            break;

        case 31:
            Ops->up();
            break;

        default:
            Ops->put(ch);
            break;
        }
        break;

    case 1:
        x = ch - ' ';
        state = 2;
        break;

    case 2:
        /* gotoxy complete */
        y = ch - ' ';
        Ops->gotoxy(x, y);
        state = 0;
        break;

    case 3:
        /* char after DLE */
        ch -= 0x20;
        while (ch-- > 0)
            Ops->put(' ');
        state = 0;
        break;
    }
}


/* ---------- keyboard ---------------------------------------------------- */

struct translator
{
    struct translator *Next;
    const char *Pattern;
    byte Key;
};

static struct translator *Keys = NULL;


void
term_add_key_translation(unsigned char Key, const char *Pattern)
{
    struct translator *NewKey = malloc(sizeof(struct translator));
    if (!NewKey)
        abort();
    NewKey->Key = Key;
    NewKey->Pattern = Pattern;
    NewKey->Next = Keys;
    Keys = NewKey;
}


/*
 * Read a key from TermIn, turning escape sequences (such as cursor keys)
 * into p-System characters.
 */
static char
fd_read(void)
{
    unsigned char ch;

    static int state = 0;
    static int BufIdx = 0;
    static char Buffer[10];

    if (state == 0)
    {
        for (;;)
        {
            fd_set fds;
            struct timeval tv;
            FD_ZERO(&fds);
            FD_SET(TermIn, &fds);
            tv.tv_sec = 0;
            tv.tv_usec = 25000;

            if (!BatchMode)
                term_tty_poll_resize();
            if (select(TermIn + 1, &fds, NULL, NULL, BufIdx ? &tv : NULL) > 0)
            {
                /* a sign is available */
                struct translator *t;
                int Match = 0;

                if (read(TermIn, &ch, 1) < 1) /* Read and save in buffer */
                    if (BatchMode)
                        exit(0);

                if (ch == '\0') /* XXX Quick-Hack :-( */
                    continue;

                Buffer[BufIdx++] = ch;
                for (t = Keys; t; t = t->Next)
                {
                    int i;
                    for (i = 0; i < BufIdx; i++)
                        if (Buffer[i] != t->Pattern[i])
                            goto next;
                    if (!(t->Pattern[BufIdx])) /* full Pattern match */
                    {
                        BufIdx = 0;
                        return (t->Key);
                    }
                    Match = 1;
                    break;
                  next:
                    ;
                }
                if (!Match)
                    goto ret;
            }
            else /* Timeout                          */
            {
              ret:
                if (BufIdx > 1)
                    state = 1;
                else
                    BufIdx = 0;
                return (Buffer[0]);
            }
        }
    }
    else
    {
        ch = Buffer[state++];
        if (state >= BufIdx)
        {
            state = 0;
            BufIdx = 0;
        }
        return (ch);
    }
}


static int
fd_stat(void)
{
    fd_set fds;
    struct timeval tv;
    FD_ZERO(&fds);
    FD_SET(TermIn, &fds);
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    return (select(TermIn + 1, &fds, NULL, NULL, &tv) > 0);
}


char
TermRead(void)
{
    if (term_sdl_active())
        return term_sdl_read();
    return fd_read();
}


int
TermStat(void)
{
    if (term_sdl_active())
        return term_sdl_stat();
    return fd_stat();
}


/* ---------- opening and closing ----------------------------------------- */

void
TermOpen(int UseXTerm, int BatchFd, int UseTty)
{
    if (BatchFd >= 0)
    {
        BatchMode = 1;
        TermIn = BatchFd;
        TermOut = 1;
        Ops = &batch_ops;
        term_add_key_translation('\r', "\n");
        return;
    }

    if (!UseTty && !UseXTerm)
    {
        Ops = term_sdl_open();
        if (Ops)
            return;
    }

    Ops = term_tty_open(UseXTerm, &TermIn, &TermOut);
    if (!Ops)
    {
        fprintf(stderr, "ucsdpsys_vm: no console: built without SDL3 and "
            "curses, use --batch\n");
        exit(1);
    }
}


void
TermClose(void)
{
    if (!Ops)
        return;
    if (BatchMode)
    {
        explain_write_or_die(TermOut, "\n", 1);
        close(TermOut);
        close(TermIn);
    }
    else if (term_sdl_active())
        term_sdl_close();
    else
        term_tty_close();
    Ops = NULL;
}


int
term_width(void)
{
    int xcolumns = BatchMode ? 80 : term_sdl_active() ? term_sdl_width() :
        term_tty_width();

    if (xcolumns < 1)
        xcolumns = 1;
    else if (xcolumns >= 32768)
        xcolumns = 32767;
    return xcolumns;
}


int
term_height(void)
{
    int ylines = BatchMode ? 24 : term_sdl_active() ? term_sdl_height() :
        term_tty_height();

    if (ylines < 1)
        ylines = 1;
    else if (ylines >= 32768)
        ylines = 32767;
    return ylines;
}


int
term_is_batch_mode(void)
{
    return BatchMode;
}


int
term_has_graphics(void)
{
    return term_sdl_active();
}


void
term_graphics_mode(int on)
{
    if (term_sdl_active())
        term_sdl_graphics_mode(on);
}
