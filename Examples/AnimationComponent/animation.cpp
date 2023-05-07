#include "Engine2D.h"


int main(int argc, char *args[])
{
    int width = 800;
    int height = 800;

    Engine2D engine (width,height);

    // Init sprites
    SDL_Texture* tankLeft = Graphics::CreateSprite("../../assets/LeftAnim.png");
    SDL_Texture* tankRight = Graphics::CreateSprite("../../assets/RightAnim.png");

    const auto tank = engine.world.create();
    engine.world.emplace<NameGroupComponent>(tank, "player1", "player1");
    engine.world.emplace<GridMovementComponent>(tank, 100);
    engine.world.emplace<TransformComponent>(tank, Vec2D(400, 400));
    engine.world.emplace<SpriteComponent>(tank, 138, 130, tankRight);
    engine.world.emplace<AnimationComponent>(tank, 3, 8, true);

      


    while(engine.nextFrame())
    {
        

        engine.update();

        if(engine.keyboard->leftKeyPressed)
        {
            auto& spriteComp = engine.world.get<SpriteComponent>(tank);
            spriteComp.texture = tankLeft;
        }

        if(engine.keyboard->rightKeyPressed)
        {
            auto& spriteComp = engine.world.get<SpriteComponent>(tank);
            spriteComp.texture = tankRight;
        }
        
        engine.render();
        
    }

    SDL_DestroyTexture(tankLeft);
    SDL_DestroyTexture(tankRight);

    return 0;
}