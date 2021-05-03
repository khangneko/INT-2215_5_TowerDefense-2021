#ifndef MAP_H_
#define MAP_H_

#include <string>
#include "TextureManager.h"
#include "Constants.h"
using namespace std;

class Map
{
public:
    void drawMap(SDL_Renderer* renderer);
private:
    int path[12][18] =
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
        {0,0,0,0,0,6,7,7,7,2,0,0,0,0,0,0,0,0,},
        {0,0,0,0,0,7,0,0,0,7,0,0,0,0,0,0,0,0,},
        {0,0,0,0,0,7,0,0,0,7,0,0,0,0,0,0,0,0,},
        {0,0,0,0,0,7,0,0,0,7,0,0,0,0,0,0,0,0,},
        {0,0,0,0,0,7,0,0,0,7,0,0,0,0,0,0,0,0,},
        {0,6,7,7,7,8,0,0,0,7,0,0,0,0,0,0,0,0,},
        {0,7,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,},
        {0,7,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,},
        {0,7,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,},
        {0,8,0,0,0,0,0,0,0,6,7,7,7,7,7,7,7,7,},
        {0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}
    };
    string map_sprite[12][18] =
    {
        {"024","024","024","024","069","070","070","070","070","070","071","024","024","024","024","024","024","024",},
        {"024","024","024","024","092","093","093","093","093","093","094","024","024","024","024","024","024","024",},
        {"024","024","024","024","092","093","072","116","073","093","094","024","024","024","024","024","024","024",},
        {"024","024","024","024","092","093","094","024","092","093","094","024","024","024","024","024","024","024",},
        {"024","024","024","024","092","093","094","024","092","093","094","024","024","024","024","024","024","024",},
        {"069","070","070","070","096","093","094","024","092","093","094","024","024","024","024","024","024","024",},
        {"092","093","093","093","093","093","094","024","092","093","094","024","024","024","024","024","024","024",},
        {"092","093","072","116","116","116","117","024","092","093","094","024","024","024","024","024","024","024",},
        {"092","093","094","024","024","024","024","024","092","093","094","024","024","024","024","024","024","024",},
        {"092","093","094","024","024","024","024","024","092","093","095","070","070","070","070","070","070","070",},
        {"092","093","094","024","024","024","024","024","092","093","093","093","093","093","093","093","093","093",},
        {"092","093","094","024","024","024","024","024","115","116","116","116","116","116","116","116","116","116",}
    };


};

#endif // MAP_H_
