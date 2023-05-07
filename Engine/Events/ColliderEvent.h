#ifndef COLLIDEREVENT_H
#define COLLIDEREVENT_H

#include <SDL2/SDL.h>
#include "entt/entt.hpp"

struct ColliderEvent
{
    entt::entity obj1;
    entt::entity obj2;

    ColliderEvent( entt::entity a, entt::entity b):
    obj1(a),obj2(b){}
};


#endif