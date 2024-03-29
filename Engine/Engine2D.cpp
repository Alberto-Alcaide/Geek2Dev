#include "Engine2D.h"

Engine2D::Engine2D(int width, int height)
{
    Log::Info("Turning on Engine2D");

    // Graphics initialization
    if(Graphics::createWindow(width, height))
        Log::Info("Graphics initialized");

    //Initialize SDL_mixer
    if(Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        Log::Error("SDL_mixer couldn't be initialized");  
    }

    // Perform the subscription of the events for all system
    eventBus.sink<KeyDownEvent>().connect<&GridMovementSystem::OnKeyDown>(gridSystem);  // subscribe GridMovementSystem to KeyDownEvents
    eventBus.sink<KeyDownEvent>().connect<&InputMovementSystem::OnKeyDown>(inputMovementSystem);
    eventBus.sink<KeyUpEvent>().connect<&InputMovementSystem::OnKeyUp>(inputMovementSystem); 
    eventBus.sink<BallHitBrickEvent>().connect<&ColliderSystem::BallHitBrick>(colliderSystem);

    isRunning = true;
}

Engine2D::~Engine2D()
{
    Log::Info("Turning off Engine2D");


    Graphics::closeWindow();
}

bool Engine2D::nextFrame()
{
    Graphics::cleanUpScreen();
    dt = (SDL_GetTicks() - lastFrameTime) / 1000.0;
    lastFrameTime = SDL_GetTicks();

    return isRunning;
}

void Engine2D::update()
{
    
    checkInput();

    // Run all systems 
    rigidbodySystem.Update(dt, world);
    particleSystem.Update(dt, world);
    kinematicSystem.Update(dt, world);  
    scriptSystem.Update(dt,0,world);
    colliderSystem.Update(eventBus,world);
    eraseSystem.Update(world);
}

void Engine2D::checkInput()
{
    
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                isRunning = false;
                break;

            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE)
                        isRunning = false;

                switch (event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        keyboard.isRightPressed = true;
                        break;
                    case SDLK_LEFT:
                        keyboard.isLeftPressed = true;
                        break;
                    default:
                        break;
                }
                eventBus.trigger(KeyDownEvent(event.key.keysym.sym, keyboard, world));
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        keyboard.isRightPressed = false;
                        break;
                    case SDLK_LEFT:
                        keyboard.isLeftPressed = false;
                    default:
                        break;
                }
                eventBus.trigger(KeyUpEvent(event.key.keysym.sym, keyboard, world));
                break;

            case SDL_MOUSEMOTION:
                {
                    int x = event.motion.x;
                    int y = event.motion.y;

                    mouse.updatePosition(x, y);
                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                int x, y;
                SDL_GetMouseState(&x, &y);
                mouse.updatePosition(x, y);

                if(event.button.button == SDL_BUTTON_LEFT)
                    mouse.leftButtonPressed = true;
                if(event.button.button == SDL_BUTTON_RIGHT)
                    mouse.rightButtonPressed = true;
                break;

            case SDL_MOUSEBUTTONUP:
                if(event.button.button == SDL_BUTTON_LEFT)
                    mouse.leftButtonPressed = true;
                if(event.button.button == SDL_BUTTON_RIGHT)
                    mouse.rightButtonPressed = true;
                break;

            default:
                break;
        }
    }
  /*  
    while (SDL_PollEvent(&event)) 
    {
        
        switch (event.type) 
        {

            case SDL_QUIT:
                isRunning = false;
                break;

            case SDL_MOUSEMOTION:
            {

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
    */
}

void Engine2D::render()
{
    
    particleSystem.Render(world);
    rigidbodySystem.Render(world);
    
    
    spriteSystem.Render(world);
    animationSystem.Render(world);

    colliderSystem.Render(world);

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
