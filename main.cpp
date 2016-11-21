#include <iostream>
#include <ctime>

#include "SDL_Plotter.h"
#include "Pokemon.h"

using namespace std;

int main(int argc, char ** argv)
{
    SDL_Plotter g(1000,1000);
    Pokemon a,b;
    char key,direction;
    string pokemonName[] = {"image.txt"};

    a.setLoc(Point(500,500));
    b.setLoc(Point(250,250));

    while(!g.getQuit())
    {
        a.draw(g,pokemonName[0]);
        b.draw(g,pokemonName[0]);
        g.update();
    	if(true)
    	{
            srand(time(NULL));
    	    key = rand()%4+1;
    	    direction = rand()%4+1;
    	    switch(key)
            {
                case UP_ARROW:      a.move(UP);
                                    break;
                case DOWN_ARROW:    a.move(DOWN);
                                    break;
                case LEFT_ARROW:    a.move(LEFT);
                                    break;
                case RIGHT_ARROW:   a.move(RIGHT);
                                    break;
            }
            switch(direction)
            {
                case UP_ARROW:      b.move(UP);
                                    break;
                case DOWN_ARROW:    b.move(DOWN);
                                    break;
                case LEFT_ARROW:    b.move(LEFT);
                                    break;
                case RIGHT_ARROW:   b.move(RIGHT);
                                    break;
            }
    	}
    }
}
