#include "Engine2D.h"

Engine2D::Engine2D(int width, int height)
{
    Log::Info("Turning on Engine2D");

    // Setting core variables
    mouse_ = new Mouse();
    keyboard_ = new Keyboard();

    // Graphics initialization
    if(Graphics::createWindow(width, height))
        Log::Info("Graphics initialized");
    
    isRunning_ = true;
}

Engine2D::~Engine2D()
{
    Log::Info("Turning off Engine2D");

    delete mouse_;
    delete keyboard_;

    Graphics::closeWindow();
}

bool Engine2D::nextFrame()
{
    Graphics::cleanUpScreen();
    dt_ = (SDL_GetTicks() - lastFrameTime_) / 1000.0;
    lastFrameTime_ = SDL_GetTicks();

    return isRunning_;
}

void Engine2D::update()
{
    
    checkInput();

    //ask all systems to update
    particleSystem_.Update(dt_,world_);
    kinematicSystem_.Update(dt_, world_);
    
}

void Engine2D::checkInput()
{
    
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) 
    {
        
        switch (event.type) 
        {

            case SDL_QUIT:
                isRunning_ = false;
                break;

            case SDL_MOUSEMOTION:
            {

                int x = event.motion.x;
                int y = event.motion.y;

                mouse_->updatePosition(x, y);
            }
                break;

            case SDL_MOUSEBUTTONDOWN:
                int x, y;
                SDL_GetMouseState(&x, &y);
                mouse_->updatePosition(x, y);

                if(event.button.button == SDL_BUTTON_LEFT)
                    mouse_->leftButtonPressed = true;
                if(event.button.button == SDL_BUTTON_RIGHT)
                    mouse_->rightButtonPressed = true;
                break;

            case SDL_MOUSEBUTTONUP:
                if(event.button.button == SDL_BUTTON_LEFT)
                    mouse_->leftButtonPressed = true;
                if(event.button.button == SDL_BUTTON_RIGHT)
                    mouse_->rightButtonPressed = true;
                break;

            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE)
                    isRunning_ = false;
                if(event.key.keysym.sym == SDLK_UP)
                    keyboard_->upKeyPressed = true;
                if(event.key.keysym.sym == SDLK_DOWN)
                    keyboard_->downKeyPressed = true;
                if(event.key.keysym.sym == SDLK_RIGHT)
                    keyboard_->rightKeyPressed = true;
                if(event.key.keysym.sym == SDLK_LEFT)
                    keyboard_->leftKeyPressed = true;
                break;

            case SDL_KEYUP:
                if(event.key.keysym.sym == SDLK_UP)
                    keyboard_->upKeyPressed = false;
                if(event.key.keysym.sym == SDLK_DOWN)
                    keyboard_->downKeyPressed = false;
                if(event.key.keysym.sym == SDLK_RIGHT)
                    keyboard_->rightKeyPressed = false;
                if(event.key.keysym.sym == SDLK_LEFT)
                    keyboard_->leftKeyPressed = false;
                break;

            default:
                break;
        }   
    }
}

void Engine2D::render()
{
    kinematicSystem_.Render(world_);
    particleSystem_.Render(world_);
    Graphics::renderFrame();
}

double Engine2D::getDeltaTime()
{
    return dt_;
}

int Engine2D::getTotalTimeInMilliSeconds()
{
    return SDL_GetTicks();
}

double Engine2D::getTotalTimeInSeconds()
{
    return SDL_GetTicks() / 1000.0;
}
