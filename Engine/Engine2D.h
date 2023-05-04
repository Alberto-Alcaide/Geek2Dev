#ifndef ENGINE2D_H
#define ENGINE2D_H

#include <iostream> 
#include "Mouse.h"
#include "Keyboard.h"
#include "Log.h"
#include "Color.h"
#include "Graphics.h"
#include "Vec2D.h"
#include "entt/entt.hpp"


#include "Force.h"

//Shape
#include "Shape.h"
#include "CircleShape.h"
#include "PolygonShape.h"
#include "RectangleShape.h"

//Component
#include "TransformComponent.h"
#include "GridMovementComponent.h"
#include "NameGroupComponent.h"

//System (include components)
#include "KinematicSystem.h"
#include "ParticleSystem.h"
#include "RigidBodySystem.h"
#include "ColliderSystem.h"
#include "GridMovementSystem.h"
#include "ScriptSystem.h"

//Events
#include "KeyDownEvent.h"
#include "ColiderEvent.h"



class Engine2D
{
private:
    bool isRunning = 0;
    double dt = 0;  // seconds
    int lastFrameTime = 0; // miliseconds

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

    // EnTT (ECS)
    entt::registry world;
    entt::dispatcher eventBus;

    // Systems
    KinematicSystem kinematicSystem;
    ParticleSystem particleSystem;
    RigidBodySystem rigidbodySystem;
    GridMovementSystem gridSystem;
    ColliderSystem colliderSystem;
    ScriptSystem scriptSystem;
};

#endif