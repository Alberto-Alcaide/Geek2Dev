
#include "Color.h"

Color::Color(){}

// Create Color (Red=r, Green=g, Blue=b, Alpha=1)
Color::Color(int r, int g, int b): r(r), g(g), b(b), a(1) {}

// Create Color (Red=r, Green=g, Blue=b, Alpha=a)
Color::Color(int r, int g, int b, int a): r(r), g(g), b(b), a(a){}

Color::Color(uint32_t color)
{
    r=color & 0xFF;
    g=(color >> 8) & 0xFF;
    b=(color >> 16) & 0xFF;
    a=(color >> 24) & 0xFF;
}

uint32_t Color::getColorRGB32()
{
    uint32_t color = 0;

    color |= a;
    color |= b << 8;
    color |= g << 16;
    color |= r << 24;

    return color;
}

Color Color::darkened(float p)
{
    // (Red, Green, Blue)
    //To darken the color we need to decrease the number of the RGBs color
    return Color(r-p,g-p,b-p); 
}

Color Color::lightened(float p)
{
    // (Red, Green, Blue)
    //To lighten the color we need to increase the number of the RGBs color
    return Color(r+p,g+p,b+p); 
}

Color Color::red()
{
    // (Red, Green, Blue)
    return Color(255,0,0);
}

Color Color::green()
{
    // (Red, Green, Blue)
    return Color(0,255,0);
}

Color Color::blue()
{
    // (Red, Green, Blue)
    return Color(0,0,255);
}

Color Color::yellow()
{
    // (Red, Green, Blue)
    return Color(255,255,0);
}

Color Color::white()
{
    // (Red, Green, Blue)
    return Color(255,255,255);
}

Color Color::black()
{
    // (Red, Green, Blue)
    return Color(0,0,0);
}

std::ostream& operator <<(std::ostream& os, const Color& c)
{
    
    os << "Red: " << c.r << ", Green: "<< c.g << ", Blue: " << c.b << ", Alpha: "<< c.a;;
    return os;
}

