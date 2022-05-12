// Author: Aiesha Esa
// This file includes the work I did on this project
//
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <X11/Xlib.h>
//#include <X11/Xutil.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
#include <X11/keysym.h>
#include <GL/glx.h>
#include "log.h"
#include <iostream>
//#include "ppm.h"
#include "fonts.h"
#include "dmesa.h"
//#include "college_survival.cpp"

//extern class Texture tex;
extern class Character bad_guy;

class Survival {
	public:

	int done;
	int xres, yres;
	GLuint bigfootTexture;
    GLuint marcoTexture;

    unsigned int texid;
	int showBigfoot;
	Survival() {
		logOpen();
		done=0;
		xres=800;
		yres=600;
    }
	~Survival() {
		logClose();
	}
} survival;

typedef double Vec[3];
 
class Enemy {
	public:
		Vec pos;
		Vec vel;
} enemy;


void rm() {
	extern void ggprint8b(Rect *r, int advance, int cref, const char *fmt, ...);
	extern void ggprint06(Rect *r, int advance, int cref, const char *fmt, ...);

	Rect r;
	int yres = 0;
	char menu = 0;
	switch(menu) {
		case 'g':
			glClearColor(0.0f,0.0f,0.0f,0.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			// For Printing out name
			unsigned int c = 0x00ffff;
			r.bot = yres - 20;
			r.left = 20;
			r.center =0;
			//ggprint06(&r, 16, c, "To move left use left arrow key");
	}
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


Image image[7] = {
"./images/metalslug.png",
"./images/campus.png",
"./images/forestTrans.png",
"./images/umbrella.png",
"./images/King.png",
"./images/Main.jfif",
"./images/enemy.png"
};


void EnemyMovement(){
    int w = image[6].width;
	int h = image[6].height;
	//
	glBindTexture(GL_TEXTURE_2D, survival.bigfootTexture);
	//
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, w, h, 0,
		GL_RGB, GL_UNSIGNED_BYTE, image[6].data);



    int addgrav = 1;
	//Update position
	enemy.pos[0] += enemy.vel[0];
	enemy.pos[1] += enemy.vel[1];
	//Check for collision with window edges
	if ((enemy.pos[0] < -140.0 && enemy.vel[0] < 0.0) ||
		(enemy.pos[0] >= (float)survival.xres+140.0 &&
		enemy.vel[0] > 0.0))
	{
		enemy.vel[0] = -enemy.vel[0];
		addgrav = 0;
	}
	if ((enemy.pos[1] < 150.0 && enemy.vel[1] < 0.0) ||
		(enemy.pos[1] >= (float)survival.yres && enemy.vel[1] > 0.0)) {
		enemy.vel[1] = -enemy.vel[1];
		addgrav = 0;
	}
	if (addgrav)
		enemy.vel[1] -= 0.75;

	//
	//
}


/*
Aiesha a_midterm;

bool Aiesha::aesa_midterm(int a) {
    bool test = false;
    if (a < 27)
        test = true;

    return test;
}
*/
