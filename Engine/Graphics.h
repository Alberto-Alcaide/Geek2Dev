#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <stdint.h>
#include "Color.h"
#include "Log.h"
#include "Vec2D.h"
#include "vector"
#include <SDL2/SDL.h>


class Graphics
{
private:
    static int windowWidth_;
    static int windowHeight_;
    static uint32_t* colorBuffer_; // Array of pixels(uint32_t) that represent the colors of our screen
    static SDL_Window* window_;
    static SDL_Renderer* renderer_;


public:
    static bool createWindow(int width, int height);
    static void closeWindow();

    /**
     * Cleans up screen with the given color. Black is default if no color is given.
     * 
     * @param c The color to clean up the screen with.
     */
<<<<<<< Updated upstream
    static void cleanUpScreen(Color c);
=======
<<<<<<< Updated upstream
    static void cleanUpScreen(Color c = Color::black());
=======
    static void cleanUpScreen(/*Color c=Color::black()*/);
>>>>>>> Stashed changes
>>>>>>> Stashed changes
    static void renderFrame();

    static void drawGrid(void);
    static void drawPixel(int x, int y, Color color);
    static void drawLine(int x0, int y0, int x1, int y1, Color color);
    static void drawRect(int x, int y, int width, int height, Color color);
    static void drawFillRect(int x, int y, int width, int height, Color color);
    static void drawPolygon(int x, int y, const std::vector<Vec2D>& vertices, Color color);
    static void drawCircle(int x0, int y0, int radius, Color color);
    static void drawFillCircle(int x0, int y0, int radius, Color color);
};



#endif