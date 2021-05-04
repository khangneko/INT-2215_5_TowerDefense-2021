#include "Map.h"


void Map::drawMap()
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
            string tilePath ="Assets/Tile/towerDefense_tile" ;
            tilePath = tilePath + map_sprite[i][j] + ".png";
            SDL_Texture* tileTexture = TextureManager::loadTexture(tilePath);
            TextureManager::draw(tileTexture, rect);
            SDL_DestroyTexture(tileTexture);
        }
    }
}

void Map::drawUI()
{
    SDL_Texture* uiTexture = TextureManager::loadTexture("Assets/ui/ui_choose.jpg");
    SDL_Rect rect;
    rect.x = GAME_WIDTH;
    rect.y = 0;
    rect.w = UI_HORIZONTAL;
    rect.h = SCREEN_HEIGHT;
    TextureManager::draw(uiTexture, rect);
    SDL_DestroyTexture(uiTexture);
}

void Map::render()
{
    drawMap();
    drawUI();
}
