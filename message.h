#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED
#include "SDL_Plotter.h"
#include "background.h"
#include <fstream>

class Message
{
    private:
        Point loc;
        Point oldLoc;
        int dimension1, dimension2, R, G, B;
        Color message[48][135];
    public:
        vector <vector<Point> > background;
        Message();
        void scopeMessageBackground(vector <vector<Point> > scopeMessageBackground);
        void draw(SDL_Plotter&);
        void erase(SDL_Plotter&);
        void setLoc(Point);
        void createSprite(string a);
};

        /*
        Description: This function contructs the Message
        Return:
        Precondition: Message class created.
        Postcondition: Message object constructed.
        */
Message :: Message()
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
}

        /*
        Description:
            This function creates the sprite and inputs its color info into the player array.
        Return: void
        Precondition: The string given is the correct file name.
        Postcondition: The array is changed.
        */
void Message:: createSprite(string a)
{
    ifstream messageFile;
    messageFile.open(a.c_str());
    dimension1 = 48;
    dimension2 = 135;
    for(int r = 0; r < dimension1; r++){
        for(int c = 0; c < dimension2; c++){
            messageFile >> message[r][c].R;
            messageFile >> message[r][c].G;
            messageFile >> message[r][c].B;
        }
    }
    messageFile.close();
}

        /*
        Description: This function sets vector for Message background
        Return:
        Precondition: Message object created, vector with background size
        Postcondition: Background position set with message
        */
void Message::scopeMessageBackground(vector <vector<Point> > scopeMessageBackground)
{
    scopeMessageBackground.resize(1000, vector <Point>(1000));
    background.resize(1000, vector <Point>(1000));
    background = scopeMessageBackground;
}

        /*
        Description: This function draws Message using color values
        Return:
        Precondition: Message object created, array with color values exists
        Postcondition: Plotter returned
        */
void Message::draw(SDL_Plotter& g)
{
    for(int y =0;y <dimension1;y++){
        for(int x=0; x<dimension2; x++){

            if(message[y][x].R == 255 && message[y][x].G == 255 && message[y][x].B == 255)
            {
                message[y][x].R = background[loc.x+x][loc.y+y].R;
                message[y][x].G = background[loc.x+x][loc.y+y].G;
                message[y][x].B = background[loc.x+x][loc.y+y].B;
            }

            g.plotPixel(loc.x+x,loc.y+y,message[y][x].R, message[y][x].G, message[y][x].B);
        }
    }
}

        /*
        Description: This function erases Message
        Return:
        Precondition: Message object exits and SDL plotter in use.
        Postcondition: The colors plotted are covered in white
        */
void Message::erase(SDL_Plotter& g)
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
                g.plotPixel(oldLoc.x +x,oldLoc.y+y,background[oldLoc.x + x][oldLoc.y + y].R,background[oldLoc.x + x][oldLoc.y + y].G,background[oldLoc.x + x][oldLoc.y + y].B);
        }
     }
}


        /*
        Description: This function sets location of Message point
        Return:
        Precondition: Point class exists and Loc exists
        Postcondition: Loc variable Point set to x and y coordinates
        */
void Message::setLoc(Point p)
{
    loc.y = p.y;
    loc.x = p.x;
}


#endif // MESSAGE_H_INCLUDED
