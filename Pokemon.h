#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include "SDL_Plotter.h"
#include "background.h"
#include <fstream>

enum DIR{UP,DOWN,LEFT,RIGHT};

class Pokemon{
    private:
        Point oldLoc;
        Point loc;
        bool deleted;
        string pokemonName;
        int dimension1, dimension2;
    public:
        Color pic[80][80];
        vector <vector<Point> > background;
        Pokemon();
        ~Pokemon();
        void createSprite(string pokemonName);
        void draw(SDL_Plotter&);
        void erase(SDL_Plotter&);
        void move();
        void setLoc(Point);
        void openFile(string pokemonName);
        void scopeBackground(vector <vector<Point> > scopeBackground);
        void specialErase(SDL_Plotter&);

        void setOldLoc(Point p);
        void setLoc(Point p);
        void setDeleted(bool d);
        void setPokemonName(string name);
        void setDimension1(int d);
        void setDimension2(int d);

        Point getOldLoc();
        Point getLoc();
        bool getDeleted();
        string getPokemonName();
        int getDimension1();
        int getDimension2();
};

/*
 * description: returns dimension2
 * return: int
 * precondition: dimension2 needs to be found
 * postcondition: dimension2 is returned
 *
*/
int Pokemon::getDimension2()
{
    return dimension2;
}

/*
 * description: returns dimension1
 * return: int
 * precondition: dimension1 needs to be found
 * postcondition: dimension1 is returned
 *
*/
int Pokemon::getDimension1()
{
    return dimension1;
}

/*
 * description: returns pokemonName
 * return: string
 * precondition: pokemonName needs to be found
 * postcondition: pokemonName is returned
 *
*/
string Pokemon::getPokemonName()
{
    return pokemonName;
}

/*
 * description: returns deleted
 * return: boolean
 * precondition: deleted needs to be found
 * postcondition: deleted is returned
 *
*/
bool Pokemon::getDeleted()
{
    return deleted;
}

/*
 * description: returns location
 * return: Point
 * precondition: location needs to be found
 * postcondition: location is returned
 *
*/
Point Pokemon::getLoc()
{
    return loc;
}

/*
 * description: returns old location
 * return: Point
 * precondition: old location needs to be found
 * postcondition: old location is returned
 *
*/
Point Pokemon::getOldLoc()
{
    return oldLoc;
}

/*
 * description: sets dimension2
 * return: none
 * precondition: dimension2 needs to be changed
 * postcondition: dimension2 is changed
 *
*/
void Pokemon::setDimension2(int d)
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
void Pokemon::setDimension1(int d)
{
    dimension1 = d;
    return;
}

/*
 * description: sets pokemonName
 * return: none
 * precondition: pokemonName needs to be changed
 * postcondition: pokemonName is changed
 *
*/
void Pokemon::setPokemonName(string name)
{
    pokemonName = name;
    return;
}

/*
 * description: sets deleted
 * return: none
 * precondition: deleted needs to be changed
 * postcondition: deleted is changed
 *
*/
void Pokemon::setDeleted(bool d)
{
    deleted = d;
    return;
}

/*
 * description: sets old location
 * return: none
 * precondition: old location needs to be changed
 * postcondition: old location is changed
 *
*/
void Pokemon::setOldLoc(Point p)
{
    oldLoc.x = p.x;
    oldLoc.y = p.y;
    return;
}

/*
 * description: default constructor
 * return: none
 * precondition:  a pokemon needs to be created
 * postcondition: a pokemon is created
 *
*/
Pokemon:: Pokemon()
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
    deleted = false;
}

/*
 * description: deconstructor
 * return: none
 * precondition: a pokemon needs to be deconstructed
 * postcondition: a pokemon is deconstructed
 *
*/
Pokemon:: ~Pokemon()
{

}

/*
 * description: creates a sprite of a certain pokemon
 * return: none
 * precondition: a sprite needs to be created
 * postcondition: a sprite is created
 *
*/
void Pokemon:: createSprite(string pokemonName)
{
    ifstream pokemonFile;
    pokemonFile.open(pokemonName.c_str());
    pokemonFile >> dimension1 >> dimension2;
    for(int r = 0; r < dimension1; r++){
        for(int c = 0; c < dimension2; c++){
            pokemonFile >> pic[r][c].R;
            pokemonFile >> pic[r][c].G;
            pokemonFile >> pic[r][c].B;
        }
    }
    pokemonFile.close();
    return;
}

/*
 * description: draws a pokemon
 * return: none
 * precondition: dimension2 needs to be changed
 * postcondition: dimension2 is changed
 *
*/
void Pokemon:: draw(SDL_Plotter& g)
{
    erase(g);
    for(int y =0;y <dimension1;y++){
        for(int x=0; x<dimension2; x++){

            if(pic[y][x].R == 255 && pic[y][x].G == 255 && pic[y][x].B == 255)
            {
                pic[y][x].R = background[loc.x+x][loc.y+y].R;
                pic[y][x].G = background[loc.x+x][loc.y+y].G;
                pic[y][x].B = background[loc.x+x][loc.y+y].B;
            }

            g.plotPixel(loc.x+x,loc.y+y,pic[y][x].R, pic[y][x].G, pic[y][x].B);
        }
    }
    return;
}

/*
 * description: erases a pokemon
 * return: none
 * precondition: a pokemon needs to be erased
 * postcondition: a pokemon is erased
 *
*/
 void Pokemon::erase(SDL_Plotter& g){
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
            g.plotPixel(oldLoc.x +x,oldLoc.y+y,background[oldLoc.x + x][oldLoc.y + y].R,background[oldLoc.x + x][oldLoc.y + y].G,background[oldLoc.x + x][oldLoc.y + y].B);
        }
    }
    return;
}

/*
 * description: sets location
 * return: none
 * precondition: location needs to be changed
 * postcondition: location is changed
 *
*/
void Pokemon::setLoc(Point p){
    loc.y = p.y;
    loc.x = p.x;
    return;
}

/*
 * description: sets the boundries of the background
 * return: none
 * precondition: boundries of the background need to be set
 * postcondition: boudries of the background are set
 *
*/
void Pokemon::scopeBackground(vector <vector<Point> > scopeBackground)
{
    scopeBackground.resize(1000, vector <Point>(1000));
    background.resize(1000, vector <Point>(1000));
    background = scopeBackground;
    return;
}

/*
 * description: different erase for catch animation
 * return: none
 * precondition: pokemon is caught
 * postcondition: pokemon is gone after being caught
 *
*/
void Pokemon::specialErase(SDL_Plotter& g)
{
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
            g.plotPixel(loc.x +x,loc.y+y,background[loc.x + x][loc.y + y].R,background[loc.x + x][loc.y + y].G,background[loc.x + x][loc.y + y].B);
        }
    }
    return;
}


#endif // POKEMON_H_INCLUDED
