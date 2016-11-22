#ifndef MESSAGE2_H_INCLUDED
#define MESSAGE2_H_INCLUDED

#include "SDL_Plotter.h"
#include "background.h"
#include <fstream>

class Message2
{
    private:
        Point loc;
        Point oldLoc;
        int dimension1, dimension2, R, G, B;
        Color message2[48][135];
    public:
        vector <vector<Point> > background;
        Message2();
        void scopeMessage2Background(vector <vector<Point> > scopeMessage2Background);
        void draw(SDL_Plotter&);
        void erase(SDL_Plotter&);
        void setLoc(Point);
        void createSprite(string a);
};

Message2 :: Message2()
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
}

void Message2:: createSprite(string a)
{
    ifstream messageFile2;
    messageFile2.open(a.c_str());
    dimension1 = 48;
    dimension2 = 135;
    for(int r = 0; r < dimension1; r++){
        for(int c = 0; c < dimension2; c++){
            messageFile2 >> message2[r][c].R;
            messageFile2 >> message2[r][c].G;
            messageFile2 >> message2[r][c].B;
        }
    }
    messageFile2.close();
}


void Message2::scopeMessage2Background(vector <vector<Point> > scopeMessage2Background
                                       )
{
    scopeMessage2Background.resize(1000, vector <Point>(1000));
    background.resize(1000, vector <Point>(1000));
    background = scopeMessage2Background;
}

void Message2::draw(SDL_Plotter& g)
{
    for(int y =0;y <dimension1;y++){
        for(int x=0; x<dimension2; x++){

            if(message2[y][x].R == 255 && message2[y][x].G == 255 && message2[y][x].B == 255)
            {
                message2[y][x].R = background[loc.x+x][loc.y+y].R;
                message2[y][x].G = background[loc.x+x][loc.y+y].G;
                message2[y][x].B = background[loc.x+x][loc.y+y].B;
            }

            g.plotPixel(loc.x+x,loc.y+y,message2[y][x].R, message2[y][x].G, message2[y][x].B);
        }
    }
}

void Message2::erase(SDL_Plotter& g)
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
                g.plotPixel(oldLoc.x +x,oldLoc.y+y,background[oldLoc.x + x][oldLoc.y + y].R,background[oldLoc.x + x][oldLoc.y + y].G,background[oldLoc.x + x][oldLoc.y + y].B);
        }
     }
}

void Message2::setLoc(Point p)
{
    loc.y = p.y;
    loc.x = p.x;
}

#endif // MESSAGE1_H_INCLUDED
