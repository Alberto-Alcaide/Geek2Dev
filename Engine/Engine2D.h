#include <iostream> 
#include "Mouse.h"
#include "Keyboard.h"
#include "Log.h"
#include "Color.h"
#include "Graphics.h"
#include "Vec2D.h"

class Engine2D
{
private:
    bool isRunning = 0;
    double dt = 0;  // seconds
    int last_frame_time = 0; // miliseconds

public:

    Engine2D(int width, int height);
    ~Engine2D();

    // Input
    Mouse* mouse;
    Keyboard* keyboard;

    // Game loop
    bool nextFrame();
    void update();
    void checkInput();
    void render();

    // Timers
    double getDeltaTime();
    int getTotalTimeInMilliSeconds();
    double getTotalTimeInSeconds();
<<<<<<< Updated upstream
=======

    // EnTT (ECS)
    entt::registry world;
>>>>>>> Stashed changes
};