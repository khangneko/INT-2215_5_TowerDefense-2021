#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include "Game.h"
#include <SDL_image.h>
#include <SDL.h>

class TextureManager
{
    public:
        static SDL_Texture* loadTexture(std::string filePath, SDL_Renderer* renderer);
        static void draw(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect rect);
};

#endif // TEXTUREMANAGER_H
