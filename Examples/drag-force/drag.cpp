#include "Engine2D.h"


int main(int argc, char *args[]){
    int width = 800;
    int height = 800;
    Engine2D engine (width,height);

    Vec2D gravityForce = Vec2D(0,50);
    Vec2D dragForce = Vec2D();

    const auto particle = engine.world_.create();
    engine.world_.emplace<TransformComponent>(particle, Vec2D(width/2,50));
    engine.world_.emplace<KinematicsComponent>(particle);
    engine.world_.emplace<ParticleComponent>(particle, 1, 20, Color::red());

    auto& t = engine.world_.get<TransformComponent>(particle);
    auto& k = engine.world_.get<KinematicsComponent>(particle);
    auto& p = engine.world_.get<ParticleComponent>(particle);

    while (engine.nextFrame())
    {
        engine.update();

        p.AddForce(gravityForce);

        if (t.position.y >= height/2){
            dragForce = Force::Generate_Drag_Vector(0.1, k.velocity);
        }else{
            dragForce = Vec2D();
        }
        p.AddForce(dragForce);
        std::cout << k.velocity << " " << dragForce << std::endl;
        Graphics::drawFillRect(0, height/2, width, height, Color(14,91,158));
        Graphics::drawFillCircle(t.position.x, t.position.y, 20, Color::red());
        engine.render();
    }
    
    return 0;
}