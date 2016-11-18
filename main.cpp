#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "SDL_Plotter.h"
#include "Pokemon.h"
#include "background.h"

using namespace std;

int main(int argc, char ** argv)
{
    SDL_Plotter g(1000,1000);
    Pokemon a;
    Pokemon b;
    Background c;
    string pokemen[256];
    setNamesFileName(pokemen);
    a.pokemonName = pokemen[0];
    b.pokemonName = pokemen[1];

    char Key;

    c.setBackground();
    c.drawBackground(g);
    a.setLoc(c.objectBackground[300][300]);
    a.scopeBackground(c.objectBackground);
    b.setLoc(c.objectBackground[100][100]);
    b.scopeBackground(c.objectBackground);

    while (!g.getQuit())
    {
        b.draw(g, b.pokemonName);
        a.draw(g, a.pokemonName);
        g.update();

        if(g.kbhit()){
    	    Key =g.getKey();
    	    switch(Key){

            case UP_ARROW: a.move(UP);
                    break;
            case DOWN_ARROW: a.move(DOWN);
                    break;
            case LEFT_ARROW: a.move(LEFT);
                    break;
            case RIGHT_ARROW: a.move(RIGHT);
                    break;
    	    }


        }


    	}
    	return 0;
}
