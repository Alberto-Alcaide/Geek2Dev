#ifndef KINEMATICSCOMPONENT_H
#define KINEMATICSCOMPONENT_H

#include "Vec2D.h"

struct KinematicsComponent
{
    // Linear version
    Vec2D velocity;
    Vec2D acceleration;

    // Angular version
    float angularVelocity;
    float angularAcceleration;

    KinematicsComponent(Vec2D velocity = Vec2D(0,0), Vec2D acceleration = Vec2D(0,0)) 
    {
        this->velocity = velocity;
        this->acceleration = acceleration;
        this->angularVelocity = angularVelocity;
        this->angularAcceleration = angularAcceleration;
    }
};

#endif