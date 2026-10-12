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

#ifndef UCSDPSYS_VM_TERM_OPS_H
#define UCSDPSYS_VM_TERM_OPS_H

/*
 * The screen operations a console backend provides.  TermWrite turns
 * the p-System control codes into calls of these.
 */
struct term_ops
{
    void (*put)(char ch);       /* any other character, written as is */
    void (*bell)(void);
    void (*newline)(void);      /* carriage return: start of next line */
    void (*clear_eos)(void);
    void (*clear_screen)(void);
    void (*insert_line)(void);
    void (*home)(void);
    void (*right)(void);
    void (*clear_eol)(void);
    void (*gotoxy)(int x, int y);
    void (*up)(void);
};

/**
  * The term_add_key_translation function is used to make an input
  * escape sequence (Pattern) read as a single p-System key.
  */
void term_add_key_translation(unsigned char Key, const char *Pattern);

#endif /* UCSDPSYS_VM_TERM_OPS_H */
