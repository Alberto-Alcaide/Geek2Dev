#ifndef GRIDMOVEMENTCOMPONENT_H
#define GRIDMOVEMENTCOMPONENT_H

#include "Vec2D.h"

struct GridMovementComponent
{
    float stepSize;

    GridMovementComponent(float stepSize): stepSize(stepSize) {}
};

#endif