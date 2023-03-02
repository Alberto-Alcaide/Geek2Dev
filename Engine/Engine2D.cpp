#include "Engine2D.h"

Engine2D::Engine2D(int width, int height)
{
    Log::Info("Turning on Engine2D");

    // Setting core variables
    mouse = new Mouse();
    keyboard = new Keyboard();

    // Graphics initialization
    if(Graphics::createWindow(width, height))
        Log::Info("Graphics initialized");
    
    isRunning = true;
}

Engine2D::~Engine2D()
{
    Log::Info("Turning off Engine2D");

    delete mouse;
    delete keyboard;

    Graphics::closeWindow();
}

bool Engine2D::nextFrame()
{
    Graphics::cleanUpScreen();
    dt = (SDL_GetTicks() - last_frame_time) / 1000.0;
    last_frame_time = SDL_GetTicks();

    return isRunning;
}

void Engine2D::update()
{
    checkInput();
}

void Engine2D::checkInput()
{
    
    SDL_Event event;

    while (SDL_PollEvent(&event)) 
    {
        switch (event.type) 
        {

            case SDL_QUIT:
                isRunning = false;
                break;

            case SDL_MOUSEMOTION:
<<<<<<< Updated upstream
=======
            {
>>>>>>> Stashed changes
                int x = event.motion.x;
                int y = event.motion.y;
                mouse->updatePosition(x, y);
            }
                break;

            case SDL_MOUSEBUTTONDOWN:
                int x, y;
                SDL_GetMouseState(&x, &y);
                mouse->updatePosition(x, y);

                if(event.button.button == SDL_BUTTON_LEFT)
                    mouse->leftButtonPressed = true;
                if(event.button.button == SDL_BUTTON_RIGHT)
                    mouse->rightButtonPressed = true;
                break;

            case SDL_MOUSEBUTTONUP:
                if(event.button.button == SDL_BUTTON_LEFT)
                    mouse->leftButtonPressed = true;
                if(event.button.button == SDL_BUTTON_RIGHT)
                    mouse->rightButtonPressed = true;
                break;

            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE)
                    isRunning = false;
                if(event.key.keysym.sym == SDLK_UP)
                    keyboard->upKeyPressed = true;
                if(event.key.keysym.sym == SDLK_DOWN)
                    keyboard->downKeyPressed = true;
                if(event.key.keysym.sym == SDLK_RIGHT)
                    keyboard->rightKeyPressed = true;
                if(event.key.keysym.sym == SDLK_LEFT)
                    keyboard->leftKeyPressed = true;
                break;

            case SDL_KEYUP:
                if(event.key.keysym.sym == SDLK_UP)
                    keyboard->upKeyPressed = false;
                if(event.key.keysym.sym == SDLK_DOWN)
                    keyboard->downKeyPressed = false;
                if(event.key.keysym.sym == SDLK_RIGHT)
                    keyboard->rightKeyPressed = false;
                if(event.key.keysym.sym == SDLK_LEFT)
                    keyboard->leftKeyPressed = false;
                break;

            default:
                break;
        }   
    }
}

void Engine2D::render()
{
    Graphics::renderFrame();
}

double Engine2D::getDeltaTime()
{
    return dt;
}

int Engine2D::getTotalTimeInMilliSeconds()
{
    return SDL_GetTicks();
}

double Engine2D::getTotalTimeInSeconds()
{
    return SDL_GetTicks() / 1000.0;
}
