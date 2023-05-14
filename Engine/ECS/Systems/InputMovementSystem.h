#ifndef INPUTMOVEMENTSYSTEM_H
#define INPUTMOVEMENTSYSTEM_H

#include <SDL2/SDL.h>
#include "entt/entt.hpp"
#include "KeyDownEvent.h"
#include "KeyUpEvent.h"
#include "TransformComponent.h" 
#include "InputMovementComponent.h" 
#include "NameGroupComponent.h" 
#include "RigidBodyComponent.h"
#include "KinematicsComponent.h"

class InputMovementSystem
{
public:
    void OnKeyDown(KeyDownEvent& keyDown)
    {
        
        // Look for actors with these Components
        auto view = keyDown.world->view<InputMovementComponent, KinematicsComponent>();

        // Iterate through them
        for (auto entity: view) 
        {
            // Get components
            const auto& inputMovementComp = view.get<InputMovementComponent>(entity);
            auto& kinematicsComp = view.get<KinematicsComponent>(entity);


            switch (keyDown.symbol) 
            {
                case SDLK_LEFT:
                    kinematicsComp.velocity.x = -inputMovementComp.xVelocity;
                    break;

                case SDLK_RIGHT:
                    kinematicsComp.velocity.x = inputMovementComp.xVelocity; 
                    break;
            }
        }
        
    }


    void OnKeyUp(KeyUpEvent& keyUp)
    {
        
         // Look for actors with these Components
        auto view = keyUp.world->view<InputMovementComponent, KinematicsComponent>();

        // Iterate through them
        for (auto entity: view) 
        {
            // Get components
            const auto& inputMovementComp = view.get<InputMovementComponent>(entity);
            auto& kinematicsComp = view.get<KinematicsComponent>(entity);
            
            switch (keyUp.symbol)
            {
                case SDLK_LEFT:

                    // Avoid having 0 velocity if the opposite key is currently down
                    if (!keyUp.keyboard.isRightPressed && kinematicsComp.velocity.x < 0) {
                        kinematicsComp.velocity.x = 0;
                    }
                    // Ensure movement in positive x direction when order: leftPressed, RightPressed, leftReleased
                    else if (keyUp.keyboard.isRightPressed && kinematicsComp.velocity.x < 0)
                       kinematicsComp.velocity.x = inputMovementComp.xVelocity;
                    
                    break;

                case SDLK_RIGHT:

                    if (!keyUp.keyboard.isLeftPressed && kinematicsComp.velocity.x > 0) {
                        kinematicsComp.velocity.x = 0;
                    }
                    else if (keyUp.keyboard.isLeftPressed && kinematicsComp.velocity.x > 0)
                        kinematicsComp.velocity.x = -inputMovementComp.xVelocity;
                    
                    break;
            }
        }
        
    }
};

#endif