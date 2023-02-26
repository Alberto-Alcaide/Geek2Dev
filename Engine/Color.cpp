
#include "Color.h"

Color::Color(){}

Color::Color(int r, int g, int b): r(r), g(g), b(b), a(1) {}

Color::Color(int r, int g, int b, int a): r(r), g(g), b(b), a(a){}

Color::Color(uint32_t color){
    r=color & 0xFF;
    g=(color >> 8) & 0xFF;
    b=(color >> 16) & 0xFF;
    a=(color >> 24) & 0xFF;
}

Color Color::darkened(float p)
{
    return Color(r-p,g-p,b-p); //Que pasa si es 0?
}

Color Color::lightened(float p)
{
    return Color(r+p,g+p,b+p); //Que pasa si es 255?
}

Color Color::red()
{
    return Color(255,0,0);
}
Color Color::green()
{
    return Color(0,255,0);
}
Color Color::blue()
{
    return Color(0,0,255);
}
Color Color::yellow()
{
    return Color(255,255,0);
}
Color Color::white()
{
    return Color(255,255,255);
}
Color Color::black()
{
    return Color(0,0,0);
}

std::ostream& operator <<(std::ostream& os, const Color& c)
{
    //Como expresarlo?? 0xFF es siempre al inicio o se pone para separar azul, verde, rojo, etc.
    
    
    os << "Red: " << c.r << ", Green: "<< c.g << ", Blue: " << c.b << ", Alpha: "<< c.a;;
    return os;
}

