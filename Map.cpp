#include "Map.h"

Map::Map()
{
    for(int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            string tilePath ="Assets/Tile/towerDefense_tile" ;
            tilePath = tilePath + map_sprite[i][j] + ".png";
            SDL_Surface* tmpSurface = IMG_Load(tilePath.c_str());
            tileTexture[i][j] = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
            SDL_FreeSurface(tmpSurface);
        }
    }
}
void Map::drawMap(SDL_Renderer* renderer)
{
    SDL_Rect rect;
    rect.w = 64;
    rect.h = 64;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            rect.x = j * TILE_SIZE;
            rect.y = i * TILE_SIZE;

            TextureManager::draw(renderer, tileTexture[i][j], rect);

        }
    }
}

void Map::drawUI(SDL_Renderer* renderer)
{
    SDL_Texture* uiTexture = TextureManager::loadTexture("Assets/ui/ui_choose.jpg");
    SDL_Rect rect;
    rect.x = GAME_WIDTH;
    rect.y = 0;
    rect.w = UI_HORIZONTAL;
    rect.h = SCREEN_HEIGHT;
    TextureManager::draw(renderer, uiTexture, rect);
    SDL_DestroyTexture(uiTexture);
}

void Map::render(SDL_Renderer* renderer)
{
    drawMap(renderer);
    drawUI(renderer);
}
