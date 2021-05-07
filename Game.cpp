#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Enemy.h"
#include "Button.h"
#include "Tower.h"

SDL_Renderer* Game::renderer = NULL;
Map* map;
std::vector<Enemy*> enemies;
std::vector<Tower*> towers;
Button* button;
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
        uiRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;
    }
    map = new Map();
    button = new Button(1190, 100);
    std::cout << 100;


}

/*void Game::handleEvents()
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
}*/

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT)
    {
        isRunning = false;
    }
    button->handleEvent(&event);
    if(button->isMouseInside() && event.type == SDL_MOUSEBUTTONDOWN)
    {
        isPlacingTower = true;
        std::cout << "GODLIKE!!!";
    }
    if(isPlacingTower && event.type == SDL_MOUSEBUTTONDOWN && !button->isMouseInside())
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        Tower* tower = new Tower(TOWER_FILE_PATH, x, y);
        towers.push_back(tower);
        isPlacingTower = false;
    }
}

void Game::update()
{
    if (!towers.empty())
    {
        for (int i =0; i < towers.size(); i++)
        {
            if(!enemies.empty())
            {

                for(int j = 0; j < enemies.size(); j++)
                {
                    if (towers[i]->isEnemyInRange(enemies[j]) && !(towers[i]->hasTarget()))
                    {
                        towers[i]->setTartget(enemies[j]);
                    }
                }
            }
            towers[i]->update();
        }
    }

    if (!enemies.empty())
    {
        for (int i = 0; i < enemies.size(); i++)
        {
            if (enemies[i]->isDead() || enemies[i]->isOutOfBound())
            {
                Enemy* e = enemies[i];
                enemies.erase(enemies.begin() + i -1);
                delete e;
            }
            else enemies[i]->update();
        }
    }
    if (enemies.empty()) waveEnd = true;
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
    map->render(renderer);
    button->render(renderer);
    if(!towers.empty())
    {
        for (int i = 0; i < towers.size(); i++)
        {
            towers[i]->render();
        }
    }
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
