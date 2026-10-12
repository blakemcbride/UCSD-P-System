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

#ifndef LIB_TURTLE_H
#define LIB_TURTLE_H

/*
 * The Turtle Graphics drawing engine: an Apple II style 280x192 screen
 * with 13 pen colors.  It only draws into memory; ucsdpsys_turtleserver
 * and the VM's SDL console put the result on screen.
 *
 * Coordinates have (0,0) at the bottom left, y increasing upward.
 */

#define TURTLE_WIDTH  280
#define TURTLE_HEIGHT 192

/**
  * The turtle_init function implements INITTURTLE: it clears the
  * screen and resets the turtle, viewport, pen and character mode.
  */
void turtle_init(void);

/**
  * The turtle_initialized function returns non-zero once turtle_init
  * has been called.  Drawing before that is ignored.
  */
int turtle_initialized(void);

void turtle_turn(int degrees);
void turtle_turnto(int degrees);
void turtle_move(int distance);
void turtle_moveto(int x, int y);
void turtle_pencolor(int color);
void turtle_fillscreen(int color);
void turtle_viewport(int xmin, int xmax, int ymin, int ymax);
int turtle_x(void);
int turtle_y(void);
int turtle_angle(void);

/**
  * The turtle_screenbit function returns non-zero if the given pixel
  * is not black.
  */
int turtle_screenbit(int x, int y);

/**
  * The turtle_drawblock function implements DRAWBLOCK.  The data holds
  * the bits of each row, rowbytes bytes per row, least significant bit
  * leftmost, the first row's first xskip bits ignored.
  */
void turtle_drawblock(const unsigned char *data, int rowbytes, int xskip,
    int width, int height, int xscreen, int yscreen, int mode);

void turtle_wchar(unsigned char c);
void turtle_chartype(int mode);

/**
  * The turtle_pixel function returns the color index (0..15) of the
  * given pixel, for display.
  */
int turtle_pixel(int x, int y);

/**
  * The turtle_rgb function returns the 0xRRGGBB value of a color index.
  */
unsigned long turtle_rgb(int color);

/**
  * The turtle_take_dirty function returns non-zero if the picture has
  * changed since it was last called.
  */
int turtle_take_dirty(void);

/**
  * The turtle_font_row function returns row (0..7, 0 at the bottom) of
  * the 7x8 bit-mapped glyph for the given character, least significant
  * bit leftmost.
  */
unsigned char turtle_font_row(unsigned char c, int row);

#endif /* LIB_TURTLE_H */
