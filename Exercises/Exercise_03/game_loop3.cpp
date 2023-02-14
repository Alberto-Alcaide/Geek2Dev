// Delta time game loop

#include <iostream>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define FPS 30
#define FRAME_TARGET_TIME (1000 / FPS)

SDL_Window* window; // = SDL_CreateWindow("My Window", 0, 0, 800, 600, 0);
SDL_Renderer* renderer; // = SDL_CreateRenderer(window, -1, 0);
SDL_Event sdl_event;

int last_frame_time = 0;
int player_x = 0;
int player_y = 0;

bool game_running = false;


// Boots up screen
bool init_graphics(int width, int height)
{

    // boots all subsystems (timer, audio, video...etc)
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error initializing SDL" << std::endl;
        return false;
    }

    window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_CENTERED,  SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

    // CreateWindow() Returns NULL on failure so we check whether window was created
    if(!window)
    {
        std::cerr << "Error creating SDL window\n";
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(!renderer)
    {
        std::cerr << "Error creating SDL renderer\n";
        return false;
    }

    std::cout << "Graphics initializaed\n";

    return true;
}

void destroy_window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Graphics destroyed\n";
}

void process_input(bool *game_is_running)
{
    
    // Check for input. Right now we are only checking if we close app.
    SDL_PollEvent(&sdl_event);
    switch(sdl_event.type)
    {
        case SDL_QUIT:
            *game_is_running = false;
            break;
        case SDL_KEYDOWN:
            if(sdl_event.key.keysym.sym == SDLK_ESCAPE)
                *game_is_running = false;
            break;
    }
}

void update()
{
    // Find ms since last update
    int delta_time_ms = (SDL_GetTicks() - last_frame_time);
    // Convert to seconds
    float delta_time = delta_time_ms / 1000.0f;

    /*  The rule of thumb is to update all objects in the scene as a function of delta time. 
        Keep your units in seconds, not frames, and multiply by delta each frame.
        The game will run as fast as it can and objects will move correctly regardless of the FPS */

    // Update player position
    player_x += 10 * delta_time; // posicion = posicion_anterior + v*dt
    player_y += 10 * delta_time;
    
    std::cout << "Delta time: " << delta_time << std::endl;
    std::cout << "Paso por aqui " << player_x << std::endl;

    if(player_x > 640)
        player_x = 0;
    if(player_y > 400)
        player_y = 0;

    last_frame_time = SDL_GetTicks();
}

void render()
{
    // clean up screen
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);

    // Rectangle to represent the player
    SDL_Rect box = {player_x, player_y, 10, 10};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &box);

    // Swap the video buffers
    SDL_RenderPresent(renderer);
}

int main(int argc, char** argv)
{

    game_running = init_graphics(640, 400);

    // Game loop
    while(game_running)
    {
        process_input(&game_running);
        update();
        render();
    }

    destroy_window();

    return 0;
}