#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "SDL.h"
#include <iostream>
#include <vector>
#include "Constants.h"


class Game {
public:
    static SDL_Renderer* renderer;
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void spawnEnemies();
    void placeTower(int xPos, int yPos);
    void render();
    void clean();
    bool running();

private:
    int tick = 0;
    int waveCount = 0;
    int enemiesNumber = ENEMY_NUMBER;
    int enemiesCount = 0;
    bool isSpawning = true;
    bool waveEnd = false;
    bool isRunning;
    bool isPlacingTower = false;
    SDL_Window *window;




};


#endif // GAME_H_INCLUDED
