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

#ifndef UCSDPSYS_VM_TERM_SDL_H
#define UCSDPSYS_VM_TERM_SDL_H

#include <ucsdpsys_vm/term_ops.h>

/*
 * The SDL3 window console backend, which also shows Turtle Graphics.
 * Without HAVE_SDL, or without a display, term_sdl_open returns NULL.
 */
const struct term_ops *term_sdl_open(void);
void term_sdl_close(void);
int term_sdl_active(void);
char term_sdl_read(void);
int term_sdl_stat(void);
int term_sdl_width(void);
int term_sdl_height(void);
void term_sdl_graphics_mode(int on);

#endif /* UCSDPSYS_VM_TERM_SDL_H */
