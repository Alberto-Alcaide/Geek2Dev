#ifndef ANIMATIONSYSTEM_H
#define ANIMATIONSYSTEM_H

#include <SDL2/SDL.h>
#include "entt/entt.hpp"
#include "AnimationComponent.h"
#include "SpriteComponent.h"


struct AnimationSystem
{
    void Render(entt::registry& world)
    {
        auto listID = world.view<SpriteComponent, AnimationComponent>();
        for(auto id : listID)
        {
            auto& animationComp = listID.get<AnimationComponent>(id);
            auto& spriteComp = listID.get<SpriteComponent>(id);

            int currentFrame =((SDL_GetTicks() - animationComp.startTime) * animationComp.frameSpeedRate / 1000);
            int moduledCurrentFrame = currentFrame % animationComp.numFrames;

            if(currentFrame >= animationComp.numFrames && !animationComp.isLoop)
                moduledCurrentFrame = animationComp.numFrames - 1;

            animationComp.currentFrame = moduledCurrentFrame;
            // guardar animacion en animation Component, then spritecomp.texture = animatonComp.texture * currentFrame
            spriteComp.srcRect.x = animationComp.currentFrame * spriteComp.width;

        }
    }
};


#endif