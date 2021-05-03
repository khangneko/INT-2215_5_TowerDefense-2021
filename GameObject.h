#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL_image.h>
#include "Game.h"


class GameObject
{
public:
    GameObject(const char* textureSheet, SDL_Renderer* renderer, int xpos, int ypos);
    ~GameObject();
    void update();
    void render(SDL_Renderer* renderer);


private:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect rect;
};

#endif // GAMEOBJECT_H
