//Ranbir Grewal


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
void rgrewal(int c){
    
    c = 0x00000000;
    ggprint8b(&r, 16, c, "David Mesa");
    ggprint8b(&r, 16,c, "Patrick Cruz");
    ggprint8b(&r, 16,c, "Aiesha Esa");
    ggprint8b(&r, 16,c, "Ranbir Grewal");

}
