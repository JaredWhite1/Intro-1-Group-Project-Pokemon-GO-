#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include "SDL_Plotter.h"
#include "background.h"
#include <fstream>

enum DIR{UP,DOWN,LEFT,RIGHT};



class Pokemon{
    private:
        Point oldLoc;
        int speed;
        int R, G, B;
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

Pokemon:: Pokemon()
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
    speed = 5;
}

Pokemon:: ~Pokemon()
{

}

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

 void Pokemon:: erase(SDL_Plotter& g){
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
            g.plotPixel(oldLoc.x +x,oldLoc.y+y,background[oldLoc.x + x][oldLoc.y + y].R,background[oldLoc.x + x][oldLoc.y + y].G,background[oldLoc.x + x][oldLoc.y + y].B);
        }
    }
}

void Pokemon:: setLoc(Point p){
    loc.y = p.y;
    loc.x = p.x;
}

void Pokemon::scopeBackground(vector <vector<Point> > scopeBackground)
{
    scopeBackground.resize(1000, vector <Point>(1000));
    background.resize(1000, vector <Point>(1000));
    background = scopeBackground;
}

void Pokemon::specialErase(SDL_Plotter& g)
{
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
            g.plotPixel(loc.x +x,loc.y+y,background[loc.x + x][loc.y + y].R,background[loc.x + x][loc.y + y].G,background[loc.x + x][loc.y + y].B);
        }
    }
}


#endif // POKEMON_H_INCLUDED
