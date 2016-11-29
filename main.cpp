#include <iostream>
#include <sstream>
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
#include "message1.h"
#include "message2.h"

using namespace std;

void setNamesFileName(string a[]);
void catchPokemon(SDL_Plotter& g, Pokemon& a, int& dontStop, bool& messageShow);
bool ballCollide(Pokeball a, Pokemon b);

int main(int argc, char ** argv)
{
    bool decremented120 = true;
    bool decremented110 = true;
    bool decremented100 = true;
    bool decremented90 = true;
    bool decremented80 = true;
    bool decremented70 = true;
    bool decremented60 = true;
    bool decremented50 = true;
    bool decremented40 = true;
    bool decremented30 = true;
    bool decremented20 = true;
    bool decremented10 = true;

    bool exit = false;

    int currentTime;
    int startTime;
    int timer = 120;
    bool messageShow = false;
    int dontStop = 0;
    int score = 0;
    string timerString = "120s.txt";
    string scoreString;
    int frame = 0;
    int direction = 1;
    SDL_Plotter g(1000,1000);
    Pokemon a;
    Pokemon b;
    Pokemon c;
    Pokemon d;
    Pokemon e;
    Background background;
    Player player;
    Pokeball ball;
    Message clock;
    Message2 scoreMessage;
    string pokemen[15];
    stringstream integerToString;
    stringstream integerToString2;
    setNamesFileName(pokemen);

    int aLocX = 200, aLocY = 300;
    int bLocX = 300, bLocY = 200;
    int cLocX = 800, cLocY = 100;
    int dLocX = 345, dLocY = 567;
    int eLocX = 123, eLocY = 734;

    int aName = 0;
    int bName = 1;
    int cName = 2;
    int dName = 3;
    int eName = 4;

    a.pokemonName = pokemen[aName];
    b.pokemonName = pokemen[bName];
    c.pokemonName = pokemen[cName];
    d.pokemonName = pokemen[dName];
    e.pokemonName = pokemen[eName];

    char Key;

    background.setBackground("background.txt");
    background.drawBackground(g);

    a.setLoc(background.objectBackground[aLocX][aLocY]);
    a.scopeBackground(background.objectBackground);
    a.createSprite(a.pokemonName);

    b.setLoc(background.objectBackground[bLocX][bLocY]);
    b.scopeBackground(background.objectBackground);
    b.createSprite(b.pokemonName);

    c.setLoc(background.objectBackground[cLocX][cLocY]);
    c.scopeBackground(background.objectBackground);
    c.createSprite(c.pokemonName);

    d.setLoc(background.objectBackground[dLocX][dLocY]);
    d.scopeBackground(background.objectBackground);
    d.createSprite(d.pokemonName);

    e.setLoc(background.objectBackground[eLocX][eLocY]);
    e.scopeBackground(background.objectBackground);
    e.createSprite(e.pokemonName);

    player.setLoc(background.objectBackground[500][500]);
    player.scopePlayerBackground(background.objectBackground);
    player.createSprite("TFD.txt");

    ball.scopeBallBackground(background.objectBackground);

    clock.scopeMessageBackground(background.objectBackground);
    clock.setLoc(background.objectBackground[812][692]);

    scoreMessage.scopeMessage2Background(background.objectBackground);
    scoreMessage.setLoc(background.objectBackground[812][827]);

    g.initSound("Pokemon Red%2FBlue%2FYellow (GB) Music - Pokemon Caught.wav");

    while((!g.getQuit() && timer != 0) && (!g.getQuit() && score != 2000))
    {
        startTime = SDL_GetTicks() - 2000;
        if(startTime/1000 == 10 && decremented120 == true)
        {
            timer = timer - 10;
            cout << timer << endl;
            decremented120 = false;
        }
        if(startTime/1000 == 20 && decremented110 == true)
        {
            timer = timer - 10;
            cout << timer << endl;
            decremented110 = false;
        }
        if(startTime/1000 == 30 && decremented100 == true)
        {
            timer = timer - 10;
            cout << timer << endl;
            decremented100 = false;
        }
        if(startTime/1000 == 40 && decremented90 == true)
        {
            timer = timer - 10;
            cout << timer << endl;
            decremented90 = false;
        }
        if(startTime/1000 == 50 && decremented80 == true)
        {
            timer = timer - 10;
            cout << timer << endl;
            decremented80 = false;
        }
        if(startTime/1000 == 60 && decremented70 == true)
        {
            timer = timer - 10;
            cout << timer << endl;
            decremented70 = false;
        }
        if(startTime/1000 == 70 && decremented60 == true)
        {
            timer = timer - 10;
            cout << timer << endl;
            decremented60 = false;
        }
        if(startTime/1000 == 80 && decremented50 == true)
        {
            timer = timer - 10;
            cout << timer << endl;
            decremented50 = false;
        }
        if(startTime/1000 == 90 && decremented40 == true)
        {
            timer = timer - 10;
            cout << timer << endl;
            decremented40 = false;
        }
        if(startTime/1000 == 100 && decremented30 == true)
        {
            timer = timer - 10;
            cout << timer << endl;
            decremented30 = false;
        }
        if(startTime/1000 == 110 && decremented20 == true)
        {
            timer = timer - 10;
            cout << timer << endl;
            decremented20 = false;
        }
        if(startTime/1000 == 120 && decremented10 == true)
        {
            timer = timer - 10;
            cout << timer << endl;
            decremented10 = false;
        }


        if(a.deleted == false)
        {
            a.draw(g);
        }
        else
        {
            if(aLocX > 500 || aLocX < 115)
            {
                aLocX += 145;
                aLocY += 98;
                if(aName == 0)
                {
                    aName += 2;
                }
                else
                {
                    aName -= 2;

                    if(bName < 0)
                    {
                        aName = 13;
                    }
                }
            }
            else
            {
                aLocX += 163;
                aLocY += 223;
                if(bName == 0)
                {
                    aName += 13;
                }
                else
                {
                    aName -= 1;

                    if(aName < 0)
                    {
                        aName = 10;
                    }
                }
            }

            if(aLocX <= 100 || aLocY <= 100 || aLocX >= 900 || aLocY >= 900 || ((aLocX >= 720 && aLocY >= 580) || (aLocX >= 720 && aLocY <= 820) || (aLocX <= 870 && aLocY >= 580)))
            {
                aLocX -= 432;
                aLocY -= 623;
            }


            a.pokemonName = pokemen[aName];
            a.setLoc(background.objectBackground[aLocX][aLocY]);
            a.createSprite(a.pokemonName);
            a.deleted = false;
        }
        if(b.deleted == false)
        {
            b.draw(g);
        }
        else
        {
            if(bLocX > 400 || bLocX < 135)
            {
                bLocX += 134;
                bLocY += 276;
                if(bName == 0)
                {
                    bName += 3;
                }
                else
                {
                    bName -= 1;

                    if(bName < 0)
                    {
                        bName = 10;
                    }
                }
            }
            else
            {
                bLocX += 263;
                bLocY += 323;
                if(bName == 0)
                {
                    bName += 12;
                }
                else
                {
                    bName -= 2;

                    if(bName < 0)
                    {
                        bName = 10;
                    }
                }
            }

            if(bLocX <= 100 || bLocY <= 100 || bLocX >= 900 || bLocY >= 900 || ((bLocX >= 720 && bLocY >= 580) || (bLocX >= 720 && bLocY <= 820) || (bLocX <= 870 && bLocY >= 580)))
            {
                bLocX -= 500;
                bLocY -= 124;
            }

            b.pokemonName = pokemen[bName];
            b.setLoc(background.objectBackground[bLocX][bLocY]);
            b.createSprite(b.pokemonName);
            b.deleted = false;
        }
        if(c.deleted == false)
        {
            c.draw(g);
        }
        else
        {
            if(cLocX > 600 || cLocX < 355)
            {
                cLocX += 156;
                cLocY += 523;
                if(cName == 0)
                {
                    cName += 2;
                }
                else
                {
                    cName -= 4;

                    if(cName < 0)
                    {
                        cName = 10;
                    }
                }
            }
            else
            {
                cLocX += 168;
                cLocY += 234;
                if(cName == 0)
                {
                    cName += 12;
                }
                else
                {
                    cName -= 2;

                    if(cName < 0)
                    {
                        cName = 10;
                    }
                }
            }

            if(cLocX <= 100 || cLocY <= 100 || cLocX >= 900 || cLocY >= 900 || ((cLocX >= 720 && cLocY >= 580) || (cLocX >= 720 && cLocY <= 820) || (cLocX <= 870 && cLocY >= 580)))
            {
                cLocX -= 400;
                cLocY -= 124;
            }

            c.pokemonName = pokemen[cName];
            c.setLoc(background.objectBackground[cLocX][cLocY]);
            c.createSprite(c.pokemonName);
            c.deleted = false;
        }
        if(d.deleted == false)
        {
            d.draw(g);
        }
        else
        {
            if(dLocX > 700 || dLocX < 500)
            {
                dLocX += 165;
                dLocY += 187;
                if(dName == 0)
                {
                    dName += 4;
                }
                else
                {
                    dName -= 2;

                    if(dName < 0)
                    {
                        dName = 11;
                    }
                }
            }
            else
            {
                dLocX += 23;
                dLocY += 345;
                if(dName == 0)
                {
                    dName += 1;
                }
                else
                {
                    dName -= 1;

                    if(dName < 0)
                    {
                        dName = 12;
                    }
                }
            }

            if(dLocX <= 100 || dLocY <= 100 || dLocX >= 900 || dLocY >= 900 || ((dLocX >= 720 && dLocY >= 580) || (dLocX >= 720 && dLocY <= 820) || (dLocX <= 870 && dLocY >= 580)))
            {
                dLocX -= 300;
                dLocY -= 124;
            }

            d.pokemonName = pokemen[dName];
            d.setLoc(background.objectBackground[dLocX][dLocY]);
            d.createSprite(d.pokemonName);
            d.deleted = false;
        }
        if(e.deleted == false)
        {
            e.draw(g);
        }
        else
        {
            if(eLocX > 400 || eLocX < 135)
            {
                eLocX += 34;
                eLocY += 76;
                if(eName == 0)
                {
                    eName += 3;
                }
                else
                {
                    eName -= 1;

                    if(eName < 0)
                    {
                        eName = 10;
                    }
                }
            }
            else
            {
                eLocX += 163;
                eLocY += 323;
                if(eName == 0)
                {
                    eName += 12;
                }
                else
                {
                    eName -= 2;

                    if(eName < 0)
                    {
                        eName = 10;
                    }
                }
            }

            if(eLocX <= 100 || eLocY <= 100 || eLocX >= 900 || eLocY >= 900 || ((eLocX >= 720 && eLocY >= 580) || (eLocX >= 720 && eLocY <= 820) || (eLocX <= 870 && eLocY >= 580)))
            {
                eLocX -= 200;
                eLocY -= 124;
            }

            e.pokemonName = pokemen[eName];
            e.setLoc(background.objectBackground[eLocX][eLocY]);
            e.createSprite(e.pokemonName);
            e.deleted = false;
        }
        player.draw(g);
        integerToString << timer;
        timerString = integerToString.str() + "s.txt";
        clock.createSprite(timerString);
        integerToString.str("");
        clock.draw(g);
        scoreString = score + ".txt";
        integerToString2 << score;
        scoreString = integerToString2.str() + ".txt";
        scoreMessage.createSprite(scoreString);
        integerToString2.str("");
        scoreMessage.draw(g);
        g.update();

        if(g.kbhit()){
            Key =g.getKey();

            switch(Key){

            case UP_ARROW: direction = 0;
                           player.createSprite("TFU.txt");
                           player.move(UP);
                           if(frame == 0)
                           {
                               g.Sleep(100);
                               player.createSprite("TFU-R.txt");
                               frame = 1;
                           }
                           else if(frame == 1)
                           {
                               g.Sleep(100);
                               player.createSprite("TFU.txt");
                               frame = 2;
                           }
                           else if(frame == 2)
                           {
                               g.Sleep(100);
                               player.createSprite("TFU-L.txt");
                               frame = 3;
                           }
                           else if(frame == 3)
                           {
                               g.Sleep(100);
                               player.createSprite("TFU.txt");
                               frame = 0;
                           }
                           break;
            case DOWN_ARROW: player.createSprite("TFD.txt");
                             player.move(DOWN);
                             direction = 1;
                             if(frame == 0)
                             {
                                 g.Sleep(100);
                                 player.createSprite("TFD-R.txt");
                                 frame = 1;
                             }
                             else if(frame == 1)
                             {
                                 g.Sleep(100);
                                 player.createSprite("TFD.txt");
                                 frame = 2;
                             }
                             else if(frame == 2)
                             {
                                 g.Sleep(100);
                                 player.createSprite("TFD-L.txt");
                                 frame = 3;
                             }
                             else if(frame == 3)
                             {
                                 g.Sleep(100);
                                 player.createSprite("TFD.txt");
                                 frame = 0;
                             }
                             break;
             case LEFT_ARROW: player.createSprite("TFL.txt");
                              player.move(LEFT);
                              direction = 2;
                              if(frame == 0)
                              {
                                  g.Sleep(100);
                                  player.createSprite("TFL-R.txt");
                                  frame = 1;
                              }
                              else if(frame == 1)
                              {
                                  g.Sleep(100);
                                  player.createSprite("TFL.txt");
                                  frame = 2;
                              }
                              else if(frame == 2)
                              {
                                  g.Sleep(100);
                                  player.createSprite("TFL-L.txt");
                                  frame = 3;
                              }
                              else if(frame == 3)
                              {
                                  g.Sleep(100);
                                  player.createSprite("TFL.txt");
                                  frame = 0;
                              }
                              break;
              case RIGHT_ARROW:  player.createSprite("TFR.txt");
                                 player.move(RIGHT);
                                 direction = 3;
                                 if(frame == 0)
                                 {
                                     g.Sleep(100);
                                     player.createSprite("TFR-R.txt");
                                     frame = 1;
                                 }
                                 else if(frame == 1)
                                 {
                                     g.Sleep(100);
                                     player.createSprite("TFR.txt");
                                     frame = 2;
                                 }
                                 else if(frame == 2)
                                 {
                                     g.Sleep(100);
                                     player.createSprite("TFR-L.txt");
                                     frame = 3;
                                 }
                                 else if(frame == 3)
                                 {
                                     g.Sleep(100);
                                     player.createSprite("TFR.txt");
                                     frame = 0;
                                 }
                                 break;
                case ' ':   ball.createSprite();
                            ball.setLoc(player.loc);
                            dontStop++;
                            break;
                    }

                }


                if(dontStop != 0)
                {
                    while(dontStop != 0)
                    {
                        ball.move(direction);
                        ball.draw(g);
                        ball.createSprite();
                        player.draw(g);
                        g.update();

                        if(ballCollide(ball, a) == true)
                        {
                            catchPokemon(g, a, dontStop, messageShow);
                        }
                        else if(ballCollide(ball, b) == true)
                        {
                            catchPokemon(g, b, dontStop, messageShow);
                        }
                        else if(ballCollide(ball, c) == true)
                        {
                            catchPokemon(g, c, dontStop, messageShow);
                        }
                        else if(ballCollide(ball, d) == true)
                        {
                            catchPokemon(g, d, dontStop, messageShow);
                        }
                        else if(ballCollide(ball, e) == true)
                        {
                            catchPokemon(g, e, dontStop, messageShow);
                        }
                        else if(ball.loc.x <= 100 || ball.loc.y <= 100 || ball.loc.x >= 900 || ball.loc.y >= 900)
                        {
                            dontStop = 0;
                            ball.specialErase(g);
                            g.update();
                        }
                    }
                }

                if(messageShow == true)
                {
                    score += 100;
                    scoreString = score + ".txt";
                    integerToString2 << score;
                    scoreString = integerToString2.str() + ".txt";
                    scoreMessage.createSprite(scoreString);
                    scoreMessage.draw(g);
                    integerToString2.str("");
                    ball.specialErase(g);
                    g.update();
                    messageShow = false;
                }
    }

    if(exit == false)
    {
        background.setBackground("endGame.txt");
        background.drawBackground(g);
        currentTime = SDL_GetTicks();

        a.setLoc(background.objectBackground[aLocX][aLocY]);
        a.scopeBackground(background.objectBackground);
        a.createSprite(a.pokemonName);

        b.setLoc(background.objectBackground[bLocX][bLocY]);
        b.scopeBackground(background.objectBackground);
        b.createSprite(b.pokemonName);

        c.setLoc(background.objectBackground[cLocX][cLocY]);
        c.scopeBackground(background.objectBackground);
        c.createSprite(c.pokemonName);

        d.setLoc(background.objectBackground[dLocX][dLocY]);
        d.scopeBackground(background.objectBackground);
        d.createSprite(d.pokemonName);

        e.setLoc(background.objectBackground[eLocX][eLocY]);
        e.scopeBackground(background.objectBackground);
        e.createSprite(e.pokemonName);

        player.setLoc(background.objectBackground[500][500]);
        player.scopePlayerBackground(background.objectBackground);
        player.createSprite("TFD.txt");

        while(exit == false)
        {
            cout << SDL_GetTicks() - currentTime << endl;
            a.specialErase(g);
            b.specialErase(g);
            c.specialErase(g);
            d.specialErase(g);
            e.specialErase(g);
            player.specialErase(g);
            g.update();

            if(SDL_GetTicks() - currentTime >= 10000)
            {
                exit = true;
            }
        }
    }
    return 0;
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

void catchPokemon(SDL_Plotter& g, Pokemon& pokemon, int& dontStop, bool& messageShow)
{
    g.playSound("Pokemon Red%2FBlue%2FYellow (GB) Music - Pokemon Caught.wav");
    dontStop = 0;
    pokemon.specialErase(g);
    pokemon.deleted = true;
    messageShow = true;
    g.update();
}

bool ballCollide(Pokeball a, Pokemon b)
{
    bool collide;
    bool stop = false;

    int g = 0;
    int h = 0;

    for(int p = 0; p < 10; p++)
    {
        for(int i = 0; i < b.dimension1; i++)
        {
            while(g < 20)
            {
                for(int f = 0; f < b.dimension2; f++)
                {
                    while(h < 20)
                    {
                        if(b.loc.x + i == a.loc.x + g && b.loc.y + f == a.loc.y + h)
                        {
                            collide = true;
                            stop = true;
                            break;
                        }
                        h++;
                    }
                    h = 0;
                }
                g++;
            }
            if(stop == true)
            {
                break;
            }
            g = 0;
        }
    }
    return collide;
}
