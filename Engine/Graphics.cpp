#include "Graphics.h"


SDL_Window* Graphics::window_=NULL;
SDL_Renderer* Graphics::renderer_=NULL;
int Graphics::windowWidth_ =0;
int Graphics::windowHeight_=0;
//uint32_t* Graphics::colorBuffer_=NULL;




int Graphics::getWindowWidth()
{
    return windowWidth_;
}

int Graphics::getWindowHeight()
{
    return windowHeight_;
}

bool Graphics::createWindow(int width, int height)
{
    windowWidth_ = width;
    windowHeight_ = height;

/*
    // Compute screen resolution and allocate corresponding memory
    int resolution = windowWidth_ * windowHeight_;
    colorBuffer_ = (uint32_t*) malloc(sizeof(uint32_t) * resolution);
*/

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
    Log::Info("Windows opened!");
    return true;
}

void Graphics::closeWindow()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
    Log::Info("Graphics destroyed");
}

void Graphics::cleanUpScreen(/*Color c=Color::black()*/)
{
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);
}

void Graphics::renderFrame()
{

    SDL_RenderPresent(renderer_);


    // How we would do it with colorBuffer_
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


void Graphics::drawGrid(int gridSize)
{
    Color color(224, 224, 224);

    // Calculates number of rows and columns
    int rows = windowHeight_ / gridSize;
    int columns = windowWidth_ / gridSize;

    // Draw horizontal lines
    for(int i=1; i< rows; i++)
    {
        drawLine(0, i*gridSize, windowWidth_, i*gridSize, color);
    }

    // Draw vertical lines
    for(int j=1; j<columns; j++)
    {
        drawLine(j*gridSize, 0, j*gridSize, windowHeight_, color);
    }
}

void Graphics::drawPixel(int x, int y, Color color)
{

    SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(renderer_, x, y);

    /*
    // Check if trying to draw inside screen boundaries
    if (x >= 0 && x < windowWidth_ && y >= 0 && y < windowHeight_)
    {
        colorBuffer_[(windowWidth_ * y) + x] = color.getColorRGB32();
    }
    */
}

void Graphics::drawLine(int x0, int y0, int x1, int y1, Color color)
{
    

    
    SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer_, x0, y0, x1, y1);
    

   /*
    int delta_x = (x1 - x0);
    int delta_y = (y1 - y0);

    int longest_side_lenght = (abs(delta_x) >= abs(delta_y)) ? abs(delta_x) : abs(delta_y);

    int x_inc = delta_x / (float)longest_side_lenght;
    int y_inc = delta_y / (float)longest_side_lenght;

    float current_x = x0;
    float current_y = y0;

    for(int i=0; i<= longest_side_lenght; i++)
    {
        drawPixel(round(current_x), round(current_y), color);
        current_x += x_inc;
        current_y += y_inc;
    }
    */
}

void Graphics::drawRect(int x, int y, int width, int height, Color color)
{
    int x2 = x + width - 1; // Get the position of the second vertex on the X axis
    int y2 = y + height -1; // Get the position o fthe second vertex on the Y axis

    drawLine(x,y,x2,y,color); // Top of Rectangle
    drawLine(x,y2,x2,y2,color); // Bottom of Rectangle
    drawLine(x,y,x,y2,color); // Left of Rectangle
    drawLine(x2,y,x2,y2,color); // Right of Rectangle

}

void Graphics::drawRotatedRect(const std::vector<Vec2D>& vertices, Color color)
{
    //std::cout << vertices[0].x << " " <<  vertices[0].y << " " << vertices[1].x << " " << vertices[1].y << std::endl;

    // order of vertices[]: top-left[0], top-right[1], bottom-left[2], bottom-right[3]
    drawLine(vertices[0].x, vertices[0].y, vertices[1].x, vertices[1].y, color); // Top of Rectangle
    drawLine(vertices[2].x, vertices[2].y, vertices[3].x, vertices[3].y, color); // Bottom of Rectangle
    drawLine(vertices[0].x, vertices[0].y, vertices[2].x, vertices[2].y, color); // Left of Rectangle
    drawLine(vertices[1].x, vertices[1].y, vertices[3].x, vertices[3].y, color); // Right of Rectangle
}


// TODO does not work yet
void Graphics::drawRotatedFillRect(const std::vector<Vec2D>& vertices, Color color)
{
    // order of vertices[]: top-left[0], top-right[1], bottom-left[2], bottom-right[3]
    drawLine(vertices[0].x, vertices[0].y, vertices[1].x, vertices[1].y, color); // Top of Rectangle
    drawLine(vertices[2].x, vertices[2].y, vertices[3].x, vertices[3].y, color); // Bottom of Rectangle
    drawLine(vertices[0].x, vertices[0].y, vertices[2].x, vertices[2].y, color); // Left of Rectangle
    drawLine(vertices[1].x, vertices[1].y, vertices[3].x, vertices[3].y, color); // Right of Rectangle
/*
    int y1 = vertices[0].y;
    int y2 = vertices[2].y;
    int x1 = vertices[0].x;
    int x2 = vertices[0].x;

    // Fill the rectangle with color
    for (int y = aux + 1; y < y2; y++)
    {
        drawLine(x1 + 1, y, x2 - 1, y, color);
        aux=y;
    }
    
    
    int delta_x = (x2 - x1);
    int delta_y = (y2 - y1);

    int longest_side_lenght = (abs(delta_x) >= abs(delta_y)) ? abs(delta_x) : abs(delta_y);

    int x_inc = delta_x / (float)longest_side_lenght;
    int y_inc = delta_y / (float)longest_side_lenght;

    //float current_x = x1;
    //float current_y = y1;
    
    for(int i=0; i<= longest_side_lenght; i++)
    {   
    std::cout << "longest_side_length:  " << longest_side_lenght << std::endl;
        std::cout << "x: " << x1+x_inc << " y: " << y1+y_inc << std::endl;
        drawLine(x1+x_inc, y1+x_inc, x2+x_inc, y2 + x_inc, color);
        //drawPixel(round(current_x), round(current_y), color);
        x_inc += x_inc;
        y_inc += y_inc;
    }
    */
}

void Graphics::drawFillRect(int x, int y, int width, int height, Color color)
{
    int x2 = x + width - 1; // Get the position of the second vertex on the X axis
    int y2 = y + height -1; // Get the position o fthe second vertex on the Y axis
    int aux=y;

    drawLine(x,y,x2,y,color); // Top of Rectangle
    drawLine(x,y2,x2,y2,color); // Bottom of Rectangle
    drawLine(x,y,x,y2,color); // Left of Rectangle
    drawLine(x2,y,x2,y2,color); // Right of Rectangle

    // Fill the rectangle with color
    for (int y = aux + 1; y < y2; y++)
    {
        drawLine(x + 1, y, x2 - 1, y, color);
        aux=y;
    }

}

void drawPolygon(int x, int y, const std::vector<Vec2D>& vertices, Color color);

void Graphics::drawCircle(int x0, int y0, int radius, double rotation, Color color)
{
    const int32_t diameter = (radius * 2);

    int32_t x = (radius-1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t err= (tx - diameter);

    int32_t rotationx=radius*cos(rotation);
    int32_t rotationy=radius*sin(rotation);

    while(x>=y)
    {
        // Draw a line to be able to see rotation of circle
        drawLine(x0, y0, x0 + rotationx, y0 + rotationy, color);
        
        // Each of the following renders an octant of the circle
        drawPixel(x0 + x, y0 - y, color);
        drawPixel(x0 + x, y0 + y, color);

        drawPixel(x0 - x, y0 - y, color);
        drawPixel(x0 - x, y0 + y, color);

        drawPixel(x0 + y, y0 - x, color);
        drawPixel(x0 + y, y0 + x, color);

        drawPixel(x0 - y, y0 - x, color);
        drawPixel(x0 - y, y0 + x, color);


        //drawPixel(x0 - y, y0 + y, color); // esto pinta un radio???

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

SDL_Texture* Graphics::CreateSprite(const char* path)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer_, path);
/*
    SDL_Surface* surface = IMG_Load(path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer_, surface);
    SDL_FreeSurface(surface);
*/


    if (!texture) 
    {
        std::string error = "Couldn't load " + std::string(path) + ": " + SDL_GetError();
		Log::Error(error);
		return nullptr;
	}

    return texture;
}

void Graphics::DrawSprite(SDL_Texture* texture, Vec2D position, Vec2D scale, int width, int height, float rotation)
{
    // Set the source rectangle of our original sprite texture
    SDL_Rect srcRect = {
        0,
        0,
        width,
        height
    };

    // Set the destination rectangle with the x,y position to be rendered
    SDL_Rect dstRect =  {
        static_cast<int>(position.x),
        static_cast<int>(position.y),
        static_cast<int>(width * scale.x),
        static_cast<int>(height * scale.y)
    };

   // SDL_RenderCopy(renderer_, texture, NULL,&srcRect);


    // Draw the texture on the destination renderer or print error when failed
    if(SDL_RenderCopyEx(renderer_, texture, &srcRect, &dstRect, rotation, NULL, SDL_FLIP_NONE) != 0)
    {
        std::cout << "Error rendering sprite" << SDL_GetError() << std::endl;
    }

}

