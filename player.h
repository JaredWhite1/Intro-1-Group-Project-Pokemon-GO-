#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "background.h"

class Player
{
    private:
        Point loc;
        Point oldLoc;
        int speed;
        int dimension1, dimension2, R, G, B;
        Color player[76][56];
    public:
        vector <vector<Point> > background;
        Player();
        void scopePlayerBackground(vector <vector<Point> > scopePlayerBackground);
        void draw(SDL_Plotter&);
        void erase(SDL_Plotter&);
        void move(DIR);
        void setLoc(Point);
        void createSprite1();
        void createSprite2();
        void createSprite3();
        void createSprite4();
        void createSprite5();
        void createSprite6();
        void createSprite7();
        void createSprite8();
        void createSprite9();
        void createSprite10();
        void createSprite11();
        void createSprite12();
};

Player :: Player()
{
    oldLoc.x = loc.x;
    oldLoc.y = loc.y;
    speed = 7;
}

void Player:: createSprite1()
{
    ifstream playerFile;
    playerFile.open("TFU.txt");
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

void Player:: createSprite2()
{
    ifstream playerFile;
    playerFile.open("TFU-L.txt");
    dimension1 = 76;
    dimension2 = 56;
    for(int r = 0; r < dimension1; r++){
        for(int c = 0; c < dimension2; c++){
            playerFile >> player[r][c].R;
            playerFile >> player[r][c].G;void createSprite1();
            playerFile >> player[r][c].B;
        }
    }
    playerFile.close();
}

void Player:: createSprite3()
{
    ifstream playerFile;
    playerFile.open("TFU-R.txt");
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

void Player:: createSprite4()
{
    ifstream playerFile;
    playerFile.open("TFD.txt");
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

void Player:: createSprite5()
{
    ifstream playerFile;
    playerFile.open("TFD-L.txt");
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

void Player:: createSprite6()
{
    ifstream playerFile;
    playerFile.open("TFD-R.txt");
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

void Player:: createSprite7()
{
    ifstream playerFile;
    playerFile.open("TFL.txt");
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

void Player:: createSprite8()
{
    ifstream playerFile;
    playerFile.open("TFL-L.txt");
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

void Player:: createSprite9()
{
    ifstream playerFile;
    playerFile.open("TFL-R.txt");
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

void Player:: createSprite10()
{
    ifstream playerFile;
    playerFile.open("TFR.txt");
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

void Player:: createSprite11()
{
    ifstream playerFile;
    playerFile.open("TFR-L.txt");
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

void Player:: createSprite12()
{
    ifstream playerFile;
    playerFile.open("TFR-R.txt");
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

void Player::move(DIR d)
{
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

void Player::setLoc(Point p)
{
    loc.y = p.y;
    loc.x = p.x;
}


#endif // PLAYER_H_INCLUDED
