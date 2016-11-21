#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

#include <ostream>
#include <fstream>
#include "SDL_plotter.h"

enum DIR {UP, DOWN, LEFT, RIGHT};

struct Point
{
    int x,y;
    Point(int x=0,int y=0);
};

class Pokemon
{
    private:
        Point loc;
        Point oldLoc;
        int speed;
        int R,G,B;

    public:
        Pokemon();
        void draw(SDL_Plotter&,string);
        void erase(SDL_Plotter&,int,int);
        void move(DIR);
        void setLoc(Point);
};

Point::Point(int a, int b)
{
    x = a;
    y = b;
}

Pokemon::Pokemon()
{
    oldLoc = loc;
    speed = 5;
}

void Pokemon::draw(SDL_Plotter& g,string fileName)
{
    ifstream myFile;
    int dimension1,dimension2;
    myFile.open(fileName.c_str());
    myFile >> dimension1 >> dimension2;
    erase(g,dimension1,dimension2);
    for(int x =0;x <dimension1;x++)
    {
        for(int y=0; y<dimension2; y++)
        {
            myFile >> R >> G >> B;
            g.plotPixel(loc.x+x,loc.y+y,R,G,B);
        }
    }
    g.Sleep(100);
}

void Pokemon:: erase(SDL_Plotter& g,int dimension1,int dimension2)
{
    for(int x= 0;x<dimension1;x++)
    {
        for(int y =0;y<dimension2;y++)
        {
            g.plotPixel(oldLoc.x +x,oldLoc.y+y,255,255,255);
        }
    }
}

void Pokemon::move(DIR d)
{
    oldLoc = loc;
    switch(d)
    {
        case UP:    loc.y-=speed;
                    if(loc.y<=0)
                    {
                        loc.y+=speed;
                    }
                    break;
        case DOWN:  loc.y+=speed;
                    if(loc.y>=1000)
                    {
                        loc.y-=speed;
                    }
                    break;
        case LEFT:  loc.x-=speed;
                    if(loc.x<=0)
                    {
                        loc.x+=speed;
                    }
                    break;
        case RIGHT: loc.x+=speed;
                    if(loc.x>=1000)
                    {
                        loc.x-=speed;
                    }
                    break;
    }
}

void Pokemon::setLoc(Point p)
{
    loc = p;
}

#endif // POKEMON_H_INCLUDED
