#ifndef COLLIDERSYSTEM_H
#define COLLIDERSYSTEM_H

#include "Engine2D.h"
#include "ColliderComponent.h"
#include "TransformComponent.h"
#include "KinematicsComponent.h"
#include "RigidBodyComponent.h"
#include "entt/entt.hpp"
#include "Collision.h"
#include "ColliderEvent.h"



class ColliderSystem
{
    public: 
        void Update(entt::dispatcher& eventBus, entt::registry& world)
        {
            auto view = world.view<TransformComponent,KinematicsComponent,RigidBodyComponent,ColliderComponent>();

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

};

#endif