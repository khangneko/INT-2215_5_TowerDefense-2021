#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(std::string filePath)
{
    SDL_Surface* tmpSurface = IMG_Load(filePath.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return texture;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect rect)
{
    SDL_RenderCopy(Game::renderer, texture, NULL, &rect);
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect rect, double angle)
{
    SDL_RenderCopyEx(Game::renderer, texture, NULL, &rect, angle, NULL, SDL_FLIP_NONE);
}

