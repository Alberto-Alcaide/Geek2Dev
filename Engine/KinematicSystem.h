#ifndef KINEMATICSYSTEM_H
#define KINEMATICSYSTEM_H

#include "KinematicComponent.h"
#include "TransformComponent.h"
#include "entt/entt.hpp"

class KinematicSystem
{
    public:
        void Update(const double dt, entt::registry& world)
        {
            // Recoge todas las entidades creadas en view con sus transform y kinematic
            auto view = world.view<TransformComponent, KinematicComponent>();
            // 1 Loop = 1 Entity, each loop will modify 1 entity.
            for (auto entity: view)
            {
                // We receive their current transform and kinematic
                auto& transform = view.get<TransformComponent>(entity);
                auto& kinematic = view.get<KinematicComponent>(entity);
                // Now we will update them
                kinematic.velocity += kinematic.acceleration * dt; // v = v0 + a * dt (euler)
                transform.position += kinematic.velocity * dt; // x = x0 + v * dt
            }
        }
};

#endif