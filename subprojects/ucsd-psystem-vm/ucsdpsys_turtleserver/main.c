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
#include <math.h>
#include <poll.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <SDL3/SDL.h>

#include <lib/progname.h>
#include <lib/version.h>


#define XSIZE 280
#define YSIZE 192
#define SCALE 2                 /* initial window size, in screen pixels */

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
static const Uint32     Palette[] = {0x000000, 0xFFFFFF, 0x000000, 0x000000,
                                     0x000000, 0x000000, 0x00FF00, 0xEE82EE,
                                     0xFFFFFF, 0x000000, 0xFFA500, 0x0000FF,
                                     0xFFFFFF};

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

/* Two pixels per byte, NULL until INITTURTLE. */
static unsigned char    *Buffer  = NULL;

static SDL_Window       *Window;
static SDL_Renderer     *Renderer;
static SDL_Texture      *Texture;
static bool             NoVideo;
static bool             Dirty;

static int GetPixel(int x, int y)
{
  unsigned char ch=Buffer[y*XSIZE/2+x/2];

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
       (x<0) || (x>=XSIZE) || (y<0) || (y>=YSIZE) )
    return;

  if (Color == PENCOLOR_NONE)
    return;
  else if (Color == PENCOLOR_REVERSE)
    Color=Inverse[GetPixel(x,y)];

  p = &Buffer[y * XSIZE / 2 + x / 2];
  if ((x&1))
    *p=(*p&0x0f)|(Color<<4);
  else
    *p=(*p&0xf0)|Color;
  Dirty = true;
}

static void Line(int len, int ticks, int *LenVec, int *TickVec)
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

static void MoveTo(int x, int y)
{
  static int right[] ={ 1,  0};
  static int left[]  ={-1,  0};
  static int up[]    ={ 0,  1};
  static int down[]  ={ 0, -1};

  if (Buffer && (CurrentPenColor!=PENCOLOR_NONE) )
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

static void TurnTo(int Angle)
{
  CurrentTurtleAng=Angle;
  while (CurrentTurtleAng<0)
    CurrentTurtleAng+=360;
  while (CurrentTurtleAng>=360)
    CurrentTurtleAng-=360;
}

static void FillScreen(int Color)
{
  int   x, y;

  for (y=CurrentViewPort.yMin; y<=CurrentViewPort.yMax; y++)
    for (x=CurrentViewPort.xMin; x<=CurrentViewPort.xMax; x++)
      SetPixel(x, y, Color);
}

static void DrawByte(char Data, int XSkip, int Width,
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

static void WChar(unsigned char ch)
{
  int   y;
  static const char     SystemCharset[256*8]={
#include <ucsdpsys_turtleserver/system.charset.h>
  };

  for (y=0; y<8; y++)
    DrawByte(SystemCharset[ch*8+y], 0, 7,
             CurrentTurtleX, CurrentTurtleY+y, CurrentCharType);
  CurrentTurtleX += 7;
}

/* Copy the bitmap to the window.  Turtle y runs upward, SDL y downward. */
static void Present(void)
{
  static Uint32 Pixels[YSIZE][XSIZE];
  int           x, y;

  if (!Texture)
    return;
  for (y=0; y<YSIZE; y++)
    for (x=0; x<XSIZE; x++)
      {
        unsigned c = GetPixel(x, y);
        Pixels[YSIZE-1-y][x] = c < NUMBER(Palette) ? Palette[c] : 0;
      }
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
      !SDL_CreateWindowAndRenderer("Turtle Graphics", XSIZE*SCALE,
                                   YSIZE*SCALE, SDL_WINDOW_RESIZABLE,
                                   &Window, &Renderer))
    {
      fprintf(stderr, "%s: no graphics display (%s), drawing off screen\n",
              progname_get(), SDL_GetError());
      NoVideo = true;
      Window = NULL;
      return;
    }
  Texture = SDL_CreateTexture(Renderer, SDL_PIXELFORMAT_XRGB8888,
                              SDL_TEXTUREACCESS_STREAMING, XSIZE, YSIZE);
  SDL_SetTextureScaleMode(Texture, SDL_SCALEMODE_NEAREST);
  SDL_SetRenderLogicalPresentation(Renderer, XSIZE, YSIZE,
                                   SDL_LOGICAL_PRESENTATION_INTEGER_SCALE);
}

static void InitTurtle(void)
{
  if (!Buffer)
    Buffer = explain_malloc_or_die(XSIZE * YSIZE / 2);
  OpenWindow();
  if (Window)
    SDL_ShowWindow(Window);

  CurrentViewPort.xMin=0;
  CurrentViewPort.xMax=XSIZE-1;
  CurrentViewPort.yMin=0;
  CurrentViewPort.yMax=YSIZE-1;
  FillScreen(PENCOLOR_BLACK);
  CurrentTurtleX=CurrentViewPort.xMax/2;
  CurrentTurtleY=CurrentViewPort.yMax/2;
  CurrentTurtleAng=0;
  CurrentCharType=10;
  CurrentPenColor=PENCOLOR_NONE;
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
            TurnTo(CurrentTurtleAng+i);
        }
      else if (strcmp(buffer, "TURNTO")==0)
        {
          if (sscanf( p, "%d", &i)==1)
            TurnTo(i);
        }
      else if (strcmp(buffer, "MOVE")==0)
        {
          if (sscanf( p, "%d", &i)==1)
            MoveTo(CurrentTurtleX+round(cos(CurrentTurtleAng*3.14/180)*i),
                   CurrentTurtleY+round(sin(CurrentTurtleAng*3.14/180)*i));
        }
      else if (strcmp(buffer, "MOVETO")==0)
        {
          int y;
          int x;
          if (sscanf( p, "%d %d", &x, &y)==2)
            MoveTo(x, y);
        }
      else if (strcmp(buffer, "PENCOLOR")==0)
        {
          if (sscanf( p, "%d", &i)==1)
            CurrentPenColor=i;
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
            if (Buffer)
              FillScreen(i);
        }
      else if (strcmp(buffer, "VIEWPORT")==0)
        {
          int yMax;
          int yMin;
          int xMax;
          int xMin;
          if (sscanf(p, "%d %d %d %d", &xMin, &xMax, &yMin, &yMax)==4)
            {
              CurrentViewPort.yMax=yMax;
              CurrentViewPort.yMin=yMin;
              CurrentViewPort.xMax=xMax;
              CurrentViewPort.xMin=xMin;
            }
        }
      else if (strcmp(buffer, "TURTLEX")==0)
        {
          printf("%d\n",CurrentTurtleX);
          fflush(stdout);
        }
      else if (strcmp(buffer, "TURTLEY")==0)
        {
          printf("%d\n",CurrentTurtleY);
          fflush(stdout);
        }
      else if (strcmp(buffer, "TURTLEANG")==0)
        {
          printf("%d\n",CurrentTurtleAng);
          fflush(stdout);
        }
      else if (strcmp(buffer, "SCREENBIT")==0)
        {
          int y;
          int x;
          int bit = 0;
          if (sscanf(p, "%d %d",&x, &y)==2)
            bit = Buffer && x >= 0 && x < XSIZE && y >= 0 && y < YSIZE &&
                  GetPixel(x,y) != PENCOLOR_BLACK;
          printf("%c\n", bit ? '1' : '0');
          fflush(stdout);
        }
      else if (strcmp(buffer, "DRAWBLOCK")==0)
        {
          int x;
          int y;
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
                      &Width, &Height, &XScreen, &YScreen, &Mode)==8)
            {
              for (y=0; y<Height; y++)
                {
                  int  Skip=XSkip&7;
                  for (x=0;x<Width;)
                    {
                      int  W=Width-x;
                      int  Data=tgetchar();

                      if (Data == EOF)
                        exit(0);
                      if ( W > 8-Skip)
                        W = 8-Skip;

                      if (Buffer)
                        DrawByte(Data, Skip, W, XScreen+x, YScreen+y, Mode);
                      x+=W;
                      Skip=0;
                    }
                }
            }
        }
      else if (strcmp(buffer, "WCHAR")==0)
        {
          if (sscanf(p, "%d",&i)==1)
            if (Buffer)
              WChar(i&0xff);
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
                if (Buffer)
                  WChar(ch);
              }
        }
      else if (strcmp(buffer, "CHARTYPE")==0)
        {
          if (sscanf(p, "%d", &i)==1)
            CurrentCharType=i&0x0f;
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
