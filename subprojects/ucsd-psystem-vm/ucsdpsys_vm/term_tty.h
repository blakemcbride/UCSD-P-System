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

#ifndef UCSDPSYS_VM_TERM_TTY_H
#define UCSDPSYS_VM_TERM_TTY_H

#include <ucsdpsys_vm/term_ops.h>

/*
 * The terminal console backend: termios and terminfo (curses).
 * Without HAVE_CURSES, term_tty_open returns NULL.
 */
const struct term_ops *term_tty_open(int UseXTerm, int *TermIn,
    int *TermOut);
void term_tty_close(void);
int term_tty_width(void);
int term_tty_height(void);
void term_tty_poll_resize(void);

#endif /* UCSDPSYS_VM_TERM_TTY_H */
