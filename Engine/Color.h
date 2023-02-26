#ifndef Color_H
#define Color_H

#include <stdint.h>
#include <iostream>

struct Color
{
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;

    Color();
    Color(int r, int g, int b); //Que se hace con alfa??
    Color(int r, int g, int b, int a);
    Color(uint32_t color);

    Color darkened(float p);
    Color lightened(float p);

    static Color red();
    static Color green();
    static Color blue();
    static Color yellow();
    static Color white();
    static Color black();

    friend std::ostream& operator <<(std::ostream& os, const Color& c);

};



#endif
