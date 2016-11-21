#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "SDL_Plotter.h"
#include "Pokemon.h"
#include "background.h"
#include "player.h"
#include "pokeball.h"
#include "message.h"

using namespace std;

int main(int argc, char ** argv)
{
    bool messageShow = false;
    int dontStop = 0;
    int frame = 0;
    int direction;
    SDL_Plotter g(1000,1000);
    Pokemon a;
    Pokemon b;
    Background c;
    Player d;
    Pokeball e;
    Message f;
    string pokemen[256];
    setNamesFileName(pokemen);
    a.pokemonName = pokemen[0];
    b.pokemonName = pokemen[1];

    char Key;
    char Random;

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
    d.createSprite("TFD.txt");
    e.scopeBallBackground(c.objectBackground);
    f.setLoc(c.objectBackground[300][300]);
    f.scopeMessageBackground(c.objectBackground);
    f.createSprite("message.txt");

    while (!g.getQuit())
    {
        if(b.deleted == false)
        {
            b.draw(g);
        }
        if(a.deleted == false)
        {
            a.draw(g);
        }
        d.draw(g);
        g.update();

        if(g.kbhit()){
    	    Key =g.getKey();

    	    switch(Key){

            case UP_ARROW: direction = 0;
                           d.createSprite("TFU.txt");
                           d.move(UP);
                           if(frame == 0)
                           {
                               g.Sleep(100);
                               d.createSprite("TFU-R.txt");
                               frame = 1;
                           }
                           else if(frame == 1)
                           {
                               g.Sleep(100);
                               d.createSprite("TFU.txt");
                               frame = 2;
                           }
                           else if(frame == 2)
                           {
                               g.Sleep(100);
                               d.createSprite("TFU-L.txt");
                               frame = 3;
                           }
                           else if(frame == 3)
                           {
                               g.Sleep(100);
                               d.createSprite("TFU.txt");
                               frame = 0;
                           }
                           break;
            case DOWN_ARROW: d.createSprite("TFD.txt");
                             d.move(DOWN);
                             direction = 1;
                             if(frame == 0)
                             {
                                 g.Sleep(100);
                                 d.createSprite("TFD-R.txt");
                                 frame = 1;
                             }
                             else if(frame == 1)
                             {
                                 g.Sleep(100);
                                 d.createSprite("TFD.txt");
                                 frame = 2;
                             }
                             else if(frame == 2)
                             {
                                 g.Sleep(100);
                                 d.createSprite("TFD-L.txt");
                                 frame = 3;
                             }
                             else if(frame == 3)
                             {
                                 g.Sleep(100);
                                 d.createSprite("TFD.txt");
                                 frame = 0;
                             }
                             break;
            case LEFT_ARROW: d.createSprite("TFL.txt");
                             d.move(LEFT);
                             direction = 2;
                             if(frame == 0)
                             {
                                 g.Sleep(100);
                                 d.createSprite("TFL-R.txt");
                                 frame = 1;
                             }
                             else if(frame == 1)
                             {
                                 g.Sleep(100);
                                 d.createSprite("TFL.txt");
                                 frame = 2;
                             }
                             else if(frame == 2)
                             {
                                 g.Sleep(100);
                                 d.createSprite("TFL-L.txt");
                                 frame = 3;
                             }
                             else if(frame == 3)
                             {
                                 g.Sleep(100);
                                 d.createSprite("TFL.txt");
                                 frame = 0;
                             }
                             break;
            case RIGHT_ARROW: d.createSprite("TFR.txt");
                              d.move(RIGHT);
                              direction = 3;
                              if(frame == 0)
                              {
                                  g.Sleep(100);
                                  d.createSprite("TFR-R.txt");
                                  frame = 1;
                              }
                              else if(frame == 1)
                              {
                                  g.Sleep(100);
                                  d.createSprite("TFR.txt");
                                  frame = 2;
                              }
                              else if(frame == 2)
                              {
                                  g.Sleep(100);
                                  d.createSprite("TFR-L.txt");
                                  frame = 3;
                              }
                              else if(frame == 3)
                              {
                                  g.Sleep(100);
                                  d.createSprite("TFR.txt");
                                  frame = 0;
                              }
                              break;
            case SPACE: e.createSprite();
                        e.setLoc(d.loc);
                        dontStop++;
                        break;
    	    }

        }


        if(dontStop != 0)
        {
            while(dontStop != 0)
            {
                e.move(direction);
                e.draw(g);
                e.createSprite();
                d.draw(g);
                g.update();

                if(ballCollide(e, a) == true)
                {
                    f.setLoc(e.loc);
                    dontStop = 0;
                    messageShow = true;
                    a.specialErase(g);
                }
                if(ballCollide(e, b) == true)
                {
                    f.setLoc(e.loc);
                    dontStop = 0;
                    messageShow = true;
                    b.specialErase(g);
                }
                if(e.loc.x <= 100 || e.loc.y <= 100 || e.loc.x >= 900 || e.loc.y >= 900)
                {
                    dontStop = 0;
                    e.specialErase(g);
                    g.update();
                }
            }
        }

        if(messageShow == true)
        {
            //f.scopeMessageBackground(c.objectBackground);
            //f.createSprite("message.txt");
            //f.draw(g);
            e.specialErase(g);
            a.deleted = true;
            b.deleted = true;
            g.update();
        }
    }
    return 0;
}
