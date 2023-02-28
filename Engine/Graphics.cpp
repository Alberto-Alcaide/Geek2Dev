#include "Graphics.h"

void Graphics::DrawGrid(void)
{

}

void Graphics::DrawPixel(int x, int y, Color color)
{
    if (x >= 0 && x < window_width && y >= 0 && y < window_height)
    {
        color_buffer[(window_width * y) + x] = color;
    }
}

void Graphics::DrawLine(int x0, int y0, int x1, int y1, Color color)
{
    int delta_x=(x1-x0);
    int delta_y=(y1-y0);
    int longest_side_lenght=(abs(delta_x)>=abs(delta_y)) ? abs(delta_x) : abs(delta_y);
    float x_inc=delta_x / (float)longest_side_lenght;
    float y_inc=delta_y / (float)longest_side_lenght;
    float current_x=x0;
    float current_y=y0;
    for(int i=0; i<= longest_side_lenght; i++)
    {
        DrawPixel(round(current_x), round(current_y), color);
        current_x += x_inc;
        current_y += y_inc;
    }
}

void DrawRect(int x, int y, int width, int height, Color color);

void DrawFillRect(int x, int y, int width, int height, Color color);

void DrawPolygon(int x, int y, const std::vector<Vec2D>& vertices, Color color);

void Graphics::DrawCircle(int x0, int y0, int radius, Color color)
{
    const int32_t diameter = (radius * 2);
    int32_t x= (radius-1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t err= (tx - diameter);

    while(x>=y)
    {
        DrawPixel(x0 + x, y0 + y, color);
        DrawPixel(x0 + y, y0 + x, color);
        DrawPixel(x0 - y, y0 + y, color);
        DrawPixel(x0 - x, y0 + y, color);
        DrawPixel(x0 - x, y0 - y, color);
        DrawPixel(x0 - y, y0 - x, color);
        DrawPixel(x0 + y, y0 - x, color);
        DrawPixel(x0 + x, y0 - y, color);

        if (err <= 0)
        {
            ++y;
            err += ty;
            ty += 2;

        }

        if (err > 0)
        {
            --x;
            tx += 2;
            err += (tx - diameter);
        }
    }
}

void Graphics::DrawFillCircle(int x0, int y0, int radius, Color color)
{
    const int32_t diameter = (radius * 2);
    int32_t x= (radius-1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t err= (tx - diameter);

    while(x>=y) 
    { 
        DrawLine(x0 + x, y0 - y, x0 + x, y0 + y, color);
        DrawLine(x0 - x, y0 - y, x0 - x, y0 + y, color);
        DrawLine(x0 + y, y0 - x, x0 + y, y0 + x, color);
        DrawLine(x0 - y, y0 - x, x0 - y, y0 + x, color);
      

        if (err <= 0)
        {
            ++y;
            err += ty;
            ty += 2;

        }

        if (err > 0)
        {
            --x;
            tx += 2;
            err += (tx - diameter);
        }
    }
}

void RenderFrame();