#ifndef POLYGONSHAPE_H
#define POLYGONSHAPE_H

#include "Shape.h"
#include "TransformComponent.h"
#include "Graphics.h"


class PolygonShape : public Shape
{
public:
    std::vector<Vec2D> localVertices;
    std::vector<Vec2D> globalVertices;

    PolygonShape() =default;
    PolygonShape(const std::vector<Vec2D> vertices);


    virtual Shape* Clone() const = 0;
    virtual ShapeType GetType() const = 0;
    virtual float GetMomentOfInertia() const = 0;
    virtual void Render(TransformComponent transform) const = 0;

    void UpdateVertices(float angle, Vec2D position)
    {   

        // Loop all the vertices, transforming from local to global 
        for (size_t i = 0; i < localVertices.size(); i++) 
        {

            // First rotate, then we translate
            globalVertices[i] = localVertices[i].rotate(angle);
            globalVertices[i] += position;
        }
    }
};



#endif