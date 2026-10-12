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

#ifndef UCSDPSYS_VM_TERM_H
#define UCSDPSYS_VM_TERM_H

#include <lib/memory.h>

/**
  * The TermOpen function is used to open the console.
  *
  * In batch mode (BatchFd >= 0) input comes from BatchFd and output goes
  * to stdout.  Otherwise the console is an SDL3 window when one can be
  * opened, or the controlling terminal (curses and termios).
  *
  * @param UseXTerm
  *     Run the console in a new xterm (terminal backend only).
  * @param BatchFd
  *     The batch input file descriptor, or -1.
  * @param UseTty
  *     Use the terminal even if a window could be opened.
  */
void TermOpen(int UseXTerm, int BatchFd, int UseTty);

/**
  * The TermClose function is used to restore the console at exit.
  */
void TermClose(void);

/**
  * The TermWrite function is used to write a character, interpreting
  * the p-System screen control codes.
  */
void TermWrite(char ch, word Mode);

/**
  * The TermRead function is used to read a character from the keyboard,
  * waiting for one if necessary.
  */
char TermRead(void);

/**
  * The TermStat function returns non-zero if a character is waiting.
  */
int TermStat(void);

int term_width(void);
int term_height(void);
int term_is_batch_mode(void);

/**
  * The term_has_graphics function returns non-zero if the console can
  * show Turtle Graphics itself (the SDL3 window).
  */
int term_has_graphics(void);

/**
  * The term_graphics_mode function switches the SDL3 window between
  * Turtle Graphics (non-zero) and text (zero).
  */
void term_graphics_mode(int on);

#endif /* UCSDPSYS_VM_TERM_H */
