#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Enemy.h"

SDL_Renderer* Game::renderer = NULL;
Map* map;
std::vector<Enemy*> enemies;
Game::Game()
{

}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initiliazed..." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "Window created!" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;
    }
    map = new Map();
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;

    default:
        break;
    }
}

void Game::update()
{
    if (enemiesCount < enemiesNumber && isSpawning)
    {
        if (tick % SPAWN_RATE == 0)
        {
            spawnEnemies();
            enemiesCount++;
        }
    }
    else
    {
        tick = 0;
        enemiesCount = 0;
        isSpawning = false;
    }
    for (int i = 0; i < enemies.size(); i++)
    {
        if (enemies[i]->isDead() || enemies[i]->isOutOfBound())
        {
            Enemy* e = enemies[i];
            enemies.erase(enemies.begin() + i -1);
            delete e;
        }
        enemies[i]->update();
    }
    tick++;
}

void Game::spawnEnemies()
{
    Enemy* enemy = new Enemy(ENEMY_FILE_PATH, SPAWN_X, SPAWN_Y);
    enemies.push_back(enemy);
}


void Game::render()
{
    SDL_RenderClear(renderer);
    map->render();
    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i]->render();
    }
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Closed" << std::endl;
}
bool Game::running()
{
    return isRunning;
}
