#ifndef KINEMATICSCOMPONENT_H
#define KINEMATICSCOMPONENT_H

#include "Vec2D.h"

struct KinematicsComponent
{
    Vec2D velocity;
    Vec2D acceleration;

    KinematicsComponent(Vec2D velocity = Vec2D(0,0), Vec2D acceleration = Vec2D(0,0)) 
    {
        this->velocity = velocity;
        this->acceleration = acceleration;
    }
};

#endif