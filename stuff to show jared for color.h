struct Point{
    int x, y;
    Point(int x = 0, int y = 0);
};

struct Color{
    int R, G, B;
    Color(){
        R = G = B = 255;
    }
};

Pokemon::Pokemon(string a){
    ifstream file(a.c_str());
    oldLoc = loc;
    speed = 10;
    file >> row >> col;
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            file >> pic[r][c].R;
            file >> pic[r][c].G;
            file >> pic[r][c].B;
        }
    }
}

void Pokemon::draw(SDL_Plotter& g){
    erase(g);
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            if(pic[r][c].R != 255 && pic[r][c].G != 255 && pic[r][c].B != 255)
                g.plotPixel(loc.x + r, loc.y + c, pic[r][c].R, pic[r][c].G, pic[r][c].B);
        }
    }
    g.update();
}

void Pokemon::erase(SDL_Plotter& g){
    for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++){
            g.plotPixel(oldLoc.x+x, oldLoc.y+y, 255, 255, 255);
        }
    }
}


MAIN:

#include <iostream>
#include "Pokemon.h"
#include "SDL_Plotter.h"

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(500,500);
    string aString;
    cout << "Please Enter A String: ";
    cin >> aString;
    Pokemon a(aString);
    int x,y, xd, yd;
    int R,G,B;
    char key;

    a.setLoc(Point(250,250));

    while (!g.getQuit())
    {
    	a.draw(g);
    	g.update();

    	if(g.kbhit()){
    	    key = g.getKey();

    	    switch(key){
                case UP_ARROW:
                    a.move(UP);
                    break;
                case LEFT_ARROW:
                    a.move(LEFT);
                    break;
                case DOWN_ARROW:
                    a.move(DOWN);
                    break;
                case RIGHT_ARROW:
                    a.move(RIGHT);
                    break;
    	    }
    	}
    }
}
