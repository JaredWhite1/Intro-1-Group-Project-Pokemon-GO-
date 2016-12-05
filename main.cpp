/*
* Authors: Jared White, Caleb DeHaan, Eliza Sims, Matt Giles, and Patrick Brennan
* Assignment Title: Group Project (Pokemon GO)
* Assignment Description: This program is a game that increments
*                         score when catching pokemon with a pokeball
* Due Date: 12/5/2016
* Date Created: 11/14/2016
* Date Last Modified: 12/1/2016
 */

 /*
 * Data Abstraction:
 *      Create 12 booleans to limit the amount of times the clock can be decremented
 *      Create a boolean to ask if the game needs the quit screen or not
 *      Create 5 pokemon objects
 *      Create a player, background, message for the clock, and message2 for the score objects.
 *      Create 2 integers to spool for the current process run time
 *      Create a 2 counter integers to decrement as 10 seconds passes and to increment by 100 as pokemon are caught
 *      Create 2 strings to hold file names
 *      Create a plotter object
 *      Create 10 integers to dictate pokemon location
 *      Create an array of strings to hold file names of the pokemons
 *      Initialize 2 string streams to convert the counters to strings
 *      Create 5 integers to define pokemon identity
 * Input:
 *      The user can input with the spacebar to shoot pokeballs and the arrow keys to move.
 *      All sprites and the background are created from input file streams that hold dimensions and RGB values
 * Process:
 *      While the game isn't quit and the user still has time and hasn't score over 2000 points, the user "moves" the
 *      player, which is just a complex process of using point locations and the background's RGB values stored in a vector to redraw pixels,
 *      and attempts to catch pokemon by shooting pokeballs at them, which erases the pokeball and pokemon, plays a sound, and increments score by 100.
 *      The pokemon are redrawn in a different location when caught and the clock counts down as 10 seconds passes.
 * Output:
 *      The plotter draws the sprites and backgrounds using the RGB values stored in a vector and arrays.
 * Assumptions:
 *      The files used have valid values and don't exceed or underestimate the dimensions provided.
 *      The user knows the controls and rules (provided in users guide).
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include "SDL_Plotter.h"
#include "Pokemon.h"
#include "background.h"
#include "player.h"
#include "pokeball.h"
#include "message.h"
#include "message2.h"

using namespace std;


//**************************************************************
// description: Set the array values to the pokemon filenames  *
// return: Void (nothing)                                      *
// precondition: The filenames stored in pokemon.txt are valid *
// postcondition: The array of strings with the file names     *
//                is filled with the file names                *
//**************************************************************
void setNamesFileName(string a[]);


//************************************************************
// description: Set of instructions for when a pokemon is    *
//              caught                                       *
// return: void (nothing)                                    *
// precondition: The pokeball has collided with a pokemon    *
// postcondition: A sound is played, score is incremented,   *
//                and the pokeball and pokemon are erased    *
//                                                           *
//************************************************************
void catchPokemon(SDL_Plotter& g, Pokemon& a, int& dontStop, bool& messageShow);


//************************************************************
// description: Test whether or not the pokemon and pokeball *
//              collides or not                              *
// return: Boolean                                           *
// precondition:  The pokeball and pokemon objects exist     *
// postcondition: A boolean that says if the pokemon is in   *
//                the same loc as the pokeball is returned   *
//************************************************************
bool ballCollide(Pokeball a, Pokemon b);

int main(int argc, char ** argv)
{
    //These booleans were created since the division of the current time variable creates multiples of the same value, so
    //something had to be created to control decrementation to a singular instance
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

    bool exit = false; //The game isn't quit

    int currentTime; //Time right now
    int startTime; //Time since process start
    int timer = 120; //Timer counter
    bool messageShow = false; //Don't increment score
    int dontStop = 0; //Don't create a pokeball
    int score = 0; //Score is 0
    string timerString = "120s.txt"; //Clock starts at 120 seconds
    string scoreString; //Score starts by not displaying anything
    int frame = 0; //Player is facing downwards to start
    int direction = 1; //^^^
    SDL_Plotter g(1000,1000); //Plotter object
    Pokemon a; //Pokemon objects
    Pokemon b; //^^^
    Pokemon c; //^^^
    Pokemon d; //^^^
    Pokemon e; //^^^
    Background background; //Background object
    Player player; //Player object
    Pokeball ball; //Pokeball object
    Message clock; //Clock object
    Message2 scoreMessage; //Score object
    string pokemen[15]; //Array of file names
    stringstream integerToString; //Convert integer to string
    stringstream integerToString2; //^^^
    setNamesFileName(pokemen); //File names setting function call

    int aLocX = 200, aLocY = 300; //Pokemon a is given a location relative to the background
    int bLocX = 300, bLocY = 200; //Pokemon b is given a location relative to the background
    int cLocX = 800, cLocY = 100; //Pokemon c is given a location relative to the background
    int dLocX = 345, dLocY = 567; //Pokemon d is given a location relative to the background
    int eLocX = 123, eLocY = 734; //Pokemon e is given a location relative to the background

    int aName = 0; //Pokemon a is a pikachu to start
    int bName = 1; //Pokemon b is a bulbasaur to start
    int cName = 2; //Pokemon c is a caterpie to start
    int dName = 3; //Pokemon d is a charmander to start
    int eName = 4; //Pokemon e is a gastly to start

    a.pokemonName = pokemen[aName];
    b.pokemonName = pokemen[bName];
    c.pokemonName = pokemen[cName];
    d.pokemonName = pokemen[dName];
    e.pokemonName = pokemen[eName];

    char Key;

    background.setBackground("background.txt"); //The background's dimensions and RGB values are stored in background.txt
    background.drawBackground(g); //Draw the background

    a.setLoc(background.objectBackground[aLocX][aLocY]); //Set pokemon a's location to the appropriate coordinates
    a.scopeBackground(background.objectBackground); //Give pokemon a knowledge of the background vector's existence
    a.createSprite(a.pokemonName); //Assign pokemon a to its sprite

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
    player.createSprite("TFD.txt"); //Player is facing down to start (design choice)

    ball.scopeBallBackground(background.objectBackground);

    clock.scopeMessageBackground(background.objectBackground);
    clock.setLoc(background.objectBackground[812][692]);

    scoreMessage.scopeMessage2Background(background.objectBackground);
    scoreMessage.setLoc(background.objectBackground[812][827]);

    g.initSound("Pokemon_Red_2FBlue_2FYellow_GB_Music_-_Pokemon_Cau.wav"); //Initialize the catch noise

    while((!g.getQuit() && timer != 0) && (!g.getQuit() && score != 2000)) //While the x button isn't hit, the score isn't 2000, and the timer hasn't hit 0
    {
        startTime = SDL_GetTicks() - 2000; //Start time is more or less 0 milliseconds
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


        if(a.deleted == false) //If the pokemon hasn't been caught yet
        {
            a.draw(g); //Draw the pokemon
        }
        else
        {
            if(aLocX > 500 || aLocX < 115) //If the pokemon was located over 500 on the x-axis or under 115
            {
                aLocX += 145; //Increment the x-coordinate
                aLocY += 98; //Increment the y-coordinate
                if(aName <= 0)
                {
                    aName += 2; //Cycle the pokemon file name
                }
                else
                {
                    aName -= 2;

                    if(bName < 0) //Keep the array in scope
                    {
                        aName = 13;
                    }
                }
            }
            else
            {
                aLocX += 163;
                aLocY += 223;
                if(bName <= 0)
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

            if(aLocX <= 150)
            {
                while(aLocX <= 150)
                {
                    aLocX += 120;
                }
            }
            if(aLocY <= 150)
            {
                while(aLocY <= 150)
                {
                    aLocY += 320;
                }
            }
            if(aLocX >= 850)
            {
                while(aLocX >= 850)
                {
                    aLocX -= 220;
                }
            }
            if(aLocY >= 850)
            {
                while(aLocY >= 850)
                {
                    aLocY -= 220;
                }
            }
            if((aLocX >= 732 && aLocY >= 612) && (aLocX <= 1027 && aLocY >= 612) && (aLocX >= 732 && aLocY <= 995) && (aLocX <= 1027 && aLocY <= 995))
            {
                while((aLocX >= 732 && aLocY >= 612) && (aLocX <= 1027 && aLocY >= 612) && (aLocX >= 732 && aLocY <= 995) && (aLocX <= 1027 && aLocY <= 995))
                {
                    aLocX -= 450;
                    aLocY -= 450;
                }
            }

            a.pokemonName = pokemen[aName]; //Reset the pokemon file name
            a.setLoc(background.objectBackground[aLocX][aLocY]); //Reset the location
            a.createSprite(a.pokemonName); //Reset the sprite
            a.deleted = false; //Set deleted to false
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
                if(bName <= 0)
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
                if(bName <= 0)
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

            if(bLocX <= 150)
            {
                while(bLocX <= 150)
                {
                    bLocX += 120;
                }
            }
            if(bLocY <= 150)
            {
                while(bLocY <= 150)
                {
                    bLocY += 320;
                }
            }
            if(bLocX >= 850)
            {
                while(bLocX >= 850)
                {
                    bLocX -= 220;
                }
            }
            if(bLocY >= 850)
            {
                while(bLocY >= 850)
                {
                    bLocY -= 220;
                }
            }
            if((bLocX >= 732 && bLocY >= 612) && (bLocX <= 1027 && bLocY >= 612) && (bLocX >= 732 && bLocY <= 995) && (bLocX <= 1027 && bLocY <= 995))
            {
                while((bLocX >= 732 && bLocY >= 612) && (bLocX <= 1027 && bLocY >= 612) && (bLocX >= 732 && bLocY <= 995) && (bLocX <= 1027 && bLocY <= 995))
                {
                    bLocX -= 450;
                    bLocY -= 450;
                }
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
                if(cName <= 0)
                {
                    while(cName <= 0)
                    {
                        cName += 2;
                    }
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
                if(cName <= 0)
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

            if(cLocX <= 150)
            {
                while(cLocX <= 150)
                {
                    cLocX += 120;
                }
            }
            if(cLocY <= 150)
            {
                while(cLocY <= 150)
                {
                    cLocY += 320;
                }
            }
            if(cLocX >= 850)
            {
                while(cLocX >= 850)
                {
                    cLocX -= 220;
                }
            }
            if(cLocY >= 850)
            {
                while(cLocY >= 850)
                {
                    cLocY -= 220;
                }
            }
            if((cLocX >= 732 && cLocY >= 612) && (cLocX <= 1027 && cLocY >= 612) && (cLocX >= 732 && cLocY <= 995) && (cLocX <= 1027 && cLocY <= 995))
            {
                while((cLocX >= 732 && cLocY >= 612) && (cLocX <= 1027 && cLocY >= 612) && (cLocX >= 732 && cLocY <= 995) && (cLocX <= 1027 && cLocY <= 995))
                {
                    cLocX -= 450;
                    cLocY -= 450;
                }
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
            if(dLocX < 700 || dLocX > 300)
            {
                dLocX += 165;
                dLocY += 187;
                if(dName <= 0)
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
                if(dName <= 0)
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

            if(dLocX <= 150)
            {
                while(dLocX <= 150)
                {
                    dLocX += 120;
                }
            }
            if(dLocY <= 150)
            {
                while(dLocY <= 150)
                {
                    dLocY += 320;
                }
            }
            if(dLocX >= 850)
            {
                while(dLocX >= 850)
                {
                    dLocX -= 220;
                }
            }
            if(dLocY >= 850)
            {
                while(dLocY >= 850)
                {
                    dLocY -= 220;
                }
            }
            if((dLocX >= 732 && dLocY >= 612) && (dLocX <= 1027 && dLocY >= 612) && (dLocX >= 732 && dLocY <= 995) && (dLocX <= 1027 && dLocY <= 995))
            {
                while((dLocX >= 732 && dLocY >= 612) && (dLocX <= 1027 && dLocY >= 612) && (dLocX >= 732 && dLocY <= 995) && (dLocX <= 1027 && dLocY <= 995))
                {
                    dLocX -= 450;
                    dLocY -= 450;
                }
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
                if(eName <= 0)
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
                if(eName <= 0)
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

            if(eLocX <= 150)
            {
                while(eLocX <= 150)
                {
                    eLocX += 120;
                }
            }
            if(eLocY <= 150)
            {
                while(eLocY <= 150)
                {
                    eLocY += 320;
                }
            }
            if(eLocX >= 850)
            {
                while(eLocX >= 850)
                {
                    eLocX -= 220;
                }
            }
            if(eLocY >= 850)
            {
                while(eLocY >= 850)
                {
                    eLocY -= 220;
                }
            }
            if((eLocX >= 732 && eLocY >= 612) && (eLocX <= 1027 && eLocY >= 612) && (eLocX >= 732 && eLocY <= 995) && (eLocX <= 1027 && eLocY <= 995))
            {
                while((eLocX >= 732 && eLocY >= 612) && (eLocX <= 1027 && eLocY >= 612) && (eLocX >= 732 && eLocY <= 995) && (eLocX <= 1027 && eLocY <= 995))
                {
                    eLocX -= 450;
                    eLocY -= 450;
                }
            }

            e.pokemonName = pokemen[eName];
            e.setLoc(background.objectBackground[eLocX][eLocY]);
            e.createSprite(e.pokemonName);
            e.deleted = false;
        }
        player.draw(g); //Draw the player
        integerToString << timer; //Convert integer to string
        timerString = integerToString.str() + "s.txt";
        clock.createSprite(timerString);
        integerToString.str(""); //Clear the string stream
        clock.draw(g); //Draw the clock
        scoreString = score + ".txt"; //Conocate the string
        integerToString2 << score; //Convert the string to integer
        scoreString = integerToString2.str() + ".txt";
        scoreMessage.createSprite(scoreString);
        integerToString2.str(""); //Clear the string stream
        scoreMessage.draw(g); //Draw the score
        g.update(); //Update the plotter

        if(g.kbhit()){
            Key =g.getKey();

            switch(Key){

            case UP_ARROW: direction = 0; //Sprite is facing down
                           player.createSprite("TFU.txt"); //Set the sprite to facing up
                           player.move(UP); //Move the player up
                           if(frame == 0)
                           {
                               g.Sleep(100); //Sleep the plotter for a second
                               player.createSprite("TFU-R.txt"); //Right foot out
                               frame = 1;
                           }
                           else if(frame == 1)
                           {
                               g.Sleep(100);
                               player.createSprite("TFU.txt"); //No foot out
                               frame = 2;
                           }
                           else if(frame == 2)
                           {
                               g.Sleep(100);
                               player.createSprite("TFU-L.txt"); //Left foot out
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
                case ' ': ball.createSprite(); //Create the pokeball sprite
                          ball.setLoc(player.getLoc()); //Set the pokeball's location to the player's location
                          dontStop++; //Start the pokeball's movement
                          break;
                    }

                }


                if(dontStop != 0)
                {
                    while(dontStop != 0)
                    {
                        ball.move(direction); //Move the pokeball in the direction the player is facing
                        ball.draw(g); //Draw the pokeball
                        ball.createSprite(); //Set the sprite
                        player.draw(g); //Redraw the player
                        g.update(); //Update the plotter

                        if(ballCollide(ball, a) == true) //If the ball collides with the pokemon a
                        {
                            catchPokemon(g, a, dontStop, messageShow); //Catch pokemon function with pokemon a
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
                        else if(ball.loc.x <= 100 || ball.loc.y <= 100 || ball.loc.x >= 900 || ball.loc.y >= 900) //Erase the ball if it exits tree boundaries
                        {
                            dontStop = 0;
                            ball.specialErase(g);
                            g.update();
                        }
                    }
                }

                if(messageShow == true)
                {
                    score += 100; //Increment score by 100
                    integerToString2 << score; //Convert integer to string
                    scoreString = integerToString2.str() + ".txt";
                    scoreMessage.createSprite(scoreString);
                    scoreMessage.draw(g); //Draw score
                    integerToString2.str(""); //Clear string stream
                    ball.specialErase(g); //Special erase pokeball
                    g.update(); //Update the plotter
                    messageShow = false;
                }
    }

    if(exit == false)
    {
        background.setBackground("endGame.txt"); //Set the background to the end game splash
        background.drawBackground(g); //Redraw the background
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
    g.playSound("Pokemon_Red_2FBlue_2FYellow_GB_Music_-_Pokemon_Cau.wav");
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
    return collide;
}
