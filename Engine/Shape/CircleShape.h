#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "Graphics.h"

struct CircleShape
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

    CircleShape* Clone() const
    {
        return new CircleShape(radius, color, filled);
    }
    /*
    ShapeType GetType() const 
    {
        return CIRCLE;
    }
    */

    float GetMomentOfInertia() const
    {
        return 0.5 * (radius * radius);
    }

    void Render(TransformComponent transform) const
    {
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