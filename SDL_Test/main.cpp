#include <iostream>
#include <stdbool.h>
#include <SDL2/SDL.h>

SDL_Window* window=NULL;
SDL_Renderer* renderer=NULL;

bool initialize_window(int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error initializing SDL" << std::endl;
        return false;
    }

    window=SDL_CreateWindow(
        "My first window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
    if (!window)
    {
        std::cerr << "Error creating SDL window" << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    if (!renderer)
    {
        std::cerr << "Error creating SDL renderer" << std::endl;
        return false;
    }

    std::cout << "Graphics initialized" << std::endl;

    return true;
}


void draw_rectangle(SDL_Rect rectangle)
{
    //Clean the video buffer
    SDL_RenderClear(renderer);

    //Draw the rectangle on the scrren
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rectangle);

}

void destroy_window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Graphics destroyed" << std::endl;
}

void wait()
{
    SDL_Event e;
    bool quit = false;
    while(!quit)
    {
        while(SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            if (e.type == SDL_KEYDOWN)
            {
                quit = true;
            }
            
        }
    }
    return;
}




int main(int argc, char* argv[])
{
    if (initialize_window(640,400))
    {
        //Create rectangle
        SDL_Rect my_rectangle= {100, 100, 60, 20};

        //Draw the rectangle on the screen
        draw_rectangle(my_rectangle);

        //Wait a couple of seconds
        wait();

        //Destroy the window to free its memory.
        destroy_window();
    }
    return 0;
}