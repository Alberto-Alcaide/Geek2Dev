#include "Engine2D.h"


int main(int argc, char *args[])
{
    int width = 800;
    int height = 800;

    Engine2D engine (width,height);

    // Init sprites
    SDL_Texture* monsterSprite = Graphics::CreateSprite("../../assets/1_enemy.png");

    const auto monster = engine.world.create();
    engine.world.emplace<TransformComponent>(monster, Vec2D(400, 400));
    engine.world.emplace<SpriteComponent>(monster, 85, 69, monsterSprite);

      


    while(engine.nextFrame())
    {
        engine.update();

        auto& monsterTransform = engine.world.get<TransformComponent>(monster);
        
        // Rotate monster
        monsterTransform.rotation += 1;

        // Scale Monster
        monsterTransform.scale = Vec2D(2, 2) * sin(engine.getTotalTimeInMilliSeconds() * 0.001);

        engine.render();
    }

    SDL_DestroyTexture(monsterSprite);

    return 0;
}