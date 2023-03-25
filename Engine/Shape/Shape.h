#ifndef SHAPE_H
#define SHAPE_H

#include "Engine2D"

enum ShapeType
{
    CIRCLE,
    POLYGON,
    RECTANGLE
};

struct Shape
{
    //Color color;
    //bool filled;

    virtual Shape* Clone() const = 0;
    virtual ShapeType GetType() const = 0;
    virtual float GetMomentOfInertia() const = 0;
    virtual void Render(TransformComponent transform) const = 0;
};


#endif