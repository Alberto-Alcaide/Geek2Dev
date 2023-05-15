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
#include "EraseComponent.h"

class ColliderSystem
{
    public: 
        void Update(entt::dispatcher& eventBus, entt::registry& world)
        {
            
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

                        // Comprobamos que sean Brick y Ball, y llamamos al evento para eliminar el Brick

                        if ((world.get<NameGroupComponent>(entityA).group == "ball" && world.get<NameGroupComponent>(entityB).group == "brick")
                            || (world.get<NameGroupComponent>(entityA).group == "brick" && world.get<NameGroupComponent>(entityB).group == "ball"))
                            eventBus.trigger(BallHitBrickEvent{entityA,entityB,contact,world});

                       
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
            // Vemos que entidad es Brick
            if (hit.world->get<NameGroupComponent>(hit.b).group=="brick")
            {
                // Comprobar que el Brick está registrado en el world
                if (hit.world->valid(hit.b))
                {
                    
                    hit.world->emplace<EraseComponent>(hit.b); // Borramos el Brick
                    
                }
            }
            else
            {
                // Comprobar que el Brick está registrado en el world
                if (hit.world->valid(hit.a))
                {

                    hit.world->emplace<EraseComponent>(hit.a); // Borramos el Brick
                    
                }
            }
            
        }

};

#endif