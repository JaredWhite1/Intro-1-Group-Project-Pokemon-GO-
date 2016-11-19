#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "SDL_Plotter.h"
#include "Pokemon.h"
#include "background.h"
#include "player.h"

using namespace std;

int main(int argc, char ** argv)
{
    int frame = 0;
    SDL_Plotter g(1000,1000);
    Pokemon a;
    Pokemon b;
    Background c;
    Player d;
    Player array[12];
    string pokemen[256];
    setNamesFileName(pokemen);
    a.pokemonName = pokemen[0];
    b.pokemonName = pokemen[1];

    char Key;

    c.setBackground();
    c.drawBackground(g);
    a.setLoc(c.objectBackground[200][300]);
    a.scopeBackground(c.objectBackground);
    a.createSprite(pokemen[0]);
    b.setLoc(c.objectBackground[100][200]);
    b.scopeBackground(c.objectBackground);
    b.createSprite(pokemen[1]);
    d.setLoc(c.objectBackground[500][500]);
    d.scopePlayerBackground(c.objectBackground);
    d.createSprite1();

    while (!g.getQuit())
    {
        b.draw(g);
        a.draw(g);
        d.draw(g);
        g.update();

        if(g.kbhit()){
    	    Key =g.getKey();
    	    switch(Key){

            case UP_ARROW: d.createSprite1();
                           d.move(UP);
                           if(frame == 0)
                           {
                               g.Sleep(100);
                               d.createSprite2();
                               frame = 1;
                           }
                           else if(frame == 1)
                           {
                               g.Sleep(100);
                               d.createSprite1();
                               frame = 2;
                           }
                           else if(frame == 2)
                           {
                               g.Sleep(100);
                               d.createSprite3();
                               frame = 3;
                           }
                           else if(frame == 3)
                           {
                               g.Sleep(100);
                               d.createSprite1();
                               frame = 0;
                           }
                           break;
            case DOWN_ARROW: d.createSprite4();
                             d.move(DOWN);
                             if(frame == 0)
                             {
                                 g.Sleep(100);
                                 d.createSprite5();
                                 frame = 1;
                             }
                             else if(frame == 1)
                             {
                                 g.Sleep(100);
                                 d.createSprite4();
                                 frame = 2;
                             }
                             else if(frame == 2)
                             {
                                 g.Sleep(100);
                                 d.createSprite6();
                                 frame = 3;
                             }
                             else if(frame == 3)
                             {
                                 g.Sleep(100);
                                 d.createSprite4();
                                 frame = 0;
                             }
                             break;
            case LEFT_ARROW: d.createSprite7();
                             d.move(LEFT);
                             if(frame == 0)
                             {
                                 g.Sleep(100);
                                 d.createSprite8();
                                 frame = 1;
                             }
                             else if(frame == 1)
                             {
                                 g.Sleep(100);
                                 d.createSprite7();
                                 frame = 2;
                             }
                             else if(frame == 2)
                             {
                                 g.Sleep(100);
                                 d.createSprite9();
                                 frame = 3;
                             }
                             else if(frame == 3)
                             {
                                 g.Sleep(100);
                                 d.createSprite7();
                                 frame = 0;
                             }
                             break;
            case RIGHT_ARROW: d.createSprite10();
                              d.move(RIGHT);
                              if(frame == 0)
                              {
                                  g.Sleep(100);
                                  d.createSprite11();
                                  frame = 1;
                              }
                              else if(frame == 1)
                              {
                                  g.Sleep(100);
                                  d.createSprite10();
                                  frame = 2;
                              }
                              else if(frame == 2)
                              {
                                  g.Sleep(100);
                                  d.createSprite12();
                                  frame = 3;
                              }
                              else if(frame == 3)
                              {
                                  g.Sleep(100);
                                  d.createSprite10();
                                  frame = 0;
                              }
                              break;
    	    }

        }


    	}
    	return 0;
}
