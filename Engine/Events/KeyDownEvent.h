#ifndef KEYDOWNEVENT_H
#define KEYDOWNEVENT_H

#include <SDL2/SDL.h>
#include "entt/entt.hpp"
#include "Keyboard.h"

struct KeyDownEvent
{
    SDL_Keycode symbol;
    Keyboard keyboard;
    entt::registry* world;

    KeyDownEvent(SDL_Keycode symbol, Keyboard keyboard, entt::registry& world): symbol(symbol), keyboard(keyboard), world(&world) {}
};

#endif