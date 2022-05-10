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
<<<<<<< HEAD
extern class Texture tex;



=======
>>>>>>> f7cabbe584b5b5eb2a5e49d3db97308c754aed57
class College {
public:

	int done;
	int xres, yres;
	GLuint bigfootTexture;
    GLuint marcoTexture;

    unsigned int texid;
	int showBigfoot;
	College() {
		logOpen();
		done=0;
		xres=800;
		yres=600;
    }
	~College() {
		logClose();
	}
} college;


 typedef double Vec[3];
 class Marco{
public:
	Vec pos;
	Vec vel;
} marcos;


void rm(){
extern void ggprint8b(Rect *r, int advance, int cref, const char *fmt, ...);
extern void ggprint06(Rect *r, int advance, int cref, const char *fmt, ...);


Rect r;
int yres = 0;
char menu = 0;
switch(menu){
       case 'g':
     glClearColor(0.0f,0.0f,0.0f,0.0f);
     glClear(GL_COLOR_BUFFER_BIT);

    // For Printing out name
    unsigned int c = 0x00ffff;
    r.bot = yres - 20;
    r.left = 20;
    r.center =0;
    ggprint06(&r, 16, c, "To move left use left arrow key");

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
;		if (ppmFlag) {
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


Image image[6] = {
"./images/metalslug.png",
"./images/campus.png",
"./images/forestTrans.png",
"./images/umbrella.png",
"./images/King.png",
"./images/Main.jfif"
};


void Marcosmovement(){
    int w = image[0].width;
	int h = image[0].height;
	//
	glBindTexture(GL_TEXTURE_2D, college.bigfootTexture);
	//
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, w, h, 0,
		GL_RGB, GL_UNSIGNED_BYTE, image[0].data);



    int addgrav = 1;
	//Update position
	marcos.pos[0] += marcos.vel[0];
	marcos.pos[1] += marcos.vel[1];
	//Check for collision with window edges
	if ((marcos.pos[0] < -140.0 && marcos.vel[0] < 0.0) ||
		(marcos.pos[0] >= (float)college.xres+140.0 &&
		marcos.vel[0] > 0.0))
	{
		marcos.vel[0] = -marcos.vel[0];
		addgrav = 0;
	}
	if ((marcos.pos[1] < 150.0 && marcos.vel[1] < 0.0) ||
		(marcos.pos[1] >= (float)college.yres && marcos.vel[1] > 0.0)) {
		marcos.vel[1] = -marcos.vel[1];
		addgrav = 0;
	}
	if (addgrav)
		marcos.vel[1] -= 0.75;

	//
	//
}






