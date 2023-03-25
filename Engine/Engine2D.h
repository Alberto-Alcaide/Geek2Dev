#include <iostream> 
#include "Mouse.h"
#include "Keyboard.h"
#include "Log.h"
#include "Color.h"
#include "Graphics.h"
#include "Vec2D.h"
#include "entt/entt.hpp"
#include "TransformComponent.h"
#include "KinematicSystem.h"
#include "ParticleSystem.h"
#include "RigidBodySystem.h"
#include "Force.h"
#include "CircleShape.h"


class Engine2D
{
private:
    bool isRunning_ = 0;
    double dt_ = 0;  // seconds
    int lastFrameTime_ = 0; // miliseconds

public:

    Engine2D(int width, int height);
    ~Engine2D();

    // Input
    Mouse* mouse_;
    Keyboard* keyboard_;

    // Game loop
    bool nextFrame();
    void update();
    void checkInput();
    void render();

    // Timers
    double getDeltaTime();
    int getTotalTimeInMilliSeconds();
    double getTotalTimeInSeconds();

    // EnTT (ECS)
    entt::registry world_;

    // Systems
    KinematicSystem kinematicSystem_;
    ParticleSystem particleSystem_;
    RigidBodySystem rigidbodySystem_;
};