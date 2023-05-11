#ifndef RIGIDBODYSYSTEM_H
#define RIGIDBODYSYSTEM_H

#include "Graphics.h"
#include "entt/entt.hpp"
#include "KinematicsComponent.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "Log.h"

class RigidBodySystem
{
    public:
        void Update(const double dt, entt::registry& world)
        {
            Log::Info("Entro RigidBodySystem");
            auto view = world.view<KinematicsComponent, RigidBodyComponent>();


            for (auto entity: view)
            {
                auto& kinematic = view.get<KinematicsComponent>(entity);
                auto& rigidbody = view.get<RigidBodyComponent>(entity);

                kinematic.acceleration = rigidbody.sumForces * rigidbody.invMass;
                rigidbody.ClearForces();
                if (rigidbody.inertia != 0)
                {
                    kinematic.angularAcceleration = rigidbody.sumTorques * rigidbody.invInertia;
                    rigidbody.ClearTorque();
                }
            }
        }
        
        void Render(entt::registry& world)
        {
            auto view = world.view<TransformComponent, RigidBodyComponent>();
            for (auto entity: view)
            {
                const auto transform = view.get<TransformComponent>(entity);
                const auto rigidbody = view.get<RigidBodyComponent>(entity);
                rigidbody.shape->Render(transform);
            }
        }
};

#endif