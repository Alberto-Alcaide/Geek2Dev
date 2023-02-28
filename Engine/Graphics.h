#ifndef Graphics_H
#define Graphics_H

#include <iostream>
#include <stdint.h>
#include "Color.h"
#include "Vec2D.h"


struct Graphics
{
    void DrawGrid(void);
    void DrawPixel(int x, int y, Color color);
    void DrawLine(int x0, int y0, int x1, int y1, Color color);
    void DrawRect(int x, int y, int width, int height, Color color);
    void DrawFillRect(int x, int y, int width, int height, Color color);
    void DrawPolygon(int x, int y, const std::vector<Vec2D>& vertices, Color color);
    void DrawCircle(int x0, int y0, int radius, Color color);
    void DrawFillCircle(int x0, int y0, int radius, Color color);

    void RenderFrame();


};



#endif