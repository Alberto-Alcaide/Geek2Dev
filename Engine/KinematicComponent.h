#ifndef KINEMATICCOMPONENT_H
#define KINEMATICCOMPONENT_H

#include "Vec2D.h"

struct KinematicComponent
{
    Vec2D velocity;
    Vec2D acceleration;

    KinematicComponent(Vec2D velocity = Vec2D(0,0), Vec2D acceleration = Vec2D(0,0)) 
    {
        this->velocity = velocity;
        this->acceleration = acceleration;
    }
};

#endif