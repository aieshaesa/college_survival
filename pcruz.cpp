//Patrick Cruz
//
//My Contributions to the project
//

//This calls the credits page.
#include <stdio.h>
#include <iostream>
#include "dmesa.h"

//using namespace std;
//Bullet function
void Bullet :: moveBullet(int nbullets) {
    
struct timespec bt;
	clock_gettime(CLOCK_REALTIME, &bt);
	int i = 0;
	while (i < g.nbullets) {
		Bullet *b = &g.barr[i];
		//How long has bullet been alive?
		double ts = timeDiff(&b->time, &bt);
		if (ts > 2.5) {
			//time to delete the bullet.
			memcpy(&g.barr[i], &g.barr[g.nbullets-1],
				sizeof(Bullet));
			g.nbullets--;
			//do not increment i.
			continue;
		}
		//move the bullet
		b->pos[0] += b->vel[0];
		b->pos[1] += b->vel[1];
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



