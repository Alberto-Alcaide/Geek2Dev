#ifndef GRIDMOVEMENTSYSTEM_H
#define GRIDMOVEMENTSYSTEM_H

#include <SDL2/SDL.h>
#include "entt/entt.hpp"
#include "KeyDownEvent.h" 

class GridMovementSystem
{
public:
    void OnKeyDown(KeyDownEvent& keyDown)
    {
        auto view = keyDown.world->view<TransformComponent, GridMovementComponent>();
        for (auto entity: view) 
        {
            auto& transformComp = view.get<TransformComponent>(entity);
            const auto gridComp = view.get<GridMovementComponent>(entity);
            Vec2D direction;

            switch (keyDown.symbol) 
            {
                case SDLK_UP:
                    direction = Vec2D(0, -1);
                    break;
                case SDLK_RIGHT:
                    direction = Vec2D(1, 0);
                    break;
                case SDLK_DOWN:
                    direction = Vec2D(0, 1);
                    break;
                case SDLK_LEFT:
                    direction = Vec2D(-1, 0);
                    break;
            }
            transformComp.position += direction *gridComp.stepSize;
        }
    }
};

#endif