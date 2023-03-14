#ifndef KINEMATICSYSTEM_H
#define KINEMATICSYSTEM_H

#include "KinematicsComponent.h"
#include "TransformComponent.h"
#include "entt/entt.hpp"

class KinematicSystem
{
public:
    void Update(const double dt, entt::registry& world)
    {
        // Collect all entities IDs in our world that have certain components. Multiple arguments in View work as AND operator. 
        auto objectsID_List = world.view<TransformComponent, KinematicsComponent>();

        // Iterate through our ID container and obtain each component to update them
        for (auto entity: objectsID_List)
        {
            // Given an ID, get a reference to each component
            auto& transform = objectsID_List.get<TransformComponent>(entity);
            auto& kinematic = objectsID_List.get<KinematicsComponent>(entity);
            
            // Update components
            kinematic.velocity += kinematic.acceleration * dt; // v = v0 + a * dt (euler)
            transform.position += kinematic.velocity * dt; // x = x0 + v * dt
        }
    }
};

#endif