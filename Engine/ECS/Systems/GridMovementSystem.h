#ifndef GRIDMOVEMENTSYSTEM_H
#define GRIDMOVEMENTSYSTEM_H

#include <SDL2/SDL.h>
#include "entt/entt.hpp"
#include "KeyDownEvent.h"
#include "TransformComponent.h" 
#include "GridMovementComponent.h" 
#include "NameGroupComponent.h" 

class GridMovementSystem
{
public:
    void OnKeyDown(KeyDownEvent& keyDown)
    {
        auto view = keyDown.world->view<TransformComponent, GridMovementComponent, NameGroupComponent>();
        for (auto entity: view) 
        {
            auto& transformComp = view.get<TransformComponent>(entity);
            const auto gridComp = view.get<GridMovementComponent>(entity);
            const auto& nameGroupComp = view.get<NameGroupComponent>(entity);
            
            Vec2D direction;

            if(nameGroupComp.name == "player1")
            {
                switch (keyDown.symbol) 
                {
                    case SDLK_UP:
                        direction = Vec2D(0, -1);   // up
                        break;
                    case SDLK_RIGHT:
                        direction = Vec2D(1, 0);    // right  
                        break;
                    case SDLK_DOWN:
                        direction = Vec2D(0, 1);    // down
                        break;
                    case SDLK_LEFT:
                        direction = Vec2D(-1, 0);   // left
                        break;
                }
            }

            if(nameGroupComp.name == "player2")
            {
                switch (keyDown.symbol) 
                {
                    case SDLK_w:
                        direction = Vec2D(0, -1);   // up
                        break;
                    case SDLK_d:
                        direction = Vec2D(1, 0);    // right  
                        break;
                    case SDLK_s:
                        direction = Vec2D(0, 1);    // down
                        break;
                    case SDLK_a:
                        direction = Vec2D(-1, 0);   // left
                        break;
                }
            }

            transformComp.position += direction *gridComp.stepSize;
        }
    }
};

#endif