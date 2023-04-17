#ifndef COLIDEREVENT_H
#define COLIDEREVENT_H

#include <SDL2/SDL.h>
#include "entt/entt.hpp"

struct ColiderEvent
{
    entt::entity obj1;
    entt::entity obj2;

    ColiderEvent( entt::entity a, entt::entity b):
    obj1(a),obj2(b){}
};


#endif