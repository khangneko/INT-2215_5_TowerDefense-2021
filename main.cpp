// this is a test
#include <exception>
#include <string>
#include <iostream>
#include <SDL.h>
#include "Game.h"


Game *game = nullptr;
int main( int argc, char * argv[] )
{
    game = new Game("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800, 600, false);
    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }
    game->~Game();
    return 1;
}
