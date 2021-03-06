/*
* Authors: Jared White, Caleb DeHaan, Eliza Sims, Matt Giles, and Patrick Brennan
* Assignment Title: Group Project (Pokemon GO)
* Assignment Description: This program is a game that increments
*                         score when catching pokemon with a pokeball
* Due Date: 12/5/2016
* Date Created: 11/14/2016
* Date Last Modified: 12/1/2016
 */


#ifndef POKEBALL_H_INCLUDED
#define POKEBALL_H_INCLUDED
#include "background.h"
#include "Pokemon.h"

class Pokeball
{
    private:
        Point oldLoc;
        int dimension1, dimension2;
        Point loc;
        int speed;
        int R, G, B;
        Color ball[20][20];
    public:
        vector <vector<Point> > background;
        Pokeball();
        void scopeBallBackground(vector <vector<Point> > scopeBallBackground);
        void draw(SDL_Plotter&);
        void erase(SDL_Plotter&);
        void move(int);
        void setLoc(Point);
        Point getLoc();
        void createSprite();
        void specialErase(SDL_Plotter&);
        void setDimension1(int);
        void setDimension2(int);
        int getDimension1();
        int getDimension2();
};

        /*
        Description: This function contructs the Pokeball
        Return:
        Precondition: Pokeball class created.
        Postcondition: Pokeball object constructed.
        */
Pokeball :: Pokeball()
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
    speed = 20;
}

        /*
        Description:
            This function creates the Pokeball sprite
            and reads in color and size from a file in an array.

        Return: void
        Precondition:  Correct file name.
        Postcondition: The array contains information for Pokeball.
        */
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


        /*
        Description:
            This function differentiates the Pokeball vector from the Background vector.
        Return: void
        Precondition: The vector with Point object exists exists.
        Postcondition: The vector is changed.
        */
void Pokeball::scopeBallBackground(vector <vector<Point> > scopeBallBackground)
{
    scopeBallBackground.resize(1000, vector <Point>(1000));
    background.resize(1000, vector <Point>(1000));
    background = scopeBallBackground;
}

        /*
        Description:
            This function draws the Pokeball sprite on the screen.
        Return: void
        Precondition: The sprite has been created.
        Postcondition: The sprite will be drawn to the screen.
        */
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
        /*
        Description:
            This function erases the Pokeball sprite on the screen.
        Return: void
        Precondition: The player has been drawn.
        Postcondition: The sprite will be erased from the screen.
        */
void Pokeball::erase(SDL_Plotter& g)
{
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
                g.plotPixel(oldLoc.x +x,oldLoc.y+y,background[oldLoc.x + x][oldLoc.y + y].R,background[oldLoc.x + x][oldLoc.y + y].G,background[oldLoc.x + x][oldLoc.y + y].B);
        }
     }
}
        /*
        Description:
            This function changes the direction of Pokeball
        Return: void
        Precondition:Pokeball object created and Pokeball contains coordinates.
        Postcondition: The direction of Pokeball is changed and speed is changed
        */
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
/*
        Description: This function erases Player
        Return:
        Precondition: Player object exits and SDL plotter in use.
        Postcondition: The colors plottered are covered in white
        */
void Pokeball::specialErase(SDL_Plotter& g)
{
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
                g.plotPixel(loc.x +x,loc.y+y,background[loc.x + x][loc.y + y].R,background[loc.x + x][loc.y + y].G,background[loc.x + x][loc.y + y].B);
        }
     }
     loc.x = 980;
     loc.y = 980;
}
 /*
        Description: This function sets location
        Return:
        Precondition: The Point object exists
        Postcondition: The x and y coordinates of Point object are changed
        */
void Pokeball::setLoc(Point p)
{
    loc.y = p.y;
    loc.x = p.x;
}

 /*
        Description: This function gets Location of Pokeball
        Return: Point
        Precondition: Point class exists and Loc exists
        Postcondition: Loc variable unchange
        */

Point Pokeball::getLoc(){
    return loc;
}

 /*
        Description: This function gets Dinension 1
        Return: int
        Precondition: The Dimension1 variable exists
        Postcondition: The Dimension1 variable is unchanged.
        */
int Pokeball::getDimension1(){
    return dimension1;
}

 /*
        Description: This function gets Dinension 2
        Return: int
        Precondition: The Dimension2 variable exists
        Postcondition: The Dimension2 variable is unchanged.
        */
int Pokeball::getDimension2(){
    return dimension2;
}

/*
 * description: sets dimension2
 * return: none
 * precondition: dimension2 needs to be changed
 * postcondition: dimension2 is changed
 *
*/
void Pokeball::setDimension2(int d)
{
    dimension2 = d;
    return;
}

/*
 * description: sets dimension1
 * return: none
 * precondition: dimension1 needs to be changed
 * postcondition: dimension1 is changed
 *
*/
void Pokeball::setDimension1(int d)
{
    dimension1 = d;
    return;
}


#endif // POKEBALL_H_INCLUDED
