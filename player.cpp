/*
* Authors: Jared White, Caleb DeHaan, Eliza Sims, Matt GIles, and Patrick Brennan
* Assignment Title: Group Project (Pokemon GO)
* Assignment Description: This program is a game that increments
*                         score when catching pokemon with a pokeball
* Due Date: 12/5/2016
* Date Created: 11/14/2016
* Date Last Modified: 12/1/2016
 */


#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "player.h"

Player :: Player()
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
    speed = 10;
}

void player::setOldLoc(Point p){
    oldLoc.y = p.y;
    oldLoc.x = p.x;
}

void player::setSpeed(int spd){
    speed = spd;
}

void player::setDimensions(int x, int y){
    dimension1 = x;
    dimension2 = y;
}

void Player:: createSprite(string a)
{
    ifstream playerFile;
    playerFile.open(a.c_str());
    dimension1 = 76;
    dimension2 = 56;
    for(int r = 0; r < dimension1; r++){
        for(int c = 0; c < dimension2; c++){
            playerFile >> player[r][c].R;
            playerFile >> player[r][c].G;
            playerFile >> player[r][c].B;
        }
    }
    playerFile.close();
}


void Player::scopePlayerBackground(vector <vector<Point> > scopePlayerBackground)
{
    scopePlayerBackground.resize(1000, vector <Point>(1000));
    background.resize(1000, vector <Point>(1000));
    background = scopePlayerBackground;
}

void Player::draw(SDL_Plotter& g)
{
    erase(g);
    for(int y =0;y <dimension1;y++){
        for(int x=0; x<dimension2; x++){

            if(player[y][x].R == 255 && player[y][x].G == 255 && player[y][x].B == 255)
            {
                player[y][x].R = background[loc.x+x][loc.y+y].R;
                player[y][x].G = background[loc.x+x][loc.y+y].G;
                player[y][x].B = background[loc.x+x][loc.y+y].B;
            }

            g.plotPixel(loc.x+x,loc.y+y,player[y][x].R, player[y][x].G, player[y][x].B);
        }
    }
}

void Player::erase(SDL_Plotter& g)
{
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
                g.plotPixel(oldLoc.x +x,oldLoc.y+y,background[oldLoc.x + x][oldLoc.y + y].R,background[oldLoc.x + x][oldLoc.y + y].G,background[oldLoc.x + x][oldLoc.y + y].B);
        }
     }
}

void Player::specialErase(SDL_Plotter& g)
{
    for(int y= 0;y<dimension1;y++){
        for(int x =0;x<dimension2;x++){
            g.plotPixel(loc.x +x,loc.y+y,background[loc.x + x][loc.y + y].R,background[loc.x + x][loc.y + y].G,background[loc.x + x][loc.y + y].B);
        }
    }
}

void Player::move(DIR d)
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
    switch(d){
        case UP:    loc.y-=speed;
                    if(loc.y<30)
                    {
                        loc.y+=speed;
                    }
                    break;
        case DOWN:  loc.y+=speed;
                    if(loc.y>820)
                    {
                        loc.y-=speed;
                    }
                    break;
        case LEFT:  loc.x-=speed;
                    if(loc.x<40)
                    {
                        loc.x+=speed;
                    }
                    break;
        case RIGHT: loc.x+=speed;
                    if(loc.x>919)
                    {
                        loc.x-=speed;
                    }
                    break;
    }
}

void Player::setLoc(Point p)
{
    loc.y = p.y;
    loc.x = p.x;
}

Point Player::getLoc(){
    return loc;
}

Point Player::getOldLoc(){
    return oldLoc;
}

int Player::getSpeed(){
    return speed;
}

int Player::getDimension1(){
    return dimension1;
}

int Player::getDimension2(){
    return dimension2;
}



#endif // PLAYER_H_INCLUDED
