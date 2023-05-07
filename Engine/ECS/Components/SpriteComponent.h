#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <iostream>

struct SpriteComponent
{
    int width;
    int height;

    SDL_Texture* texture;
    SDL_Rect srcRect;

    SpriteComponent(int w, int h, SDL_Texture* t)
    {
        width = w;
        height = h;
        texture = t;   

        srcRect = {0, 0, w, h};
    }
};



#endif