// Author: David Mesa's
// dmesa.cpp
// This is showing my ability to code and my contribution to the group
//
//
#include <stdio.h>
#include "dmesa.h"
#include <GL/glx.h>

typedef struct t_rect 
{
    int left;
    int top;
    int right;
    int bot;
    int width;
    int height;
    int center;
    int centerx;
    int centery;
} Rect;

extern void ggprint8b(Rect *r, int advance, int cref, const char *fmt, ...);
extern void ggprint06(Rect *r, int advance, int cref, const char *fmt, ...);


// created a instance for credit screen 
Credits credits; 

// add showpage function for my credit screen 
//void Credits :: showPaget(int xres, int yres)
void Credits :: showPage(int yres)
{
    Rect r;

 //   glBindTexture(GL_TEXTURE_2D, g.forestTexture);
  //  glBegin(GL_QUADS);
  //  glTexCoord2f(0.0f, 1.0f); glVertex2i(0, 0);
  //  glTexCoord2f(0.0f, 0.0f); glVertex2i(0, g.yres);
  //  glTexCoord2f(1.0f, 0.0f); glVertex2i(g.xres, g.yres);
  //  glTexCoord2f(1.0f, 1.0f); glVertex2i(g.xres, 0);
  //  glEnd();

  // chooses color to  and displays name for credit space
  glClearColor(1.0,1.0,1.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  unsigned int c = 0x000000fff;
  r.bot = yres - 20;
  r.left = 10;
  r.center = 0;
//  ggprint8b(
//  glTranslate(xres/2,yres/2,0);
//  glEnd();
    ggprint8b(&r, 16, c, "David Mesa");
    ggprint8b(&r, 16, c, "Patrick Cruz");
    ggprint8b(&r, 16, c, "Aiesha Esa");
    ggprint8b(&r, 16, c, "Ranbir Grewal");

//    glEnd();
//  glClearColor(1.0,1.0,1.0,1.0);
//  glClear(GL_COLOR_BUFFER_BIT);
//  unsigned int d = 0x000000fff;
//  r.bot = yres - 300;
//  r.left = +100;
//  r.center = 0;
//    ggprint06(&r, 0, c, "falkdsfjlk;dasjf;l");




}

