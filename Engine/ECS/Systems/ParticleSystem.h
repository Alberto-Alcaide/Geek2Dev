#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "entt/entt.hpp"
#include "KinematicsComponent.h"
#include "ParticleComponent.h"
#include "TransformComponent.h"

class ParticleSystem
{
    public:

        // Finds objects with ParticleComponent and KinematicsComponent and updates their acceleration
        void Update(const double dt, entt::registry& world)
        {
            // Collect all entities IDs in our world that have certain components
            auto objectsID_List = world.view<KinematicsComponent, ParticleComponent>();

            // Iterate through our ID container and obtain each component to update them
            for (auto entity: objectsID_List)
            {
                // Given an ID, get a reference to each component
                auto& kinematic = objectsID_List.get<KinematicsComponent>(entity);
                auto& rb= objectsID_List.get<ParticleComponent>(entity);

                // Update 
                kinematic.acceleration = rb.sumForces * rb.invMass;
                rb.ClearForces();
            }
        }

        // Finds objects with ParticleComponent and TransformComponent and adds them to the buffer to be rendered
        void Render(entt::registry& world)
        {
            // Find list of objects with specific components
            auto view= world.view<TransformComponent, ParticleComponent>();

            // Loop through that list of objets
            for (auto entity: view)
            {
                // For each, find their components
                const auto& transform = view.get<TransformComponent>(entity);
                const auto& particle = view.get<ParticleComponent>(entity);

                // Add circle to buffer to be rendered
                Graphics::drawFillCircle(transform.position.x, transform.position.y, particle.radius, particle.color);
            }
        }
};


#endif