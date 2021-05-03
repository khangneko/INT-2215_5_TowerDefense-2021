#include "Map.h"


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
            string tilePath ="Assets/Tile/towerDefense_tile" ;
            tilePath = tilePath + map_sprite[i][j] + ".png";
            SDL_Texture* tileTexture = TextureManager::loadTexture(tilePath, renderer);
            TextureManager::draw(renderer, tileTexture, rect);
        }
    }
}
