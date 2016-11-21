#ifndef POKEBALL_H_INCLUDED
#define POKEBALL_H_INCLUDED
#include "background.h"
#include "Pokemon.h"

class Pokeball
{
    private:
        Point oldLoc;
        double speed;
        int R, G, B;
        Color ball[20][20];
    public:
        int dimension1, dimension2;
        Point loc;
        vector <vector<Point> > background;
        Pokeball();
        void scopeBallBackground(vector <vector<Point> > scopeBallBackground);
        void draw(SDL_Plotter&);
        void erase(SDL_Plotter&);
        void move(int);
        void setLoc(Point);
        void createSprite();
};

Pokeball :: Pokeball()
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
    speed = 5;
}

void Pokeball:: createSprite()
{
    ifstream ballFile;
    ballFile.open("pokeball.txt");
    ballFile >> dimension1;
    ballFile >> dimension2;
    for(int r = 0; r < dimension1; r++){
        for(int c = 0; c < dimension2; c++){
            ballFile >> ball[r][c].R;
            ballFile >> ball[r][c].G;
            ballFile >> ball[r][c].B;
        }
    }
    ballFile.close();
}


void Pokeball::scopeBallBackground(vector <vector<Point> > scopeBallBackground)
{
    scopeBallBackground.resize(1000, vector <Point>(1000));
    background.resize(1000, vector <Point>(1000));
    background = scopeBallBackground;
}

void Pokeball::draw(SDL_Plotter& g)
{
    erase(g);
    for(int y =0;y <dimension1;y++){
        for(int x=0; x<dimension2; x++){

            if(ball[y][x].R == 255 && ball[y][x].G == 255 && ball[y][x].B == 255)
            {
                ball[y][x].R = background[loc.x+x][loc.y+y].R;
                ball[y][x].G = background[loc.x+x][loc.y+y].G;
                ball[y][x].B = background[loc.x+x][loc.y+y].B;
            }

            g.plotPixel(loc.x+x,loc.y+y,ball[y][x].R, ball[y][x].G, ball[y][x].B);
        }
    }
}

void Pokeball::erase(SDL_Plotter& g)
{
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
                g.plotPixel(oldLoc.x +x,oldLoc.y+y,background[oldLoc.x + x][oldLoc.y + y].R,background[oldLoc.x + x][oldLoc.y + y].G,background[oldLoc.x + x][oldLoc.y + y].B);
        }
     }
}

void Pokeball::move(int d)
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
    switch(d){
    case 0: loc.y-=speed;
            break;
    case 1: loc.y+=speed;
            break;
    case 2: loc.x-=speed;
            break;
    case 3: loc.x+=speed;
            break;
    }
}

void Pokeball::setLoc(Point p)
{
    loc.y = p.y;
    loc.x = p.x;
}

bool ballCollide(Pokeball a, Pokemon b)
{
    bool collide;
    bool stop = false;

    int g = 0;
    int h = 0;

    for(int i = 0; i < b.dimension1; i++)
    {
        for(int f = 0; f < b.dimension2; f++)
        {
            if(b.loc.x + i == a.loc.x + g && b.loc.y + f == a.loc.y + h)
            {
                collide = true;
                stop = true;
                break;
            }
            else
            {
                collide = false;
            }

            if(g <= 20)
            {
                g++;
            }
        }
        if(stop == true)
        {
            break;
        }

        if(h <= 20)
        {
            h++;
        }
    }
    return collide;
}

#endif // POKEBALL_H_INCLUDED
