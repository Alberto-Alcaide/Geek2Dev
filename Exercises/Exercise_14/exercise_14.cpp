#include "Engine2D.h"

int main(int argc, char *args[])
{
    Engine2D engine(800,800);

    auto a = engine.world.create();
    engine.world.emplace<TransformComponent>(a, Vec2D(400,400));
    engine.world.emplace<KinematicsComponent>(a);
    engine.world.emplace<ColliderComponent>(a, RectangleShape(20,20, Color::blue(), true), true, false);

    auto b = engine.world.create();
    engine.world.emplace<TransformComponent>(b, Vec2D(100,100));
    engine.world.emplace<KinematicsComponent>(b);
    engine.world.emplace<ColliderComponent>(b, RectangleShape(20,20, Color::red(), true), true, false);

    while (engine.nextFrame())
    {
        engine.update();

        engine.world.get<TransformComponent>(b).position = engine.mouse->position;

        Contact contact;
        if (Collision::IsColliding(a,b,contact,engine.world))
        {
            //int x, int y, int width, int height, Color color
            //Graphics::drawFillRect(contact.start.x, contact.start.y,20,20, Color::blue());
            //Graphics::drawFillRect(contact.end.x, contact.end.y, 20,20, Color::red());
            //Graphics::drawLine(contact.start.x,contact.start.y,contact.start.x + contact.normal.x * 15, contact.start.y + contact.normal.y * 15, 0xFFFF00FF);

            //std::cout << "Depth: " << contact.depth << std::endl;

        }
        
        engine.render();
    }
    return 0;
}