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

    void UpdateVertices(float rotation, Vec2D position)
    {   
        // Clear the globalVertices vector
        globalVertices.clear();

        // Compute the sine and cosine of the rotation angle
        float cosAngle = std::cos(rotation);
        float sinAngle = std::sin(rotation);

        // Compute the rotated and translated vertices
        for (const Vec2D& localVertex : localVertices) 
        {
            // Rotate the vertex
            Vec2D rotatedVertex = Vec2D(localVertex.x * cosAngle - localVertex.y * sinAngle,
                                        localVertex.x * sinAngle + localVertex.y * cosAngle);
            // Translate the vertex
            Vec2D translatedVertex = rotatedVertex + position;
            // Add the vertex to the globalVertices vector
            globalVertices.push_back(translatedVertex);
        }
    }
};



#endif