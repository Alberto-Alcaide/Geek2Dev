#ifndef HORIZONTALMOVEMENTCOMPONENT_H
#define HORIZONTALMOVEMENTCOMPONENT_H

#include "Vec2D.h"

struct HorizontalMovementComponent
{
    float stepSize;

    HorizontalMovementComponent(float stepSize): stepSize(stepSize) {}
};

#endif