#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include "SDL_Plotter.h"
#include <algorithm>
#include <vector>

struct Point {
    double x,y;
    int R,G,B;
    Point(int x =0, int y =0);
};

struct Color{
    int R, G, B;
    Color(){
        R = G = B = 255;
    }
};

Point :: Point(int a, int b)
{
   x= a;
   y=b;
}

class Background
{
    private:

    public:
        vector <vector<Point> > objectBackground;
        void drawBackground(SDL_Plotter& g);
        void setBackground(string a);
};

void Background::setBackground(string a)
{
    objectBackground.resize(1000, vector <Point>(1000));
    ifstream backgroundImage;
    backgroundImage.open(a.c_str());

    for(int i = 0; i < 1000; i++)
    {
        for(int f = 0; f < 1000; f++)
        {
            backgroundImage >> objectBackground[i][f].R >> objectBackground[i][f].G >> objectBackground[i][f].B;
            objectBackground[i][f].x = i;
            objectBackground[i][f].y = f;
        }
    }
    backgroundImage.close();
}

void Background::drawBackground(SDL_Plotter& g)
{
    for(int h = 0; h < 1000; h++)
    {
        for(int j = 0; j < 1000; j++)
        {
            g.plotPixel(objectBackground[j][h].y,objectBackground[j][h].x,objectBackground[h][j].R,objectBackground[h][j].G,objectBackground[h][j].B);
        }
    }
}



#endif // BACKGROUND_H_INCLUDED
