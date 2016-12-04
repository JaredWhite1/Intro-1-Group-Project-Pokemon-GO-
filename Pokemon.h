#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include "SDL_Plotter.h"
#include "background.h"
#include <fstream>

enum DIR{UP,DOWN,LEFT,RIGHT};

class Pokemon{
    private:
        Point oldLoc;
    public:
        bool deleted = false;
        Color pic[80][80];
        int dimension1, dimension2;
        Point loc;
        vector <vector<Point> > background;
        string pokemonName;
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
};
 /*
        Description: This function contructs the Pokemon
        Return:
        Precondition: Location and Pokemon object exist.
        Postcondition: Pokemon object constructed
        */
Pokemon:: Pokemon()
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
}

 /*
        Description: This function destructs Pokemon object
        Return:
        Precondition: Pokemon constructed
        Postcondition:Object destroyed
        */
Pokemon:: ~Pokemon()
{

}

 /*
        Description: This function creates Pokemon image
        Return:
        Precondition: Pokemon class exits, file contains binary for
        image of a Pokemon
        Postcondition: dimensions and colors read into array
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
}

        /*
        Description: This function plots using ink
        Return:
        Precondition: Pokemon object created, SDL Plotter exits
        Postcondition: Plotter returned
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

}

 /*
        Description: This function erases pokemon
        Return:
        Precondition: Pokemon object exits and SDL plotter in uses
        Postcondition: The colors plottered are covered in white
        */

 void Pokemon:: erase(SDL_Plotter& g){
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
            g.plotPixel(oldLoc.x +x,oldLoc.y+y,background[oldLoc.x + x][oldLoc.y + y].R,background[oldLoc.x + x][oldLoc.y + y].G,background[oldLoc.x + x][oldLoc.y + y].B);
        }
    }
}

 /*
        Description: This function sets location
        Return:
        Precondition: Pokemon object and point object exist.
        Postcondition: The coordinates of point are changed
        */
void Pokemon:: setLoc(Point p){
    loc.y = p.y;
    loc.x = p.x;
}

 /*
        Description: This function sets the size of vector Background
        Return:
        Precondition: background Vector exists
        Postcondition: Background size set by size of vector.
        */

void Pokemon::scopeBackground(vector <vector<Point> > scopeBackground)
{
    scopeBackground.resize(1000, vector <Point>(1000));
    background.resize(1000, vector <Point>(1000));
    background = scopeBackground;
}
 /*
        Description: This function erases background
        Return:
        Precondition: Location of Pokemon exists and location of background
        Postcondition: Background color changed to Pokemon color
        */
void Pokemon::specialErase(SDL_Plotter& g)
{
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
            g.plotPixel(loc.x +x,loc.y+y,background[loc.x + x][loc.y + y].R,background[loc.x + x][loc.y + y].G,background[loc.x + x][loc.y + y].B);
        }
    }
}


#endif // POKEMON_H_INCLUDED
