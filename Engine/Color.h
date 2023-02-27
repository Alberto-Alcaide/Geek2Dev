#ifndef Color_H
#define Color_H

#include <stdint.h>
#include <iostream>

struct Color
{
    unsigned int r; //Red
    unsigned int g; //Green
    unsigned int b; //Blue
    unsigned int a; //Alpha (opacity)

    //Constructors
    Color();
    Color(int r, int g, int b); 
    Color(int r, int g, int b, int a);
    Color(uint32_t color);
    
    ~Color()=default;

    //Functions

    Color darkened(float p); //This makes RGB - p, so R-p, G-p, B-p
    Color lightened(float p); //This makes RGB + p, so R+p, G+p, B+p

    static Color red(); //Color red: (255,0,0)
    static Color green(); //Color green: (0,255,0)
    static Color blue(); //Color blue: (0,0,255)
    static Color yellow(); //Color yellow: (255,255,0)
    static Color white(); //Color white: (255,255,255)
    static Color black(); //Color black: (0,0,0)

    //overload operator

    //Shows how the Color struct will show its variables. For Example: Red: 255, Green: 0, Blue: 0, Alpha: 1
    friend std::ostream& operator <<(std::ostream& os, const Color& c); 

};



#endif
