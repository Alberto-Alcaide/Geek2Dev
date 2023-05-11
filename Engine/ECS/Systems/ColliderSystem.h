#ifndef COLLIDERSYSTEM_H
#define COLLIDERSYSTEM_H

#include "Engine2D.h"
#include "ColliderComponent.h"
#include "TransformComponent.h"
#include "KinematicsComponent.h"
#include "RigidBodyComponent.h"
#include "NameGroupComponent.h"
#include "entt/entt.hpp"
#include "Collision.h"
#include "ColliderEvent.h"
#include "BallHitBrickEvent.h"

#include <chrono>




class ColliderSystem
{
    public: 
        void Update(entt::dispatcher& eventBus, entt::registry& world)
        {
            Log::Info("Entro ColliderSystem");
            auto view = world.view<TransformComponent,KinematicsComponent,RigidBodyComponent,ColliderComponent, NameGroupComponent>();

            for (auto entity: view)
            {
                auto& collider = view.get<ColliderComponent>(entity);
                collider.isColliding = false;
            }

            for (auto entityA : view)
            {
                for (auto entityB : view)
                {
                    if (entityA == entityB)
                        break;
                    Contact contact;
                    if (Collision::IsColliding(entityA,entityB, contact, world))
                    {
                        world.get<ColliderComponent>(entityA).isColliding = true;
                        world.get<ColliderComponent>(entityB).isColliding = true;
                        Collision::ResolveCollision(entityA, entityB, contact, world);

                        if ((world.get<NameGroupComponent>(entityA).group == "ball" && world.get<NameGroupComponent>(entityB).group == "brick")
                            || (world.get<NameGroupComponent>(entityA).group == "brick" && world.get<NameGroupComponent>(entityB).group == "ball"))
                            eventBus.trigger(BallHitBrickEvent{entityA,entityB,contact,world});
                        // LLamar a un evento que sea BallHitBrickEvent.h, donde se hagan cosas (quitar vida, destruir, etc.)
                        Log::Warning("Terminado Evento");
                        //std::cout << "Entidad A: " << world.get<NameGroupComponent>(entityA).group << std::endl;
                        std::cout << "Entidad A valid: " << world.valid(entityA) << std::endl;
                        std::cout << "Entidad B valid: " << world.valid(entityB) << std::endl;
                    }
                }
            }                       
        }

        void Render(entt::registry& world)
        {
            
            auto view = world.view<TransformComponent,KinematicsComponent,ColliderComponent>();
            for (auto entity: view)
            {
                const auto collider = view.get<ColliderComponent>(entity);
                if(collider.renderCollider)
                {
                    const auto transform = view.get<TransformComponent>(entity);
                    collider.shape->Render(transform);
                }
            }
        }

        void BallHitBrick(BallHitBrickEvent& hit)
        {
            Log::Warning("Ladrillo");
            if (hit.world->get<NameGroupComponent>(hit.b).group=="brick")
            {
                if (hit.world->valid(hit.b))
                {
                    Log::Error("Destruye B");
                    //hit.world->remove<ColliderComponent,RigidBodyComponent,KinematicsComponent>(hit.b);
                    hit.world->destroy(hit.b); //Esta funcion hace que el juego deje de funcionar
                    Log::Error("Destruido B");
                }
            }
            else
            {
                if (hit.world->valid(hit.a))
                {
                    Log::Error("Destruye A");
                    //hit.world->remove<ColliderComponent,RigidBodyComponent,KinematicsComponent>(hit.a);
                    hit.world->destroy(hit.a); //Esta funcion hace que el juego deje de funcionar
                    Log::Error("Destruido A");
                }
            }

            
            
        }

};

#endif