#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <iostream>

struct SpriteComponent
{
    int width;
    int height;

    SDL_Texture* texture;

    SpriteComponent(int w, int h, SDL_Texture* t)
    {
        width = w;
        height = h;
        texture = t;
    }
};



#endif