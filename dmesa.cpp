// Author: David Mesa's
// dmesa.cpp
// This is showing my ability to code and my contribution to the group
//
//
#include <unistd.h>
#include <stdio.h>
#include "dmesa.h"
#include <GL/glx.h>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
Dmesa dmesa;

void Dmesa :: dmesa(int a )
{
    int b = 10;
    for(int i = 0; i <= b;++i)
    {
        cout << a << "*" << i << "=" << a * i << endl;
    }
}


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
void Credits :: showPage(int xres, int yres, unsigned int texid, int wd, int h)
{


  Rect r;
  glClearColor(1.0f,1.0f,0.0f,0.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3ub(0,0,255);
  glPushMatrix();

   static float rot = 0.0;
   static float angle = 0.0;
   glTranslatef(xres/2,yres/2,0);
   glRotatef(rot,0.0f,0.0f,1.0f);
   glTranslatef(-xres/2, -yres/2,0);
   rot = sin(angle)* 20;
   angle +=1.5;

   glBegin(GL_TRIANGLES);
     glVertex2f(20.0,20.0);
     glVertex2f(xres/2.0,yres-20);
     glVertex2f(xres-20,20.0);
   glEnd();
   glPopMatrix(); 
   
    // chooses color to  and displays name for credit space
//  glClearColor(0.0f,0.0f,0.0f,0.0f);
// glClear(GL_COLOR_BUFFER_BIT);
 unsigned int c = 0x00ffff;
    r.bot = yres - 20;
    r.left = 10;
    r.center =0;
    ggprint06(&r, 16, c, "David Mesa");

    unsigned int d = 0xaa0000;
    r.bot = yres - 20;
    r.left = 100;
    r.center =0;

    ggprint06(&r, 16, d, "Patrick Cruz");

    unsigned int a = 0x00ff00;
    r.bot = yres - 20;
    r.left = 200;
    r.center =0;

    ggprint06(&r, 16, a, "Aiesha Esa");

    unsigned int b = 0xaa0000;
    r.bot = yres - 20;
    r.left = 300;
    r.center =0;

    ggprint06(&r, 16, b, "Ranbir Grewal");

    glPushMatrix();
    glTranslatef(xres/2,yres/2,0);
    float w = 50.0;
    glColor3ub(255,255,255);
    glBindTexture(GL_TEXTURE_2D,texid);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f,1.0f); glVertex2f(-w,-w);
        glTexCoord2f(0.0f,0.0f); glVertex2f(-w, w);
        glTexCoord2f(1.0f,0.0f); glVertex2f( w, w);
        glTexCoord2f(1.0f,1.0f); glVertex2f( w,-w);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

}
Texture tex;
void Texture :: maketext(unsigned int texid, int width, int height, const void* img)
{   
    glBindTexture(GL_TEXTURE_2D, texid);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height , 0,
    GL_RGB, GL_UNSIGNED_BYTE, img);
    glBindTexture(GL_TEXTURE_2D,0);
}


