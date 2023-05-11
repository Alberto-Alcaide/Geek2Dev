#ifndef BALLHITBRICKEVENT_H
#define BALLHITBRICKEVENT_H

#include <SDL2/SDL.h>
#include "entt/entt.hpp"
#include "Collision.h"

struct BallHitBrickEvent
{
    entt::entity a;
    entt::entity b; 
    Contact contact;
    entt::registry* world;

    BallHitBrickEvent(entt::entity a, entt::entity b, Contact& contact, entt::registry& world): a(a), b(b), contact(contact), world(&world) {}
};

#endif