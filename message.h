#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED
#include "background.h"

class Message
{
    private:
        Point loc;
        Point oldLoc;
        int dimension1, dimension2, R, G, B;
        Color message[70][190];
    public:
        vector <vector<Point> > background;
        Message();
        void scopeMessageBackground(vector <vector<Point> > scopePlayerBackground);
        void draw(SDL_Plotter&);
        void erase(SDL_Plotter&);
        void setLoc(Point);
        void createSprite(string a);
};

Message :: Message()
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
}

void Message:: createSprite(string a)
{
    ifstream messageFile;
    messageFile.open("message.txt");
    messageFile >> dimension1;
    messageFile >> dimension2;
    for(int r = 0; r < dimension1; r++){
        for(int c = 0; c < dimension2; c++){
            messageFile >> message[r][c].R;
            messageFile >> message[r][c].G;
            messageFile >> message[r][c].B;
        }
    }
    messageFile.close();
}


void Message::scopeMessageBackground(vector <vector<Point> > scopeMessageBackground)
{
    scopeMessageBackground.resize(1000, vector <Point>(1000));
    background.resize(1000, vector <Point>(1000));
    background = scopeMessageBackground;
}

void Message::draw(SDL_Plotter& g)
{
    for(int y =0;y <dimension1;y++){
        for(int x=0; x<dimension2; x++)
        {

            if((message[y][x].R == 255 && message[y][x].G == 255 && message[y][x].B == 255)
            || (message[y][x].R == 200 && message[y][x].G == 200 && message[y][x].B == 200)
            || (message[y][x].R == 234 && message[y][x].G == 234 && message[y][x].B == 234)
            || (message[y][x].R == 212 && message[y][x].G == 212 && message[y][x].B == 212)
            || (message[y][x].R == 223 && message[y][x].G == 223 && message[y][x].B == 223)
            || (message[y][x].R == 245 && message[y][x].G == 245 && message[y][x].B == 245))
            {
                message[y][x].R = background[loc.x+x][loc.y+y].R;
                message[y][x].G = background[loc.x+x][loc.y+y].G;
                message[y][x].B = background[loc.x+x][loc.y+y].B;
            }
            loc.x+=x;
            loc.y+=y;
            oldLoc.x = loc.x;
            oldLoc.y = loc.y;
            g.plotPixel(loc.x,loc.y,message[y][x].R, message[y][x].G, message[y][x].B);
            loc.x-=x;
            loc.y-=y;
        }
    }
    erase(g);
}

void Message::erase(SDL_Plotter& g)
{
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
                g.plotPixel(oldLoc.x +x,oldLoc.y+y,background[oldLoc.x + x][oldLoc.y + y].R,background[oldLoc.x + x][oldLoc.y + y].G,background[oldLoc.x + x][oldLoc.y + y].B);
        }
     }
}

void Message::setLoc(Point p)
{
    loc.y = p.y;
    loc.x = p.x;
}


#endif // MESSAGE_H_INCLUDED
