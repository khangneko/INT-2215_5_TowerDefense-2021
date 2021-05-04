#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "SDL.h"
#include <iostream>
#include <vector>


class Game {
public:
    static SDL_Renderer* renderer;
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void spawnEnemies();
    void render();
    void clean();
    bool running();

private:
    int tick = 0;
    int waveCount = 0;
    int enemiesNumber = 5;
    int enemiesCount = 0;
    bool isSpawning = true;
    bool waveEnd = false;
    bool isRunning;
    SDL_Window *window;




};


#endif // GAME_H_INCLUDED
