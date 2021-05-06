#include "Button.h"

Button::Button(int x, int y)
{
    mPosition.x = x;
    mPosition.y = y;
}

bool Button::isMouseInside()
{
    return this->mouseInside;
}
void Button::handleEvent(SDL_Event* e)
{
    if(e->type == SDL_MOUSEMOTION)
    {
        int x, y;
        SDL_GetMouseState( &x, &y );

        mouseInside = true;
        if( x < mPosition.x )
        {
            mouseInside = false;
        }
        //Mouse is right of the button
        else if( x > mPosition.x + BUTTON_WIDTH )
        {
            mouseInside = false;
        }
        //Mouse above the button
        else if( y < mPosition.y )
        {
            mouseInside = false;
        }
        //Mouse below the button
        else if( y > mPosition.y + BUTTON_HEIGHT )
        {
            mouseInside = false;
        }
    }
}

void Button::render()
{
    SDL_Texture* buttonTexture = TextureManager::loadTexture("Assets/Tower/Normal Button.png");
    SDL_Rect rect;
    rect.x = mPosition.x;
    rect.y = mPosition.y;
    rect.w = BUTTON_WIDTH;
    rect.h = BUTTON_HEIGHT;
    TextureManager::draw(buttonTexture, rect);
    SDL_DestroyTexture(buttonTexture);
}
