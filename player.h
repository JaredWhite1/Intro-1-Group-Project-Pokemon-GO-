#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Pokemon.h"
#include "background.h"
#include "SDL_Plotter.h"

using namespace std;

class Player
{
    private:
        Point oldLoc;
        int speed;
        Point loc;
        int dimension1, dimension2;
    public:
    /*
        Description: This function contructs the Player
        Return:
        Precondition: Player class created.
        Postcondition: Player object constructed.
        */
        Player();
        /*
        Description: This creates a two dimensional vector
        Return:
        Precondition: Class Point and background object exist.
        Postcondition: Two dimensional vector created with corrdinates of Point object.
        */
        vector <vector<Point> > background;

         /*
        Description: This creates an array Player of Color class
        Return:
        Precondition: Color class exists
        Postcondition: The player array is created.
        */
        Color player[76][56];

        /*
        Description:
            This function differentiates the Player vector from the Background vector.
        Return: void
        Precondition: The vector exists.
        Postcondition: The vector is changed.
        */
        void scopePlayerBackground(vector <vector<Point> > scopePlayerBackground);


        /*
        Description:
            This function draws the Player sprite on the screen.
        Return: void
        Precondition: The sprite has been created.
        Postcondition: The sprite will be drawn to the screen.
        */
        void draw(SDL_Plotter&);


        /*
        Description:
            This function erases the Player sprite on the screen.
        Return: void
        Precondition: The player has been drawn.
        Postcondition: The sprite will be erased from the screen.
        */
        void erase(SDL_Plotter&);


        /*
        Description:
            This function is erase but with loc instead of oldLoc.
        Return: void
        Precondition: The player has been drawn.
        Postcondition: The sprite will be erased from the screen.
        */
        void specialErase(SDL_Plotter&);


        /*
        Description:
            This function draws the sprite at a new location and erases the old location.
        Return: void
        Precondition: The array has been filled.
        Postcondition: The sprite has been drawn and erased from the screen.
        */
        void move(DIR);


        /*
        Description: This function sets the loc variable.
        Return: void
        Precondition: The Point exists.
        Postcondition: The Point is changed.
        */
        void setLoc(Point);


        /*
        Description:
            This function creates the sprite and inputs its color info into the player array.
        Return: void
        Precondition: The string given is the correct file name.
        Postcondition: The array is changed.
        */
        void createSprite(string a);

        /*
            Description:
                This function sets the oldLoc variable.
            Return: void
            Precondition: oldLoc exists.
            Postcondition: oldLoc is changed.
        */
        void setOldLoc(Point);

        /*
        Description:
            This function sets the speed variable.
        Return: void
        Precondition: speed exists.
        Postcondition: speed is changed.
        */
        void setSpeed(int);


        /*
        Description:
            This function sets the dimension1 and dimension2.
        Precondition: Both dimensions exist.
        Postcondition: Both dimensions are changed.
        */
        void setDimensions(int, int);


        /*
        Description: This function gets the loc variable.
        Return: Point
        Precondition: The loc variable exists.
        Postcondition: The loc variable is unchanged.
        */
        Point getLoc();


        /*
        Description: This function gets the oldLoc variable.
        Return: Point
        Precondition: The oldLoc variable exists.
        Postcondition: The oldLoc variable is unchanged.
        */
        Point getOldLoc();


        /*
        Description: This function gets the speed variable.
        Return: int
        Precondition: The speed variable exists.
        Postcondition: The speed variable is unchanged.
        */
        int getSpeed();

        /*
        Description: This function gets the dimension1 variable.
        Return: int
        Precondition: The dimension1 variable exists.
        Postcondition: The dimension1 variable is unchanged.
        */
        int getDimension1();


        /*
        Description: This function gets the dimension2 variable.
        Return: int
        Precondition: The dimension2 variable exists.
        Postcondition: The dimension2 variable is unchanged.
        */
        int getDimension2();
};
 /*
        Description: This function constructs player object
        Return:
        Precondition: location exists
        Postcondition: Player set with location and speed 10.
        */
Player :: Player()
{
    setOldLoc(loc);
    speed = 10;
}
 /*
        Description: This function sets old location
        Return:
        Precondition: The Point object exists
        Postcondition: The x and y coordinates of Point object are changed
        */
void Player::setOldLoc(Point p){
    oldLoc.y = p.y;
    oldLoc.x = p.x;
}
 /*
        Description: This function sets the Player speed
        Return:
        Precondition: The speed variable exists
        Postcondition: The speed variable is changed.
        */
void Player::setSpeed(int spd){
    speed = spd;
}
 /*
        Description: This function sets the dimension x and y cordinates.
        Return: int
        Precondition: Player object exits, x and y coordinates exits
        Postcondition: The dimension2 variable is unchanged.
        */
void Player::setDimensions(int x, int y){
    dimension1 = x;
    dimension2 = y;
}
        /*
        Description:
            This function creates the sprite and inputs its color info into the player array.
        Return: void
        Precondition: The string given is the correct file name.
        Postcondition: The array is changed.
        */
void Player:: createSprite(string a)
{
    ifstream playerFile;
    playerFile.open(a.c_str());
    dimension1 = 76;
    dimension2 = 56;
    for(int r = 0; r < dimension1; r++){
        for(int c = 0; c < dimension2; c++){
            playerFile >> player[r][c].R;
            playerFile >> player[r][c].G;
            playerFile >> player[r][c].B;
        }
    }
    playerFile.close();
}


        /*
        Description: This function sets vector for Player background
        Return:
        Precondition: Player object created, vector with background size
        Postcondition: Plotter returned
        */
void Player::scopePlayerBackground(vector <vector<Point> > scopePlayerBackground)
{
    scopePlayerBackground.resize(1000, vector <Point>(1000));
    background.resize(1000, vector <Point>(1000));
    background = scopePlayerBackground;
}
        /*
        Description: This function plots Player using color values
        Return:
        Precondition: Player object created, file with color values exists
        Postcondition: Plotter returned
        */
void Player::draw(SDL_Plotter& g)
{
    erase(g);
    for(int y =0;y <dimension1;y++){
        for(int x=0; x<dimension2; x++){

            if(player[y][x].R == 255 && player[y][x].G == 255 && player[y][x].B == 255)
            {
                player[y][x].R = background[loc.x+x][loc.y+y].R;
                player[y][x].G = background[loc.x+x][loc.y+y].G;
                player[y][x].B = background[loc.x+x][loc.y+y].B;
            }

            g.plotPixel(loc.x+x,loc.y+y,player[y][x].R, player[y][x].G, player[y][x].B);
        }
    }
}
/*
        Description: This function erases Player
        Return:
        Precondition: Player object exits and SDL plotter in use.
        Postcondition: The colors plottered are covered in white
        */
void Player::erase(SDL_Plotter& g)
{
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
                g.plotPixel(oldLoc.x +x,oldLoc.y+y,background[oldLoc.x + x][oldLoc.y + y].R,background[oldLoc.x + x][oldLoc.y + y].G,background[oldLoc.x + x][oldLoc.y + y].B);
        }
     }
}
/*
        Description: This function erases Player
        Return:
        Precondition: Player object exits and SDL plotter in use.
        Postcondition: The colors plottered are covered in white
        */
void Player::specialErase(SDL_Plotter& g)
{
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
            g.plotPixel(loc.x +x,loc.y+y,background[loc.x + x][loc.y + y].R,background[loc.x + x][loc.y + y].G,background[loc.x + x][loc.y + y].B);
        }
    }
}

 /*
        Description: This function changes speed and direction
                    of the Pokemon location on screen.
        Return:
        Precondition: Player object exists, direction exists
        Postcondition: Coordinates of Point loc changed, and speed changed
        */

void Player::move(DIR d)
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
    switch(d){
        case UP:    loc.y-=speed;
                    if(loc.y<30)
                    {
                        loc.y+=speed;
                    }
                    break;
        case DOWN:  loc.y+=speed;
                    if(loc.y>820)
                    {
                        loc.y-=speed;
                    }
                    break;
        case LEFT:  loc.x-=speed;
                    if(loc.x<40)
                    {
                        loc.x+=speed;
                    }
                    break;
        case RIGHT: loc.x+=speed;
                    if(loc.x>919)
                    {
                        loc.x-=speed;
                    }
                    break;
    }
}

 /*
        Description: This function sets location of Player
        Return: Point
        Precondition: Point class exists and Loc exists
        Postcondition: Loc variable Point set to x and y coordinates
        */

void Player::setLoc(Point p)
{
    loc.y = p.y;
    loc.x = p.x;
}
 /*
        Description: This function gets Location of Player
        Return: Point
        Precondition: Point class exists and Loc exists
        Postcondition: Loc variable unchange
        */

Point Player::getLoc(){
    return loc;
}

 /*
        Description: This function gets Old Location of Player
        Return: Point
        Precondition: Point class exists and OldLoc exists
        Postcondition: old Loc variable unchange
        */
Point Player::getOldLoc(){
    return oldLoc;
}
 /*
        Description: This function gets Dimension 2
        Return: int
        Precondition: The Dimension2 variable exists
        Postcondition: The Dimension2 variable is unchanged.
        */
int Player::getSpeed(){
    return speed;
}
 /*
        Description: This function gets Dinension 1
        Return: int
        Precondition: The Dimension1 variable exists
        Postcondition: The Dimension1 variable is unchanged.
        */
int Player::getDimension1(){
    return dimension1;
}

 /*
        Description: This function gets Dinension 2
        Return: int
        Precondition: The Dimension2 variable exists
        Postcondition: The Dimension2 variable is unchanged.
        */
int Player::getDimension2(){
    return dimension2;
}




#endif // PLAYER_H_INCLUDED

