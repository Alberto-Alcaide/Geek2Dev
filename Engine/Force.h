#ifndef FORCE_H
#define FORCE_H

#include "Vec2D.h"

struct Force
{
    static Vec2D generateDragVector(float k, Vec2D velocity);
    static Vec2D generateSpringVector(Vec2D position, Vec2D anchor, float restLeng, float k);
};

#endif