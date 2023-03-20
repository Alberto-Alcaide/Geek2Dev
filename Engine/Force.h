#ifndef FORCE_H
#define FORCE_H

#include "Vec2D.h"

struct Force{
    static Vec2D Generate_Drag_Vector(float k, Vec2D velocity);
    static Vec2D Generate_Spring_Vector(Vec2D position, Vec2D anchor, float restLeng, float k);
};

#endif