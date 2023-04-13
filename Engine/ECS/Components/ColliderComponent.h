#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include "Shape.h"

struct ColliderComponent
{
    Shape* shape; 
    bool renderCollider;
    bool isColliding;

    ColliderComponent(const Shape& shape,bool renderCollider=true, bool isColliding=false)
    {
        this->shape = shape.Clone();
        this->renderCollider = renderCollider;
        this->isColliding = isColliding; //isColliding

    }
};

#endif