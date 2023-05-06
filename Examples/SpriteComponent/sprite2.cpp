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

    SDL_Surface* surface = IMG_Load("../../assets/1_enemy.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Graphics::getRenderer(), surface);
    SDL_FreeSurface(surface);


    while(engine.nextFrame())
    {
        engine.update();


        
        

        //Graphics::drawCircle(400, 400, 50,1,Color::white());
        engine.render();
    }

    return 0;
}