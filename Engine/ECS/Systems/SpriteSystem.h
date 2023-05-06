#ifndef SPRITESYSTEM_H
#define SPRITESYSTEM_H

#include "Graphics.h"
#include "entt/entt.hpp"
#include "TransformComponent.h"
#include "SpriteComponent.h"

class SpriteSystem
{
public:
    void Render(entt::registry& world)
    {
        // Get IDs of actors with sprite and transform component
        auto view = world.view<TransformComponent, SpriteComponent>();

        // Iterate through those IDs
        for(auto entity: view)
        {
            // Get each component using the IDs
            const auto t = view.get<TransformComponent>(entity);
            const auto s = view.get<SpriteComponent>(entity);


            // DEBUG
            std::cout << "x: " << t.position.x << " y: " << t.position.y << std::endl;
            std::cout << "w: " << s.width << " h: " << s.height << std::endl;
            std::cout << "scale: " << t.scale.x << " scaley: " << t.scale.y << std::endl;



            Graphics::DrawSprite(s.texture, t.position, t.scale, s.width, s.height, t.rotation);
        }
    }    
};


#endif