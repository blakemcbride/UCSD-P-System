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
 * The terminal console backend: the controlling terminal (or a new
 * xterm) in raw mode via termios, with terminfo for the screen control
 * strings.
 */

#include <stddef.h>

#include <ucsdpsys_vm/term_tty.h>

#ifdef HAVE_CURSES

#include <fcntl.h>
#include <libexplain/accept.h>
#include <libexplain/bind.h>
#include <libexplain/getsockname.h>
#include <libexplain/listen.h>
#include <libexplain/open.h>
#include <libexplain/socket.h>
#include <libexplain/system.h>
#include <libexplain/write.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <curses.h>
#include <netinet/in.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <term.h>
#include <termios.h>

#if defined(SIGWINCH) && defined(TIOCGWINSZ)
#define CAN_RESIZE 1
#endif


static int TermOut = -1;
static struct termios OldTerm;


#ifdef CAN_RESIZE

static volatile sig_atomic_t sigwinch_happened;


static void
sigwinch(int signum)
{
    (void)signum;
    sigwinch_happened = 1;
    signal(SIGWINCH, sigwinch);
}

#endif /* CAN_RESIZE */


void
term_tty_poll_resize(void)
{
#ifdef CAN_RESIZE
    struct winsize  size;

    if (!sigwinch_happened)
        return;
    if (ioctl(fileno(stdout), TIOCGWINSZ, &size) == 0)
    {
        resize_term(size.ws_row, size.ws_col);
        wrefresh(curscr);
        LINES = size.ws_row;
        COLS = size.ws_col;
    }
    sigwinch_happened = 0;
#endif
}


static void
out(const char *s)
{
    if (s)
        explain_write_or_die(TermOut, s, strlen(s));
}


static void
tty_put(char ch)
{
    explain_write_or_die(TermOut, &ch, 1);
}


static void tty_bell(void)         { tty_put(7); }
static void tty_newline(void)      { out("\r\n"); }
static void tty_clear_eos(void)    { out(clr_eos); }
static void tty_clear_screen(void) { out(clear_screen); }
static void tty_insert_line(void)  { out(insert_line); }
static void tty_right(void)        { out(cursor_right); }
static void tty_clear_eol(void)    { out(clr_eol); }
static void tty_up(void)           { out(cursor_up); }


static void
tty_home(void)
{
    out(cursor_home ? cursor_home : "\n");
}


static void
tty_gotoxy(int x, int y)
{
    if (cursor_address)
        out(tgoto(cursor_address, x, y));
}


static const struct term_ops tty_ops =
{
    tty_put,
    tty_bell,
    tty_newline,
    tty_clear_eos,
    tty_clear_screen,
    tty_insert_line,
    tty_home,
    tty_right,
    tty_clear_eol,
    tty_gotoxy,
    tty_up,
};


static void
OpenXTerm(void)
{
    socklen_t i;
    int s;
    struct sockaddr_in addr;
    char Buffer[256];

    unsigned char TelnetInit[] = { 255, 253, 3, 255, 251, 3, 255, 251, 1 };

    s = explain_socket_or_die(PF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    addr.sin_port = htons(0);
    explain_bind_or_die(s, (struct sockaddr *)&addr, sizeof(addr));
    explain_listen_or_die(s, 1);
    i = sizeof(addr);
    explain_getsockname_or_die(s, (struct sockaddr *)&addr, &i);

    snprintf(Buffer, sizeof(Buffer), "xterm -geometry 80x24 -e "
        "telnet -E localhost %d&", ntohs(addr.sin_port));
    explain_system_success_or_die(Buffer);

    i = sizeof(addr);
    TermOut = explain_accept_or_die(s, (struct sockaddr *)&addr, &i);

    close(s);

    explain_write_or_die(TermOut, TelnetInit, sizeof(TelnetInit));
    for (i = 0; i < sizeof(TelnetInit); i++)
    {
        if (read(TermOut, &s, 1) <= 0)
            break;
    }
}


const struct term_ops *
term_tty_open(int UseXTerm, int *TermInp, int *TermOutp)
{
    struct termios NewTerm;

#ifdef CAN_RESIZE
    signal(SIGWINCH, sigwinch);
#endif
    if (UseXTerm)
    {
        OpenXTerm();
        setupterm("xterm", TermOut, NULL);
    }
    else
    {
        TermOut = explain_open_or_die("/dev/tty", O_RDWR, 0666);
        setupterm(NULL, TermOut, NULL);
    }
    *TermInp = TermOut;
    *TermOutp = TermOut;

    tcgetattr(TermOut, &OldTerm);
    NewTerm = OldTerm;
    NewTerm.c_iflag &= ~(PARMRK | ISTRIP | INLCR | IGNCR |
        ICRNL | IUCLC | IXOFF | IXON);
    NewTerm.c_oflag &= ~OPOST;
    NewTerm.c_lflag &= ~(ISIG | ICANON | ECHO | ECHONL | IEXTEN);
    NewTerm.c_cc[VMIN] = 1;
    NewTerm.c_cc[VTIME] = 0;
    tcsetattr(TermOut, TCSANOW, &NewTerm);

    out(init_1string);
    out(init_2string);
    out(init_3string);
    out(enter_ca_mode);

    term_add_key_translation(0x0b, "\033[A");
    term_add_key_translation(0x0a, "\033[B");
    term_add_key_translation(0x15, "\033[C");
    term_add_key_translation(0x08, "\033[D");

    term_add_key_translation(0x0b, "\033[OA");
    term_add_key_translation(0x0a, "\033[OB");
    term_add_key_translation(0x15, "\033[OC");
    term_add_key_translation(0x08, "\033[OD");

    if (key_up)
        term_add_key_translation(0x0b, key_up);
    if (key_down)
        term_add_key_translation(0x0a, key_down);
    if (key_right)
        term_add_key_translation(0x15, key_right);
    if (key_left)
        term_add_key_translation(0x08, key_left);
    return &tty_ops;
}


void
term_tty_close(void)
{
#ifdef CAN_RESIZE
    signal(SIGWINCH, SIG_IGN);
#endif
    out("\r\n");
    out(exit_ca_mode);
    out(reset_1string);
    out(reset_2string);
    out(reset_3string);
    tcsetattr(TermOut, TCSANOW, &OldTerm);
    close(TermOut);
}


int
term_tty_width(void)
{
    term_tty_poll_resize();
    return COLS;
}


int
term_tty_height(void)
{
    term_tty_poll_resize();
    return LINES;
}

#else /* !HAVE_CURSES */

const struct term_ops *
term_tty_open(int UseXTerm, int *TermIn, int *TermOut)
{
    (void)UseXTerm;
    (void)TermIn;
    (void)TermOut;
    return NULL;
}

void term_tty_close(void) { }
int term_tty_width(void) { return 80; }
int term_tty_height(void) { return 24; }
void term_tty_poll_resize(void) { }

#endif /* HAVE_CURSES */
