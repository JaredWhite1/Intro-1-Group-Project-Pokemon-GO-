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
int randomSystemTime(int);
int randomProcessTicks(int);
void checkPosition(Pokemon, Background);
void checkNameEqual(Pokemon, Pokemon, string a[]);
void checkPositionEqual(Pokemon, Pokemon, Background);
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
    Pokemon f;
    Pokemon h;
    Pokemon i;
    Pokemon j;
    Pokemon k;
    Background background;
    Player player;
    Pokeball ball;
    Message clock;
    string pokemen[16];
    stringstream integerToString;
    stringstream integerToString2;
    setNamesFileName(pokemen);

    a.pokemonName = pokemen[randomSystemTime(16)];
    b.pokemonName = pokemen[randomProcessTicks(16)];
    c.pokemonName = pokemen[randomSystemTime(16)];
    d.pokemonName = pokemen[randomProcessTicks(16)];
    e.pokemonName = pokemen[randomSystemTime(16)];
    f.pokemonName = pokemen[randomProcessTicks(16)];
    h.pokemonName = pokemen[randomSystemTime(16)];
    i.pokemonName = pokemen[randomProcessTicks(16)];
    j.pokemonName = pokemen[randomSystemTime(16)];
    k.pokemonName = pokemen[randomProcessTicks(16)];

    char Key;

    background.setBackground();
    background.drawBackground(g);

    a.setLoc(background.objectBackground[randomProcessTicks(1000)][randomSystemTime(1000)]);
    checkPosition(a, background);
    a.scopeBackground(background.objectBackground);
    a.createSprite(a.pokemonName);

    b.setLoc(background.objectBackground[randomSystemTime(1000)][randomProcessTicks(1000)]);
    checkPosition(b, background);
    b.scopeBackground(background.objectBackground);
    b.createSprite(b.pokemonName);

    c.setLoc(background.objectBackground[randomProcessTicks(1000)][randomSystemTime(1000)]);
    checkPosition(c, background);
    c.scopeBackground(background.objectBackground);
    c.createSprite(c.pokemonName);

    d.setLoc(background.objectBackground[randomSystemTime(1000)][randomProcessTicks(1000)]);
    checkPosition(d, background);
    d.scopeBackground(background.objectBackground);
    d.createSprite(d.pokemonName);

    e.setLoc(background.objectBackground[randomProcessTicks(1000)][randomSystemTime(1000)]);
    checkPosition(e, background);
    e.scopeBackground(background.objectBackground);
    e.createSprite(e.pokemonName);

    f.setLoc(background.objectBackground[randomSystemTime(1000)][randomProcessTicks(1000)]);
    checkPosition(f, background);
    f.scopeBackground(background.objectBackground);
    f.createSprite(f.pokemonName);

    h.setLoc(background.objectBackground[randomProcessTicks(1000)][randomSystemTime(1000)]);
    checkPosition(h, background);
    h.scopeBackground(background.objectBackground);
    h.createSprite(h.pokemonName);

    i.setLoc(background.objectBackground[randomSystemTime(1000)][randomProcessTicks(1000)]);
    checkPosition(i, background);
    i.scopeBackground(background.objectBackground);
    i.createSprite(i.pokemonName);

    j.setLoc(background.objectBackground[randomProcessTicks(1000)][randomSystemTime(1000)]);
    checkPosition(j, background);
    j.scopeBackground(background.objectBackground);
    j.createSprite(j.pokemonName);

    k.setLoc(background.objectBackground[randomSystemTime(1000)][randomProcessTicks(1000)]);
    checkPosition(k, background);
    k.scopeBackground(background.objectBackground);
    k.createSprite(k.pokemonName);

    player.setLoc(background.objectBackground[500][500]);
    player.scopePlayerBackground(background.objectBackground);
    player.createSprite("TFD.txt");

    ball.scopeBallBackground(background.objectBackground);

    clock.scopeMessageBackground(background.objectBackground);
    clock.setLoc(background.objectBackground[812][692]);

    g.initSound("Pokemon Red%2FBlue%2FYellow (GB) Music - Pokemon Caught.wav");

    while (!g.getQuit())
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
            b.draw(g);
        }
        if(b.deleted == false)
        {
            a.draw(g);
        }
        if(c.deleted == false)
        {
            c.draw(g);
        }
        if(d.deleted == false)
        {
            d.draw(g);
        }
        if(e.deleted == false)
        {
            e.draw(g);
        }
        if(f.deleted == false)
        {
            f.draw(g);
        }
        if(h.deleted == false)
        {
            h.draw(g);
        }
        if(i.deleted == false)
        {
            i.draw(g);
        }
        if(j.deleted == false)
        {
            j.draw(g);
        }
        if(k.deleted == false)
        {
            k.draw(g);
        }
        player.draw(g);
        integerToString << timer;
        timerString = integerToString.str() + "s.txt";
        clock.createSprite(timerString);
        integerToString.str("");
        clock.draw(g);
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
                case SPACE: ball.createSprite();
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
                            g.playSound("Pokemon Red%2FBlue%2FYellow (GB) Music - Pokemon Caught.wav");
                            g.Sleep(300);
                            g.quitSound("Pokemon Red%2FBlue%2FYellow (GB) Music - Pokemon Caught.wav");
                            dontStop = 0;
                            messageShow = true;
                            a.specialErase(g);
                        }
                        if(ballCollide(ball, b) == true)
                        {
                            g.playSound("Pokemon Red%2FBlue%2FYellow (GB) Music - Pokemon Caught.wav");
                            g.Sleep(300);
                            g.quitSound("Pokemon Red%2FBlue%2FYellow (GB) Music - Pokemon Caught.wav");
                            dontStop = 0;
                            messageShow = true;
                            b.specialErase(g);
                        }
                        if(ball.loc.x <= 100 || ball.loc.y <= 100 || ball.loc.x >= 900 || ball.loc.y >= 900)
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
                    integerToString2.str("");
                    ball.specialErase(g);
                    a.deleted = true;
                    b.deleted = true;
                    g.update();
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

int randomSystemTime(int a)
{
    int random;

    srand(time(NULL));
    random = rand() % a;

    return random;
}

int randomProcessTicks(int a)
{
    int random;

    srand(SDL_GetTicks());
    random = rand() % a;

    return random;
}

void checkPosition(Pokemon a, Background c)
{
    if(a.loc.x <= 180 || a.loc.y <= 180 || a.loc.x >= 780 || a.loc.y >= 520)
    {
        while(a.loc.x <= 180 || a.loc.y <= 180 || a.loc.x >= 780 || a.loc.y >= 520)
        {
            a.setLoc(c.objectBackground[randomProcessTicks(1000)][randomSystemTime(1000)]);
        }
    }

    cout << a.loc.x << " " << a.loc.y << endl;
}

void checkPositionEqual(Pokemon a, Pokemon b, Background c)
{
    bool stop = false;

    for(int i = 0; i < 80; i++)
    {
        for(int f = 0; f < 80; f++)
        {
            if(b.loc.x + i == a.loc.x + i && b.loc.y + f == a.loc.y + f)
            {
                while(b.loc.x + i == a.loc.x + i && b.loc.y + f == a.loc.y + f)
                {
                    a.setLoc(c.objectBackground[randomSystemTime(1000)][randomSystemTime(1000)]);
                }
                stop = true;
                break;
            }
        }
        if(stop == true)
        {
            break;
        }
    }
}

void checkNameEqual(Pokemon a, Pokemon b, string c[])
{
    if(a.pokemonName == b.pokemonName)
    {
        while(a.pokemonName == b.pokemonName)
        {
            b.pokemonName = c[randomSystemTime(16)];
        }
    }
}

bool ballCollide(Pokeball a, Pokemon b)
{
    bool collide;
    bool stop = false;

    int g = 0;
    int h = 0;

    for(int i = 0; i < b.dimension1; i++)
    {
        for(int f = 0; f < b.dimension2; f++)
        {
            if(b.loc.x + i == a.loc.x + g && b.loc.y + f == a.loc.y + h)
            {
                collide = true;
                stop = true;
                break;
            }
            else
            {
                collide = false;
            }

            if(g <= 20)
            {
                g++;
            }
        }
        if(stop == true)
        {
            break;
        }

        if(h <= 20)
        {
            h++;
        }
    }
    return collide;
}
