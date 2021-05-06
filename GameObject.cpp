#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(std::string filePath, int xpos, int ypos)
{
    this->filePath = filePath;
    this->xpos = xpos;
    this->ypos = ypos;
    objTexture = TextureManager::loadTexture(filePath);
    rect.x = xpos - 32;
    rect.y = ypos - 32;
    rect.w = rect.h = 64;
}

void GameObject::update()
{
    std::cout << "Do something";
}

void GameObject::render()
{
    TextureManager::draw(objTexture, rect, this->angle);
}

int GameObject::getXPos()
{
    return this->xpos;
}

int GameObject::getYPos()
{
    return this->ypos;
}

SDL_Texture* GameObject::getObjTexture()
{
    return this->objTexture;
}

