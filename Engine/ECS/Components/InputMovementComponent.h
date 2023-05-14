#ifndef INPUTMOVEMENTCOMPONENT_H
#define INPUTMOVEMENTCOMPONENT_H

#include "Vec2D.h"

struct InputMovementComponent
{
    float xVelocity;
    float yVelocity;

    InputMovementComponent(float xVelocity = 100, float yVelocity = 100): xVelocity(xVelocity), yVelocity(yVelocity) {}
};

#endif