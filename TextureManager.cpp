#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(std::string filePath, SDL_Renderer* renderer)
{
    SDL_Surface* tmpSurface = IMG_Load(filePath.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return texture;
}

void TextureManager::draw(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect rect)
{
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}
