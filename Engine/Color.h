#ifndef Color_H
#define Color_H

#include <stdint.h>
#include <iostream>

struct Color
{
    unsigned int r; 
    unsigned int g; 
    unsigned int b; 
    unsigned int a; //Alpha (opacity)

    //Constructors
    Color();
    Color(int r, int g, int b); 
    Color(int r, int g, int b, int a);
    Color(uint32_t color);
    
    ~Color()=default;

    //Functions
    uint32_t getColorRGB32();

    Color darkened(float p); //This makes RGB - p, so R-p, G-p, B-p -
    Color lightened(float p); //This makes RGB + p, so R+p, G+p, B+p

    //Color red: (255,0,0,1)
    static Color red(); 
    //Color green: (0,255,0)
    static Color green();
    //Color blue: (0,0,255) 
    static Color blue(); 
    //Color yellow: (255,255,0)
    static Color yellow();
    //Color white: (255,255,255) 
    static Color white(); 
    //Color black: (0,0,0)
    static Color black(); 

    //overload operator

    //Shows how the Color struct will show its variables. For Example: Red: 255, Green: 0, Blue: 0, Alpha: 1
    friend std::ostream& operator <<(std::ostream& os, const Color& c); 

};



#endif
