#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL_image.h>
#include "Game.h"
#include <string>


class GameObject
{
public:
    GameObject(std::string filePath, int xpos, int ypos);
    virtual void update();
    void render();
    int getXpos();
    int getYpos();


protected:
    int xpos;
    int ypos;
    double angle = -90;
    std::string filePath;

    SDL_Texture* objTexture;
    SDL_Rect rect;
};

#endif // GAMEOBJECT_H
