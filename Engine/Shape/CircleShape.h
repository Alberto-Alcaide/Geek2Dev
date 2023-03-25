#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "TransformComponent.h"
#include "Graphics.h"
#include <cmath>

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
   /*
   void UpdateCircle(TransformComponent transform)
   {
        transform.position.x = radius * cos(transform.rotation);
        transform.position.y = radius * sin(transform.rotation);
        Render(transform);
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
                transform.rotation,
                this->color
            );
    }

};

#endif