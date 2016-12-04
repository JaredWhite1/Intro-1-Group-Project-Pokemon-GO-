#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include "SDL_Plotter.h"
#include <algorithm>
#include <vector>
#include <fstream>


struct Point {
    int x,y;
    int R,G,B;
    Point(int a = 0, int b = 0);
};

struct Color{
    int R, G, B;
    Color(){
        R = G = B = 255;
    }
};

        /*
        Description: This function contructs the Point
        Return:
        Precondition: X and Y coordinats exist exist.
        Postcondition: Point object constructed
        */
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

        /*
        Description: This function sets vector background size and colors
        Return:void
        Precondition: File with correct data exists.
        Postcondition: Background vector set with color and size.
        */
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

 /*
        Description: This function uses Plotter to draw background
        Return:void
        Precondition: G object and SDL plotter exist
        Postcondition:G object background array modified with colors.
        */
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
