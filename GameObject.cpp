#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer, int xpos, int ypos)
{
    objTexture = TextureManager::loadTexture(textureSheet, renderer);
    this->xpos = xpos;
    this->ypos = ypos;
    rect.x = xpos;
    rect.y = ypos;
}

void GameObject::update()
{

}

void GameObject::render(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, objTexture, NULL, &rect);
}
GameObject::~GameObject()
{
    //dtor
}
