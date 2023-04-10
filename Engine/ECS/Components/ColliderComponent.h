#include "Shape.h"

struct ColliderComponent
{
    Shape* shape; 
    bool renderCollider;
    bool isColliding;

    ColliderComponent(Shape& shape,bool renderCollider, bool isColliding)
    {
        this->shape = shape.Clone();
        this->renderCollider = renderCollider;
        this->isColliding = false; //isColliding

    }
};