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

#include <math.h>
#include <stdlib.h>

#include <lib/turtle.h>


#define PENCOLOR_NONE           0
#define PENCOLOR_WHITE          1
#define PENCOLOR_BLACK          2
#define PENCOLOR_REVERSE        3
#define PENCOLOR_RADAR          4
#define PENCOLOR_BLACK1         5
#define PENCOLOR_GREEN          6
#define PENCOLOR_VIOLET         7
#define PENCOLOR_WHITE1         8
#define PENCOLOR_BLACK2         9
#define PENCOLOR_ORANGE         10
#define PENCOLOR_BLUE           11
#define PENCOLOR_WHITE2         12

#define NUMBER(a)       (sizeof(a)/sizeof(a[0]))

/* RGB value of each pen color; the pseudo colors show as black. */
static const unsigned long Palette[] = {0x000000, 0xFFFFFF, 0x000000,
                                        0x000000, 0x000000, 0x000000,
                                        0x00FF00, 0xEE82EE, 0xFFFFFF,
                                        0x000000, 0xFFA500, 0x0000FF,
                                        0xFFFFFF};

static const unsigned char SystemCharset[256*8]={
#include <lib/system.charset.h>
};

static struct
{
  int   xMin;
  int   xMax;
  int   yMin;
  int   yMax;
} CurrentViewPort;
static int      CurrentPenColor;
static int      CurrentTurtleX;
static int      CurrentTurtleY;
static int      CurrentTurtleAng;
static int      CurrentCharType;

/* Two pixels per byte. */
static unsigned char    Buffer[TURTLE_WIDTH * TURTLE_HEIGHT / 2];
static int              Initialized;
static int              Dirty;

static int GetPixel(int x, int y)
{
  unsigned char ch=Buffer[y*TURTLE_WIDTH/2+x/2];

  if ((x&1))
    return ((ch&0xf0)>>4);
  else
    return (ch&0x0f);
}

static void SetPixel(int x, int y, int Color)
{
  unsigned char         *p;
  static const char     Inverse[NUMBER(Palette)] =
                                {0, 2, 1, 0, 0, 8, 7, 6, 5, 12, 11, 10, 9};

  if ( (x<CurrentViewPort.xMin) || (x>CurrentViewPort.xMax) ||
       (y<CurrentViewPort.yMin) || (y>CurrentViewPort.yMax) ||
       (x<0) || (x>=TURTLE_WIDTH) || (y<0) || (y>=TURTLE_HEIGHT) )
    return;

  if (Color == PENCOLOR_NONE)
    return;
  else if (Color == PENCOLOR_REVERSE)
    Color=Inverse[GetPixel(x,y)];

  p = &Buffer[y * TURTLE_WIDTH / 2 + x / 2];
  if ((x&1))
    *p=(*p&0x0f)|(Color<<4);
  else
    *p=(*p&0xf0)|Color;
  Dirty = 1;
}

static void Line(int len, int ticks, const int *LenVec, const int *TickVec)
{
  int   i=len/2;
  int   j;

  for (j=0;j<len; j++)
    {
      CurrentTurtleX+=LenVec[0];
      CurrentTurtleY+=LenVec[1];
      i+=ticks;
      if (i>=len)
        {
          i-=len;
          CurrentTurtleX+=TickVec[0];
          CurrentTurtleY+=TickVec[1];
        }
      SetPixel(CurrentTurtleX, CurrentTurtleY, CurrentPenColor);
    }
}

void turtle_moveto(int x, int y)
{
  static const int right[] ={ 1,  0};
  static const int left[]  ={-1,  0};
  static const int up[]    ={ 0,  1};
  static const int down[]  ={ 0, -1};

  if (Initialized && (CurrentPenColor!=PENCOLOR_NONE) )
    {
      int dx=x-CurrentTurtleX;
      int dy=y-CurrentTurtleY;
      if ( (dx>0) && (abs(dy)<=dx) )
        Line(dx, abs(dy), right, (dy>0)?up:down);
      else if ( (dx<0) && (abs(dy)<=-dx) )
        Line(-dx, abs(dy), left, (dy>0)?up:down);
      else if ( (dy>0) && (abs(dx)<=dy) )
        Line(dy, abs(dx), up, (dx>0)?right:left);
      else
        Line(-dy, abs(dx), down, (dx>0)?right:left);
    }
  CurrentTurtleX=x;
  CurrentTurtleY=y;
}

void turtle_turnto(int Angle)
{
  CurrentTurtleAng=Angle;
  while (CurrentTurtleAng<0)
    CurrentTurtleAng+=360;
  while (CurrentTurtleAng>=360)
    CurrentTurtleAng-=360;
}

void turtle_turn(int degrees)
{
  turtle_turnto(CurrentTurtleAng + degrees);
}

void turtle_move(int distance)
{
  /* 3.14 rather than M_PI, as in the original */
  turtle_moveto(CurrentTurtleX+round(cos(CurrentTurtleAng*3.14/180)*distance),
                CurrentTurtleY+round(sin(CurrentTurtleAng*3.14/180)*distance));
}

void turtle_pencolor(int color)
{
  CurrentPenColor = color;
}

void turtle_fillscreen(int Color)
{
  int   x, y;

  if (!Initialized)
    return;
  for (y=CurrentViewPort.yMin; y<=CurrentViewPort.yMax; y++)
    for (x=CurrentViewPort.xMin; x<=CurrentViewPort.xMax; x++)
      SetPixel(x, y, Color);
}

void turtle_viewport(int xmin, int xmax, int ymin, int ymax)
{
  CurrentViewPort.xMin=xmin;
  CurrentViewPort.xMax=xmax;
  CurrentViewPort.yMin=ymin;
  CurrentViewPort.yMax=ymax;
}

int turtle_x(void)
{
  return CurrentTurtleX;
}

int turtle_y(void)
{
  return CurrentTurtleY;
}

int turtle_angle(void)
{
  return CurrentTurtleAng;
}

int turtle_screenbit(int x, int y)
{
  return Initialized && x >= 0 && x < TURTLE_WIDTH && y >= 0 &&
         y < TURTLE_HEIGHT && GetPixel(x, y) != PENCOLOR_BLACK;
}

static void DrawByte(unsigned char Data, int XSkip, int Width,
                     int XScreen, int YScreen, int Mode)
{
  static const int      ModeTable[16][2]={
    {PENCOLOR_BLACK, PENCOLOR_BLACK},   {PENCOLOR_REVERSE, PENCOLOR_BLACK},
    {PENCOLOR_BLACK, PENCOLOR_REVERSE}, {PENCOLOR_REVERSE, PENCOLOR_REVERSE},
    {PENCOLOR_NONE,  PENCOLOR_BLACK},   {PENCOLOR_WHITE,   PENCOLOR_BLACK},
    {PENCOLOR_NONE,  PENCOLOR_REVERSE}, {PENCOLOR_WHITE,   PENCOLOR_REVERSE},
    {PENCOLOR_BLACK, PENCOLOR_NONE},    {PENCOLOR_REVERSE, PENCOLOR_NONE},
    {PENCOLOR_BLACK, PENCOLOR_WHITE},   {PENCOLOR_REVERSE, PENCOLOR_WHITE},
    {PENCOLOR_NONE,  PENCOLOR_NONE},    {PENCOLOR_WHITE,   PENCOLOR_NONE},
    {PENCOLOR_NONE,  PENCOLOR_WHITE},   {PENCOLOR_WHITE,   PENCOLOR_WHITE}   };
  int i;

  for (i=0;i<Width; i++)
    {
      int pixel;
      if ( (i+XSkip) > 7 )
        break;
      pixel = Data & (1 << (i+XSkip) ) ? 1:0;
      SetPixel(XScreen+i, YScreen, ModeTable[Mode&15][pixel]);
    }
}

void turtle_drawblock(const unsigned char *data, int rowbytes, int xskip,
    int width, int height, int xscreen, int yscreen, int mode)
{
  int x;
  int y;

  if (!Initialized)
    return;
  for (y=0; y<height; y++)
    {
      const unsigned char *row = data + y * rowbytes;
      int  Skip=xskip&7;
      for (x=0;x<width;)
        {
          int  W=width-x;

          if ( W > 8-Skip)
            W = 8-Skip;
          DrawByte(*row++, Skip, W, xscreen+x, yscreen+y, mode);
          x+=W;
          Skip=0;
        }
    }
}

void turtle_wchar(unsigned char ch)
{
  int   y;

  if (!Initialized)
    return;
  for (y=0; y<8; y++)
    DrawByte(SystemCharset[ch*8+y], 0, 7,
             CurrentTurtleX, CurrentTurtleY+y, CurrentCharType);
  CurrentTurtleX += 7;
}

void turtle_chartype(int mode)
{
  CurrentCharType = mode & 0x0f;
}

void turtle_init(void)
{
  Initialized = 1;
  turtle_viewport(0, TURTLE_WIDTH-1, 0, TURTLE_HEIGHT-1);
  turtle_fillscreen(PENCOLOR_BLACK);
  CurrentTurtleX=CurrentViewPort.xMax/2;
  CurrentTurtleY=CurrentViewPort.yMax/2;
  CurrentTurtleAng=0;
  CurrentCharType=10;
  CurrentPenColor=PENCOLOR_NONE;
  Dirty = 1;
}

int turtle_initialized(void)
{
  return Initialized;
}

int turtle_pixel(int x, int y)
{
  return Initialized ? GetPixel(x, y) : PENCOLOR_BLACK;
}

unsigned long turtle_rgb(int color)
{
  return (color >= 0 && (unsigned)color < NUMBER(Palette)) ? Palette[color] : 0;
}

int turtle_take_dirty(void)
{
  int was = Dirty;
  Dirty = 0;
  return was;
}

unsigned char turtle_font_row(unsigned char c, int row)
{
  return SystemCharset[c * 8 + (row & 7)];
}
