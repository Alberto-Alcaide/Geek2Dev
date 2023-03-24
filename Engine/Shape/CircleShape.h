#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "Shape.h"
#include "Engine2D.h"

class CircleShape : public Shape
{

    float radius;
    Color color;
    bool filled;

    CircleShape(float radius,  Color color, bool filled )
    {
        this->radius = radius;
        this->color = color;
        this->filled = filled;
    }

    Shape* Clone() const
    {
        return new CircleShape(radius, color, filled);
    }

    ShapeType GetType() const 
    {
        return CIRCLE;
    }

    float GetMomentOfInertia() const
    {
        return 0.5 * (radius * radius);
    }

    void Render(TransformComponent transform) const override{
        if (this->filled)
            Graphics::drawFillCircle(
                transform.position.x,
                transform.position.y,
                this->radius,
                this->color
            );
        else
            Graphics::drawCircle(
                transform.position.x,
                transform.position.y,
                this->radius,
                this->color
            );
    }

};

#endif