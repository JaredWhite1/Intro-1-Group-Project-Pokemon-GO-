#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include "SDL_Plotter.h"
#include "background.h"
#include <fstream>

enum DIR{UP,DOWN,LEFT,RIGHT};

class Pokemon{
    private:
        Point loc;
        Point oldLoc;
        int speed;
        int dimension1, dimension2, R, G, B;
    public:
        vector <vector<Point> > background;
        string pokemonName;
        Pokemon();
        void draw(SDL_Plotter&, string pokemonName);
        void erase(SDL_Plotter&);
        void move(DIR);
        void setLoc(Point);
        void openFile(string pokemonName);
        void scopeBackground(vector <vector<Point> > scopeBackground);
};



Pokemon:: Pokemon(){
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
    speed = 10;
}


void Pokemon:: draw(SDL_Plotter& g, string pokemonName){
    ifstream pokemonFile;
    pokemonFile.open(pokemonName.c_str());
    pokemonFile >> dimension1 >> dimension2;
    erase(g);
    for(int y =0;y <dimension1;y++){
        for(int x=0; x<dimension2; x++){
            pokemonFile >> R >> G >> B;

            if(R == 255 && G == 255 && B == 255)
            {
                R = background[loc.x+x][loc.y+y].R;
                G = background[loc.x+x][loc.y+y].G;
                B = background[loc.x+x][loc.y+y].B;
            }

            g.plotPixel(loc.x+x,loc.y+y,R,G,B);
        }
    }
    pokemonFile.close();
}

 void Pokemon:: erase(SDL_Plotter& g){
     for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
                g.plotPixel(oldLoc.x +x,oldLoc.y+y,background[oldLoc.x + x][oldLoc.y + y].R,background[oldLoc.x + x][oldLoc.y + y].G,background[oldLoc.x + x][oldLoc.y + y].B);
        }
     }
 }


void Pokemon:: move(DIR d){
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
    switch(d){
        case UP: loc.y-=speed;
                break;
        case DOWN: loc.y+=speed;
                break;
        case LEFT: loc.x-=speed;
                break;
        case RIGHT: loc.x+=speed;
                break;
    }
}
void Pokemon:: setLoc(Point p){
    loc.y = p.y;
    loc.x = p.x;
}

void setNamesFileName(string a[256])
{
    int counter = 0;
    ifstream indexFile;
    indexFile.open("pokemon.txt");
    do
    {
        indexFile >> a[counter];
        counter++;
    }while(!indexFile.eof());
    indexFile.close();
}

void Pokemon::scopeBackground(vector <vector<Point> > scopeBackground)
{
    scopeBackground.resize(1000, vector <Point>(1000));
    background.resize(1000, vector <Point>(1000));
    background = scopeBackground;
}
#endif // POKEMON_H_INCLUDED
