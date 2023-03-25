#include "Engine2D.h"


int main(int argc, char *args[]){
    int width = 800;
    int height = 800;
    Engine2D engine (width,height);
    Vec2D anchor = Vec2D(width/2,200);
    float k = 20;
    float restlenght = 200;
    Vec2D gravity_force = Vec2D(0,0);
    Vec2D drag_force = Vec2D();
    Vec2D spring_force = Vec2D();


    const auto particle1 = engine.world_.create();
    engine.world_.emplace<TransformComponent>(particle1, Vec2D(width/2,390));
    engine.world_.emplace<KinematicsComponent>(particle1);
    engine.world_.emplace<ParticleComponent>(particle1, 1, 10, Color::red());
    const auto particle2 = engine.world_.create();
    engine.world_.emplace<TransformComponent>(particle2, Vec2D(width/2,490));
    engine.world_.emplace<KinematicsComponent>(particle2);
    engine.world_.emplace<ParticleComponent>(particle2, 1, 10, Color::red());
    const auto particle3 = engine.world_.create();
    engine.world_.emplace<TransformComponent>(particle3, Vec2D(width/2,590));
    engine.world_.emplace<KinematicsComponent>(particle3);
    engine.world_.emplace<ParticleComponent>(particle3, 1, 10, Color::red());
    const auto particle4 = engine.world_.create();
    engine.world_.emplace<TransformComponent>(particle4, Vec2D(width/2,690));
    engine.world_.emplace<KinematicsComponent>(particle4);
    engine.world_.emplace<ParticleComponent>(particle4, 1, 10, Color::red());
    const auto particle5 = engine.world_.create();
    engine.world_.emplace<TransformComponent>(particle5, Vec2D(width/2,790));
    engine.world_.emplace<KinematicsComponent>(particle5);
    engine.world_.emplace<ParticleComponent>(particle5, 1, 10, Color::red());

    auto& t1 = engine.world_.get<TransformComponent>(particle1);
    auto& t2 = engine.world_.get<TransformComponent>(particle2);
    auto& t3 = engine.world_.get<TransformComponent>(particle3);
    auto& t4 = engine.world_.get<TransformComponent>(particle4);
    auto& t5 = engine.world_.get<TransformComponent>(particle5);

    auto& kinematic1 = engine.world_.get<KinematicsComponent>(particle1);
    auto& kinematic2 = engine.world_.get<KinematicsComponent>(particle2);
    auto& kinematic3 = engine.world_.get<KinematicsComponent>(particle3);
    auto& kinematic4 = engine.world_.get<KinematicsComponent>(particle4);
    auto& kinematic5 = engine.world_.get<KinematicsComponent>(particle5);

    auto& p1 = engine.world_.get<ParticleComponent>(particle1);
    auto& p2 = engine.world_.get<ParticleComponent>(particle2);
    auto& p3 = engine.world_.get<ParticleComponent>(particle3);
    auto& p4 = engine.world_.get<ParticleComponent>(particle4);
    auto& p5 = engine.world_.get<ParticleComponent>(particle5);

    
    while (engine.nextFrame())
    {
        engine.update();

        spring_force = Force::generateSpringVector(t1.position, anchor,restlenght, k);
        //drag_force=Force::generateDragVector(0.001, kinematic.velocity);
        p1.AddForce(spring_force);
        p1.AddForce(gravity_force);
        p1.AddForce(drag_force);

        spring_force = Force::generateSpringVector(t2.position, t1.position,restlenght-100, k);
        p2.AddForce(spring_force);
        p2.AddForce(gravity_force);
        p2.AddForce(drag_force);

        spring_force = Force::generateSpringVector(t3.position, t2.position,restlenght-100, k);
        p3.AddForce(spring_force);
        p3.AddForce(gravity_force);
        p3.AddForce(drag_force);

        spring_force = Force::generateSpringVector(t4.position, t3.position,restlenght-100, k);
        p4.AddForce(spring_force);
        p4.AddForce(gravity_force);
        p4.AddForce(drag_force);

        spring_force = Force::generateSpringVector(t5.position, t4.position,restlenght-100, k);
        p5.AddForce(spring_force);
        p5.AddForce(gravity_force);
        p5.AddForce(drag_force);
        
        Graphics::drawFillRect(0, height/2, width, height, Color(14,91,158));

        Graphics::drawLine(t1.position.x, t1.position.y, anchor.x, anchor.y, Color::white());
        Graphics::drawLine(t2.position.x, t2.position.y, t1.position.x, t1.position.y, Color::white());
        Graphics::drawLine(t3.position.x, t3.position.y, t2.position.x, t2.position.y, Color::white());
        Graphics::drawLine(t4.position.x, t4.position.y, t3.position.x, t3.position.y, Color::white());
        Graphics::drawLine(t5.position.x, t5.position.y, t4.position.x, t4.position.y, Color::red());
        Graphics::drawFillRect(anchor.x-15, anchor.y, 30, 10, Color::red());
        engine.render();
    }
    
    return 0;
}