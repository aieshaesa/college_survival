//Patrick Cruz
//
//My Contributions to the project
//

//This calls the credits page.
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include "dmesa.h"
#include <time.h>
#include <GL/glx.h>
#include <math.h>
#include <cstring>

extern double timeDiff(struct timespec *start, struct timespec *end);
Bullets Bullet;
//using namespace std;
//Bullet function
Bullets *barr;

//barr = new Bullet[11];


void Bullets :: moveBullet(int nbullets, float Vec) {
    
struct timespec bt;
	clock_gettime(CLOCK_REALTIME, &bt);
	int i = 0;
    //Vec pos;
    //Vec vel;
    //int *b;
    while (i < nbullets) {
		//Bullet *b = &barr[i];
		//How long has bullet been alive?
		double ts = timeDiff(CLOCK_REALTIME,&bt);
		if (ts > 2.5) {
			//time to delete the bullet.
			memcpy(&barr[i], &barr[nbullets-1],
				sizeof(Bullet));
			nbullets--;
			//do not increment i.
			continue;
		}
		//move the bullet
		//vec.pos[0] += vec.vel[0];
		//vec.pos[1] += vec.vel[1];
    }
}
//Midterm: thursday revisions
//Test that the value falls within a range.
Pcruz pcruz_midterm;

bool Pcruz::pcruz_midterm(int num)
{
    if (0 <= num && num <= 50)
    {
        return true;
    }
    else
    {
        return false;
    }

}



