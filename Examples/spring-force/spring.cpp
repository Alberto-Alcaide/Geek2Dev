#include "Engine2D.h"


int main(int argc, char *args[]){
    int width = 800;
    int height = 800;
    Engine2D engine (width,height);
    Vec2D anchor = Vec2D(width/2,200);
    float k = 2;
    float restlenght = 200;
    Vec2D gravity_force = Vec2D(0,50);
    Vec2D drag_force = Vec2D();


    const auto particle = engine.world_.create();
    engine.world_.emplace<TransformComponent>(particle, Vec2D(width/2-50,500));
    engine.world_.emplace<KinematicsComponent>(particle);
    engine.world_.emplace<ParticleComponent>(particle, 1, 10, Color::red());

    auto& t = engine.world_.get<TransformComponent>(particle);
    auto& kinematic = engine.world_.get<KinematicsComponent>(particle);s
    auto& p = engine.world_.get<ParticleComponent>(particle);

    
    while (engine.nextFrame())
    {
        engine.update();

        Vec2D spring_force = Force::generateSpringVector(t.position, anchor,restlenght, k);
        drag_force=Force::generateDragVector(0.001, kinematic.velocity);
        p.AddForce(spring_force);
        p.AddForce(gravity_force);
        p.AddForce(drag_force);
        
        Graphics::drawFillRect(0, height/2, width, height, Color(14,91,158));
        Graphics::drawLine(t.position.x, t.position.y, anchor.x, anchor.y, Color::white());
        Graphics::drawFillRect(anchor.x-15, anchor.y, 30, 10, Color::red());
        engine.render();
    }
    
    return 0;
}