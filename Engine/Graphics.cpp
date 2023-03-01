#include "Graphics.h"

void renderFrame();

bool Graphics::createWindow(int width, int height)
{
    windowWidth_ = width;
    windowHeight_ = height;

    // Compute screen resolution and allocate corresponding memory
    int resolution = windowWidth_ * windowHeight_;
    colorBuffer_ = (uint32_t*) malloc(sizeof(uint32_t) * resolution);

    // Initialize all SDL subsystems (timer, audio, video...etc), otherwise Log error
    if(SDL_Init(SDL_INIT_EVERYTHING) !=0)
    {
        Log::Error("Failed to initialize SDL.");
        return false;
    }

    // SDL_CreateWindow Returns NULL on failure so Log error if window is not created
    window_ = SDL_CreateWindow("My Window", SDL_WINDOWPOS_CENTERED,  SDL_WINDOWPOS_CENTERED, windowWidth_, windowHeight_, SDL_WINDOW_BORDERLESS);
    if(!window_)
    {
        Log::Error("Failed to create SDL window)");
    }

    // SDL_CreateRenderer returns NULL on failure so Log error if renderer is not created
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!renderer_)
    {
        Log::Error("Failed to create SDL renderer");
    }

    return true;
}

void Graphics::closeWindow()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
    Log::Info("Graphics destroyed");
}

void Graphics::cleanUpScreen(Color c = Color::black())
{
    SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer_, c.r, c.g, c.b, c.a);
    SDL_RenderClear(renderer_);
}

void Graphics::renderFrame()
{
    /*
    // que representa color_buffer_texture ?
    SDL_UpdateTexture(
        colorBufferTexture, 
        NULL, 
        colorBuffer_, 
        (int)(windowWidth_* sizeof(uint32_t))
    );

    // copy  portion of the colorBufferTexture to the rendering target.
    SDL_RenderCopy(renderer_, colorBufferTexture, NULL, NULL);

    //Clear colorBuffer
    memset(colorBuffer_, 0, windowWidth_ * windowHeight_ * sizeof(uint32_t));

    // Swap video buffer
    SDL_RenderPresent(renderer_);
    */
}

void Graphics::drawGrid(void)
{

}

void Graphics::drawPixel(int x, int y, Color color)
{
    // Check if trying to draw inside screen boundaries
    if (x >= 0 && x < windowWidth_ && y >= 0 && y < windowHeight_)
    {
        colorBuffer_[(windowWidth_ * y) + x] = color.getColorRGB32();
    }
}

void Graphics::drawLine(int x0, int y0, int x1, int y1, Color color)
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
        drawPixel(round(current_x), round(current_y), color);
        current_x += x_inc;
        current_y += y_inc;
    }
}

void drawRect(int x, int y, int width, int height, Color color);

void drawFillRect(int x, int y, int width, int height, Color color);

void drawPolygon(int x, int y, const std::vector<Vec2D>& vertices, Color color);

void Graphics::drawCircle(int x0, int y0, int radius, Color color)
{
    const int32_t diameter = (radius * 2);
    int32_t x = (radius-1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t err= (tx - diameter);

    while(x>=y)
    {
        // Each of the following renders an octant of the circle
        drawPixel(x0 + x, y0 + y, color);
        drawPixel(x0 + y, y0 + x, color);
        drawPixel(x0 - y, y0 + y, color);
        drawPixel(x0 - x, y0 + y, color);
        drawPixel(x0 - x, y0 - y, color);
        drawPixel(x0 - y, y0 - x, color);
        drawPixel(x0 + y, y0 - x, color);
        drawPixel(x0 + x, y0 - y, color);

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

void Graphics::drawFillCircle(int x0, int y0, int radius, Color color)
{
    const int32_t diameter = (radius * 2);
    int32_t x= (radius-1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t err= (tx - diameter);

    while(x>=y) 
    { 
        // Each of the following renders an octant of the circle
        drawLine(x0 + x, y0 - y, x0 + x, y0 + y, color);
        drawLine(x0 - x, y0 - y, x0 - x, y0 + y, color);
        drawLine(x0 + y, y0 - x, x0 + y, y0 + x, color);
        drawLine(x0 - y, y0 - x, x0 - y, y0 + x, color);
      

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
