#ifndef KINEMATICCOMPONENT_H
#define KINEMATICCOMPONENT_H

#include "Vec2D.h"

struct KinematicComponent
{
    Vec2D velocity;
    Vec2D acceleration;

    KinematicComponent() 
    {
        this->velocity = velocity;
        this->acceleration = acceleration;
    }
};

#endif