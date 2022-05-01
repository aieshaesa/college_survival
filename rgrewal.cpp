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
Rgrewal rgrewal;
class College {
public:

	int done;
	int xres, yres;
	GLuint bigfootTexture;
    GLuint marcoTexture;
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


void Marcosmovement(){

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
	//Gravity?
	if (addgrav)
		marcos.vel[1] -= 0.75;
}



