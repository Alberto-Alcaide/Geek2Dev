#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <stdint.h>
#include <cmath>
#include "Color.h"
#include "Log.h"
#include "Vec2D.h"
#include "vector"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "TransformComponent.h"


class Graphics
{
private:
    static int windowWidth_;
    static int windowHeight_;
    static SDL_Window* window_;
    static SDL_Renderer* renderer_;
    //static uint32_t* colorBuffer_; // Array of pixels(uint32_t) that represent the colors of our screen


public:

    static int getWindowWidth();
    static int getWindowHeight();
    static SDL_Renderer* getRenderer() {return renderer_;};

    static bool createWindow(int width, int height);
    static void closeWindow();

    /**
     * Cleans up screen with the given color. Black is default if no color is given.
     * 
     * @param c The color to clean up the screen with.
     */
    static void cleanUpScreen(/*Color c=Color::black()*/);
    static void renderFrame();

    static void drawGrid(int gridSize);
    static void drawPixel(int x, int y, Color color);
    static void drawLine(int x0, int y0, int x1, int y1, Color color);

    static void drawRect(int x, int y, int width, int height, Color color);
    static void drawRotatedRect(const std::vector<Vec2D>& vertices, Color color);
    static void drawFillRect(int x, int y, int width, int height, Color color);
    static void drawRotatedFillRect(const std::vector<Vec2D>& vertices, Color color);

    static void drawPolygon(int x, int y, const std::vector<Vec2D>& vertices, Color color);
    static void drawCircle(int x0, int y0, int radius, double rotation, Color color);
    static void drawFillCircle(int x0, int y0, int radius, Color color);

    static SDL_Texture* CreateSprite(const char* path);
    static void DrawSprite(SDL_Texture* texture, Vec2D position, Vec2D scale, int width, int height, float rotation, SDL_Rect _srcRect);
};



#endif