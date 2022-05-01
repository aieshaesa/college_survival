#ifndef _dmesa_h_
#define _dmesa_h_

//Author: David Mesa
//This is my header file to show case my contribtion to the project

// created a create class for credit screen 
class Credits
{
    public:
        void showPage(int xres,int yres,unsigned int texid,unsigned int texid2,
                         unsigned int texid3,unsigned int texid4,
                             int wd, int h);
};

class Texture
{
    public:
        void maketext(unsigned int texid, int width, int height,const void* img);
};

class Background
{
    public:
        void home(int xres, int yres,unsigned int texid5);
};

class Dmesa
{
    public:
       void dmesa(int a);
};

class Aiesha {
    public:
        bool aesa_midterm(int a);

};

class Pcruz
{
    public:
        bool pcruz_midterm(int num);
};


#endif

