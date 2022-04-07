//Ranbir Grewal
// I am in charge of the controls of this game
#include <iostream>
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
Rect r;
void rgrewal(){
    
    unsigned int c = 0x00000000;
    ggprint8b(&r, 16, c, "David Mesa");
    ggprint8b(&r, 16,c, "Patrick Cruz");
    ggprint8b(&r, 16,c, "Aiesha Esa");
    ggprint8b(&r, 16,c, "Ranbir Grewal");

}

