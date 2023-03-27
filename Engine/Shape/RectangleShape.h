#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H

#include "PolygonShape.h"

class RectangleShape : public PolygonShape
{
public:
    float width;    
    float height;

    RectangleShape(float width, float height, Color color = Color::red(), bool filled = true)
    {
        this->width =  width;
        this->height =  height;
        this->color =  color;
        this->filled =  filled;

        if(width != 0 && height != 0)
        {
            // Load the vertices of the box polygon
            // order top-left, top-right, bottom-left, bottom-right
            localVertices.push_back(Vec2D(-width / 2.0, height / 2.0));
            localVertices.push_back(Vec2D(width / 2.0, height / 2.0));
            localVertices.push_back(Vec2D(-width / 2.0, -height / 2.0));
            localVertices.push_back(Vec2D(width / 2.0, -height / 2.0));

           
            globalVertices.push_back(Vec2D(-width / 2.0, height / 2.0));
            globalVertices.push_back(Vec2D(width / 2.0, height / 2.0));
            globalVertices.push_back(Vec2D(-width / 2.0, -height / 2.0));
            globalVertices.push_back(Vec2D(width / 2.0, -height / 2.0));
        }
        else
            Log::Error("Error when creatring rectangleShape. Width and Height cannot be 0");
    }    

    Shape* Clone() const override
    {
        return new RectangleShape(width, height, color, filled);
    }

    ShapeType GetType() const override
    {
        return RECTANGLE;
    }

    float GetMomentOfInertia() const override
    {
        // Moment of inertia of a rectangle: 1/12* * (w^2 + h^2)
        // This still needs to be multiplied by the rigidbody's mass
        return 0.08333333333 * (width*width + height*height);
    }

    void Render(TransformComponent transform) const override
    {
        if(this->filled)
        {
            Graphics::drawRotatedFillRect(globalVertices, Color::red());
        }
        else
        {
            Graphics::drawRotatedRect(globalVertices, Color::red());
        }
    }
};

#endif