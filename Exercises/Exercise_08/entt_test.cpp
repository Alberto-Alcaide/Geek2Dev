#include "Engine2D.h"



int main(int argc, char *args[])
{
    // Initialize game engine
    Engine2D engine(850, 650);
    

    // Entities initialization

    const auto ball = engine.world.create();
    engine.world.emplace<Transform>(ball, Vec2D(100,100));
    const auto ball2 = engine.world.create();
    engine.world.emplace<Transform>(ball2, Vec2D(200,100));
    int radius=10;


    while (engine.nextFrame())
    {
        engine.update();

        // Code of the game
        auto view = engine.world.view<Transform>();
        for (auto entity: view)
        {
            auto& transform = view.get<Transform>(entity);

            //Ball 1 and 2 positions
            Log::Info("Ball position: ("
                + std::to_string(transform.position.x)
                + ", "
                + std::to_string(transform.position.y)
                + ")"
            );

            //Drawing both of the circles
            Graphics::drawFillCircle(transform.position.x,transform.position.y,radius,Color::green());
            transform.position += Vec2D( 0.5, 0.7);
        }

        engine.render();
        
    }
    engine.~Engine2D();

    return 0;

}