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
#include "fonts.h"
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

// created a instance for credit screen 
Credits credits; 

// add showpage function for my credit screen 
void Credits :: showPage(int xres, int yres, unsigned int texid,
        unsigned int texid2,unsigned int texid3, 
        unsigned int texid4, int wd, int h)
{

    Rect r;

    // Background Color
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // For Printing out name
    // David Mesa
    unsigned int c = 0x00ffff;
    r.bot = yres - 20;
    r.left = 20;
    r.center =0;

    ggprint06(&r, 16, c, "David Mesa");

    //Patrick Cruz
    unsigned int d = 0xaa0000;
    r.bot = yres - 20;
    r.left = 170;
    r.center =0;

    ggprint06(&r, 16, d, "Patrick Cruz");

    //Aiesha Esa
    unsigned int a = 0x00ff00;
    r.bot = yres - 20;
    r.left = 320;
    r.center =0;

    ggprint06(&r, 16, a, "Aiesha Esa");

    //Ranbir Grewal
    unsigned int b = 0xaa0000;
    r.bot = yres - 20;
    r.left = 470;
    r.center =0;

    ggprint06(&r, 16, b, "Ranbir Grewal");

    //Triangle in the background of credits page    
    glPushMatrix();
  //  glColor3f(1.0f,1.0f,0.0f);
//      glClearColor(1.0f,1.0f,0.0f,0.0f);
 //   glClear(GL_COLOR_BUFFER_BIT);

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

    // Davids Picture
    glPushMatrix();

    glTranslatef(xres-600,yres-100,0);
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

    //Patricks Picture
    glPushMatrix();

    glTranslatef(xres-450,yres-100,0);
    float q = 50.0;
    glColor3ub(255,255,255);
    glBindTexture(GL_TEXTURE_2D,texid2);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f,1.0f); glVertex2f(-q,-q);
    glTexCoord2f(0.0f,0.0f); glVertex2f(-q, q);
    glTexCoord2f(1.0f,0.0f); glVertex2f( q, q);
    glTexCoord2f(1.0f,1.0f); glVertex2f( q,-q);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

    //Aeishia's Picture
    glPushMatrix();

    glTranslatef(xres-300,yres-100,0);
    float p = 50.0;
    glColor3ub(255,255,255);
    glBindTexture(GL_TEXTURE_2D,texid3);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f,1.0f); glVertex2f(-p,-p);
    glTexCoord2f(0.0f,0.0f); glVertex2f(-p, p);
    glTexCoord2f(1.0f,0.0f); glVertex2f( p, p);
    glTexCoord2f(1.0f,1.0f); glVertex2f( p,-p);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

    //Ranbir's Picture
    glPushMatrix();

    glTranslatef(xres-150,yres-100,0);
    float t = 50.0;
    glColor3ub(255,255,255);
    glBindTexture(GL_TEXTURE_2D,texid4);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f,1.0f); glVertex2f(-t,-t);
    glTexCoord2f(0.0f,0.0f); glVertex2f(-t, t);
    glTexCoord2f(1.0f,0.0f); glVertex2f( t, t);
    glTexCoord2f(1.0f,1.0f); glVertex2f( t,-t);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

}

Texture tex;
void Texture :: maketext(unsigned int texid, int width, int height,
        const void* img)
{   
    glBindTexture(GL_TEXTURE_2D, texid);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height , 0,
            GL_RGB, GL_UNSIGNED_BYTE, img);
    glBindTexture(GL_TEXTURE_2D,0);
}

Background background;

void Background :: home(int bxres,int byres,unsigned int texid5)
{
    Rect r;
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //Menu options
    unsigned int c = 0x00ffff;
    r.bot = byres - 300;
    r.left = bxres-360;
    r.center =0;

    ggprint06(&r, 16, c, "C - Credit Screen");
    ggprint06(&r, 16, c, "b - Begin game");
    ggprint06(&r, 16, c, "g - Gameplay controls");

    //Game Name
    unsigned int d = 0xff0000;
    r.bot = byres -100;
    r.left = bxres- 360;
    r.center =0;

    ggprint06(&r, 16, d, "College Survival");

    glPushMatrix();

    //Main Menu picture
    glTranslatef(bxres/2,byres-200,0);
    float t = 75;
    glColor3ub(255,255,255);
    glBindTexture(GL_TEXTURE_2D,texid5);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f,1.0f); glVertex2f(-t,-t);
    glTexCoord2f(0.0f,0.0f); glVertex2f(-t, t);
    glTexCoord2f(1.0f,0.0f); glVertex2f( t, t);
    glTexCoord2f(1.0f,1.0f); glVertex2f( t,-t);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);

    glPopMatrix();

}
