#include "background.h"

class Player
{
    private:
        Point oldLoc;
        int speed;
        Point loc;
        int dimension1, dimension2;
    public:
        Player();
        vector <vector<Point> > background;
        Color player[76][56];
        void scopePlayerBackground(vector <vector<Point> > scopePlayerBackground);
        void draw(SDL_Plotter&);
        void erase(SDL_Plotter&);
        void specialErase(SDL_Plotter&);
        void move(DIR);
        void setLoc(Point);
        void createSprite(string a);
};

Player :: Player();

/*
Description:
    This function sets the oldLoc variable.
Return: void
Precondition: oldLoc exists.
Postcondition: oldLoc is changed.
*/
void player::setOldLoc(Point);

/*
Description: 
    This function sets the speed variable.
Return: void
Precondition: speed exists.
Postcondition: speed is changed.
*/
void player::setSpeed(int);

/*
Description: 
    This function sets the dimension1 and dimension2.
Return: void
Precondition: Both dimensions exist.
Postcondition: Both dimensions are changed.
*/
void player::setDimensions(int, int);

/*
Description:
    This function creates the sprite and inputs its color info into the player array.
Return: void
Precondition: The string given is the correct file name.
Postcondition: The array is changed.
*/
void Player:: createSprite(string a);

/*
Description: 
   This function differentiates the Player vector from the Background vector.
Return: void
Precondition: The vector exists.
Postcondition: The vector is changed.
*/
void Player::scopePlayerBackground(vector <vector<Point> > scopePlayerBackground);

/*
Description: 
    This function draws the Player sprite on the screen.
Return: void
Precondition: The sprite has been created.
Postcondition: The sprite will be drawn to the screen.
*/
void Player::draw(SDL_Plotter& g);

/*
Description: 
    This function erases the Player sprite on the screen.
Return: void
Precondition: The player has been drawn.
Postcondition: The sprite will be erased from the screen.
*/
void Player::erase(SDL_Plotter& g);

/*
Description: 
    This function is erase but with loc instead of oldLoc.
Return: void
Precondition: The player has been drawn.
Postcondition: The sprite will be erased from the screen.
*/
void Player::specialErase(SDL_Plotter& g);

/*
Description: 
    This function draws the sprite at a new location and erases the old location.  
Return: void
Precondition: The array has been filled.
Postcondition: The sprite has been drawn and erased from the screen.
*/
void Player::move(DIR d);

/*
Description: This function sets the loc variable.
Return: void
Precondition: The Point exists.
Postcondition: The Point is changed.
*/
void Player::setLoc(Point p);

/*
Description: This function gets the loc variable.
Return: Point
Precondition: The loc variable exists.
Postcondition: The loc variable is unchanged.
*/
Point Player::getLoc();

/*
Description: This function gets the oldLoc variable.
Return: Point
Precondition: The oldLoc variable exists.
Postcondition: The oldLoc variable is unchanged.
*/
Point Player::getOldLoc();

/*
Description: This function gets the speed variable.
Return: int
Precondition: The speed variable exists.
Postcondition: The speed variable is unchanged.
*/
int Player::getSpeed();

/*
Description: This function gets the dimension1 variable.
Return: int
Precondition: The dimension1 variable exists.
Postcondition: The dimension1 variable is unchanged.
*/
int Player::getDimension1();

/*
Description: This function gets the dimension2 variable.
Return: int
Precondition: The dimension2 variable exists.
Postcondition: The dimension2 variable is unchanged.
*/
int Player::getDimension2();
