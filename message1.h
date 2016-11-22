#ifndef MESSAGE1_H_INCLUDED
#define MESSAGE1_H_INCLUDED

#include "SDL_Plotter.h"
#include "background.h"
#include <fstream>

class Message1
{
    private:
        Point loc;
        Point oldLoc;
        int dimension1, dimension2, R, G, B;
        Color message1[48][135];
    public:
        vector <vector<Point> > background;
        Message1();
        void scopeMessage1Background(vector <vector<Point> > scopeMessage1Background);
        void draw(SDL_Plotter&);
        void erase(SDL_Plotter&);
        void setLoc(Point);
        void createSprite(string a);
};

Message1 :: Message1()
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
}

void Message1:: createSprite(string a)
{
    ifstream messageFile1;
    messageFile1.open(a.c_str());
    dimension1 = 48;
    dimension2 = 135;
    for(int r = 0; r < dimension1; r++){
        for(int c = 0; c < dimension2; c++){
            messageFile1 >> message1[r][c].R;
            messageFile1 >> message1[r][c].G;
            messageFile1 >> message1[r][c].B;
        }
    }
    messageFile1.close();
}


void Message1::scopeMessage1Background(vector <vector<Point> > scopeMessage1Background)
{
    scopeMessage1Background.resize(1000, vector <Point>(1000));
    background.resize(1000, vector <Point>(1000));
    background = scopeMessage1Background;
}

void Message1::draw(SDL_Plotter& g)
{
    for(int y =0;y <dimension1;y++){
        for(int x=0; x<dimension2; x++){

            if(message1[y][x].R == 255 && message1[y][x].G == 255 && message1[y][x].B == 255)
            {
                message1[y][x].R = background[loc.x+x][loc.y+y].R;
                message1[y][x].G = background[loc.x+x][loc.y+y].G;
                message1[y][x].B = background[loc.x+x][loc.y+y].B;
            }

            g.plotPixel(loc.x+x,loc.y+y,message1[y][x].R, message1[y][x].G, message1[y][x].B);
        }
    }
}

void Message1::erase(SDL_Plotter& g)
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
                g.plotPixel(oldLoc.x +x,oldLoc.y+y,background[oldLoc.x + x][oldLoc.y + y].R,background[oldLoc.x + x][oldLoc.y + y].G,background[oldLoc.x + x][oldLoc.y + y].B);
        }
     }
}

void Message1::setLoc(Point p)
{
    loc.y = p.y;
    loc.x = p.x;
}

#endif // MESSAGE1_H_INCLUDED
