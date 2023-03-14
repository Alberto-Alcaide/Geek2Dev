#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "Vec2D.h"

struct TransformComponent
{
    Vec2D position;
    double rotation;
    Vec2D scale;

    TransformComponent(Vec2D position = Vec2D(0,0), double rotation = 0.0, Vec2D scale = Vec2D(1,1))
    {
        this->position=position;
        this->rotation=rotation;
        this->scale=scale;
    }
};



#endif