#ifndef KEYUPEVENT_H
#define KEYUPEVENT_H

#include <SDL2/SDL.h>
#include "entt/entt.hpp"
#include "Keyboard.h"

struct KeyUpEvent
{
    SDL_Keycode symbol;
    Keyboard keyboard;
    entt::registry* world;

    KeyUpEvent(SDL_Keycode symbol,Keyboard keyboard, entt::registry &world)
    {
        this->symbol = symbol;
        this->keyboard = keyboard;
        this->world = &world;

    };
};

#endif