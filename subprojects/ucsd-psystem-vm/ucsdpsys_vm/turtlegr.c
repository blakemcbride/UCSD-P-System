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

#include <libexplain/execlp.h>
#include <libexplain/fork.h>
#include <libexplain/malloc.h>
#include <libexplain/socketpair.h>
#include <math.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>

#include <lib/memory.h>
#include <lib/pcode.h>
#include <lib/psystem.h>
#include <lib/turtle.h>

#include <ucsdpsys_vm/stack.h>
#include <ucsdpsys_vm/term.h>
#include <ucsdpsys_vm/turtlegr.h>

#ifdef TURTLEGRAPHICS

static FILE *TurtleServer = NULL;

#define TURTLE_SPEEDUP

#ifdef TURTLE_SPEEDUP
static Integer CurrentTurtleX;
static Integer CurrentTurtleY;
static Integer CurrentTurtleAng;
#endif


static void
StartTurtleServer(void)
{
    int fd[2];
    int pid;
    int i;

    /*
     * If the server can't start, writes to it fail; don't let that
     * kill the VM.
     */
    signal(SIGPIPE, SIG_IGN);

    if (explain_socketpair_on_error(PF_UNIX, SOCK_STREAM, 0, fd) < 0)
        return;
    pid = explain_fork_on_error();
    if (pid < 0)
        return;
    if (!pid)
    {
        if (fd[1] != 0)
        {
            close(0);
            dup2(fd[1], 0);
        }
        if (fd[1] != 1)
        {
            close(1);
            dup2(fd[1], 1);
        }
        for (i = getdtablesize(); i > 2; i--)
            close(i);
        explain_execlp_or_die
        (
            "ucsdpsys_turtleserver",
            "ucsdpsys_turtleserver",
            NULL
        );
    }
    close(fd[1]);
    TurtleServer = fdopen(fd[0], "wb+");
}


static void
tprintf(char *format, ...)
{
    va_list ap;
    if (!TurtleServer)
        StartTurtleServer();

    if (TurtleServer)
    {
        va_start(ap, format);
        vfprintf(TurtleServer, format, ap);
        va_end(ap);
        putc('\n', TurtleServer);
    }
}


static Integer
tgetint(void)
{
    int i = 0;
    char Buffer[20];

    if (!TurtleServer)
        return 0;
    fflush(TurtleServer);

    for (i = 0; i < 19; i++)
    {
        int c = getc(TurtleServer);
        if (c == EOF || c == '\n')
            break;
        Buffer[i] = c;
    }

    Buffer[i] = '\0';

    if (sscanf(Buffer, "%d", &i) != 1)
        i = 0;
    return ((Integer) i);
}


#ifdef TURTLE_SPEEDUP

static void
TurnTo(int Angle)
{
    CurrentTurtleAng = Angle;
    while (CurrentTurtleAng < 0)
        CurrentTurtleAng += 360;
    while (CurrentTurtleAng >= 360)
        CurrentTurtleAng -= 360;
}

#endif


/*
 * With the SDL console, Turtle Graphics are drawn in its window by the
 * VM itself; otherwise the commands go to ucsdpsys_turtleserver.
 */
#define INPROC term_has_graphics()


void
TurtleGraphics(word EntryPoint)
{
    size_t i;
    char func[64];
    char *p;

    i = 0;
    for (i = 0; i < sizeof(func); i++)
    {
        if (!(func[i] = MemRdByte(EntryPoint, i)))
            break;
    }

    p = &func[16];
    if (strcmp(p, "INITTURTLE") == 0)
    {
        if (INPROC)
        {
            turtle_init();
            term_graphics_mode(1);
        }
        else
            tprintf("INITTURTLE");
#ifdef TURTLE_SPEEDUP
        CurrentTurtleX = 139;
        CurrentTurtleY = 95;
        CurrentTurtleAng = 0;
#endif
    }
    else if (strcmp(p, "TURN") == 0)
    {
        Integer j = PopInteger();
        if (INPROC)
            turtle_turn(j);
        else
            tprintf("TURN %d", j);
#ifdef TURTLE_SPEEDUP
        TurnTo(CurrentTurtleAng + j);
#endif
    }
    else if (strcmp(p, "TURNTO") == 0)
    {
        Integer j = PopInteger();
        if (INPROC)
            turtle_turnto(j);
        else
            tprintf("TURNTO %d", j);
#ifdef TURTLE_SPEEDUP
        TurnTo(j);
#endif
    }
    else if (strcmp(p, "MOVE") == 0)
    {
        Integer j = PopInteger();
        if (INPROC)
            turtle_move(j);
        else
            tprintf("MOVE %d", j);
#ifdef TURTLE_SPEEDUP
        CurrentTurtleX += round(cos(CurrentTurtleAng * 3.14 / 180) * j);
        CurrentTurtleY += round(sin(CurrentTurtleAng * 3.14 / 180) * j);
#endif
    }
    else if (strcmp(p, "MOVETO") == 0)
    {
        Integer y = PopInteger();
        Integer x = PopInteger();
        if (INPROC)
            turtle_moveto(x, y);
        else
            tprintf("MOVETO %d %d", x, y);
#ifdef TURTLE_SPEEDUP
        CurrentTurtleX = x;
        CurrentTurtleY = y;
#endif
    }
    else if (strcmp(p, "PENCOLOR") == 0)
    {
        word c = Pop();
        if (INPROC)
            turtle_pencolor(c);
        else
            tprintf("PENCOLOR %d", c);
    }
    else if (strcmp(p, "TEXTMODE") == 0)
    {
        if (INPROC)
            term_graphics_mode(0);
        else
            tprintf("TEXTMODE");
    }
    else if (strcmp(p, "GRAFMODE") == 0)
    {
        if (INPROC)
            term_graphics_mode(1);
        else
            tprintf("GRAFMODE");
    }
    else if (strcmp(p, "FILLSCREEN") == 0)
    {
        word c = Pop();
        if (INPROC)
            turtle_fillscreen(c);
        else
            tprintf("FILLSCREEN %d", c);
    }
    else if (strcmp(p, "VIEWPORT") == 0)
    {
        int yMax = PopInteger();
        int yMin = PopInteger();
        int xMax = PopInteger();
        int xMin = PopInteger();
        if (INPROC)
            turtle_viewport(xMin, xMax, yMin, yMax);
        else
            tprintf("VIEWPORT %d %d %d %d", xMin, xMax, yMin, yMax);
    }
    else if (strcmp(p, "TURTLEX") == 0)
    {
        Pop();
        Pop();
        if (INPROC)
            Push(turtle_x());
        else
        {
#ifdef TURTLE_SPEEDUP
            Push(CurrentTurtleX);
#else
            tprintf("TURTLEX");
            Push(tgetint());
#endif
        }
    }
    else if (strcmp(p, "TURTLEY") == 0)
    {
        Pop();
        Pop();
        if (INPROC)
            Push(turtle_y());
        else
        {
#ifdef TURTLE_SPEEDUP
            Push(CurrentTurtleY);
#else
            tprintf("TURTLEY");
            Push(tgetint());
#endif
        }
    }
    else if (strcmp(p, "TURTLEANG") == 0)
    {
        Pop();
        Pop();
        if (INPROC)
            Push(turtle_angle());
        else
        {
#ifdef TURTLE_SPEEDUP
            Push(CurrentTurtleAng);
#else
            tprintf("TURTLEANG");
            Push(tgetint());
#endif
        }
    }
    else if (strcmp(p, "SCREENBIT") == 0)
    {
        Integer y;
        Integer x;

        /* the function result space is on top, as for TURTLEX */
        Pop();
        Pop();
        y = PopInteger();
        x = PopInteger();
        if (INPROC)
            Push(turtle_screenbit(x, y));
        else
        {
            tprintf("SCREENBIT %d %d", x, y);
            Push(tgetint());
        }
    }
    else if (strcmp(p, "DRAWBLOCK") == 0)
    {
        int x;
        int y;
        Integer Mode = PopInteger();
        Integer YScreen = PopInteger();
        Integer XScreen = PopInteger();
        Integer Height = PopInteger();
        Integer Width = PopInteger();
        Integer YSkip = PopInteger();
        Integer XSkip = PopInteger();
        Integer RowSize = PopInteger();
        word Source = Pop();
        /* the bytes each row's bits occupy, from bit XSkip on */
        int RowBytes = ((XSkip & 7) + Width + 7) / 8;
        unsigned char *Data;

        if (Width <= 0 || Height <= 0)
            return;
        Data = explain_malloc_or_die((size_t)RowBytes * Height);
        for (y = 0; y < Height; y++)
            for (x = 0; x < RowBytes; x++)
                Data[y * RowBytes + x] =
                    MemRdByte(Source, (y + YSkip) * RowSize + XSkip / 8 + x);
        if (INPROC)
            turtle_drawblock(Data, RowBytes, XSkip & 7, Width, Height,
                XScreen, YScreen, Mode);
        else
        {
            tprintf("DRAWBLOCK %d %d %d %d %d %d %d %d", RowBytes, XSkip & 7,
                0, Width, Height, XScreen, YScreen, Mode);
            if (TurtleServer)
                fwrite(Data, RowBytes, Height, TurtleServer);
        }
        free(Data);
    }
    else if (strcmp(p, "WCHAR") == 0)
    {
        int c = Pop() & 0xff;
        if (INPROC)
            turtle_wchar(c);
        else
            tprintf("WCHAR %d", c);
#ifdef TURTLE_SPEEDUP
        CurrentTurtleX += 7;
#endif
    }
    else if (strcmp(p, "WSTRING") == 0)
    {
        word Addr = Pop();
        int Len = MemRdByte(Addr, 0);
        int j;

        if (INPROC)
        {
            for (j = 0; j < Len; j++)
                turtle_wchar(MemRdByte(Addr, j + 1));
        }
        else
        {
            tprintf("WSTRING %d", Len);
            for (j = 0; j < Len && TurtleServer; j++)
                putc(MemRdByte(Addr, j + 1), TurtleServer);
        }
#ifdef TURTLE_SPEEDUP
        CurrentTurtleX += 7 * Len;
#endif
    }
    else if (strcmp(p, "CHARTYPE") == 0)
    {
        int c = Pop() & 0x0f;
        if (INPROC)
            turtle_chartype(c);
        else
            tprintf("CHARTYPE %d", c);
    }
    else
        XeqError(XNOTIMP);
    if (TurtleServer)
        fflush(TurtleServer);
}


void
GraphicsClear(void)
{
    int status;

    if (INPROC)
        term_graphics_mode(0);
    if (TurtleServer)
    {
        fclose(TurtleServer);
        TurtleServer = NULL;
        wait(&status);
    }
}

#endif /* TURTLEGRAPHICS */
