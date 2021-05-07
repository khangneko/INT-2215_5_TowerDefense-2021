#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include "Game.h"
#include "TextureManager.h"

class Button
{
    public:
        Button(int x, int y);
        void handleEvent(SDL_Event* e);
        void render(SDL_Renderer* renderer);
        bool isMouseInside();

    private:
        SDL_Point mPosition;
        bool mouseInside;

};

#endif // BUTTON_H_INCLUDED
