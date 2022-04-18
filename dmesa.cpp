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
#include <string.h>
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
void Credits :: showPage(int xres, int yres)
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
}
class Image {
public:
    int width, height;
    unsigned char *data;
    ~Image() { delete [] data; }
    Image(const char *fname) {
        if (fname[0] == '\0')
            return;
        //printf("fname **%s**\n", fname);
        int ppmFlag = 0;
        char name[40];
        strcpy(name, fname);
        int slen = strlen(name);
        char ppmname[80];
        if (strncmp(name+(slen-4), ".ppm", 4) == 0)
            ppmFlag = 1;
        if (ppmFlag) {
            strcpy(ppmname, name);
        } else {
            name[slen-4] = '\0';
            //printf("name **%s**\n", name);
            sprintf(ppmname,"%s.ppm", name);
            //printf("ppmname **%s**\n", ppmname);
            char ts[100];
            //system("convert eball.jpg eball.ppm");
            sprintf(ts, "convert %s %s", fname, ppmname);
            system(ts);
        }
        //sprintf(ts, "%s", name);
        FILE *fpi = fopen(ppmname, "r");
        if (fpi) {
            char line[200];
            fgets(line, 200, fpi);
            fgets(line, 200, fpi);
            //skip comments and blank lines
            while (line[0] == '#' || strlen(line) < 2)
                fgets(line, 200, fpi);
            sscanf(line, "%i %i", &width, &height);
            fgets(line, 200, fpi);
            //get pixel data
            int n = width * height * 3;
            data = new unsigned char[n];
            for (int i=0; i<n; i++)
                data[i] = fgetc(fpi);
            fclose(fpi);
        } else {
            printf("ERROR opening image: %s\n",ppmname);
            exit(0);
        }
        if (!ppmFlag)
            unlink(ppmname);
    }
};

// Aiesha changed Bigfoot image to metalslug, and forest image to campus
/*Image img[4] = {
"./images/metalslug.png",
"./images/campus.png",
"./images/forestTrans.png",
"./images/umbrella.png" };
*/

