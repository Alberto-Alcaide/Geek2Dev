#ifndef SHAPE_H
#define SHAPE_H

#include "Color.h"
#include "TransformComponent.h"

enum ShapeType
{
    CIRCLE,
    POLYGON,
    RECTANGLE
};

class Shape
{
public:
    Color color;
    bool filled;
    bool draw;

    virtual Shape* Clone() const = 0;
    virtual ShapeType GetType() const = 0;
    virtual float GetMomentOfInertia() const = 0;
    virtual void Render(TransformComponent transform) const = 0;
};


#endif