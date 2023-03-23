#ifndef KINEMATICSYSTEM_H
#define KINEMATICSYSTEM_H

#include "RigidBodyComponent.h"
#include "KinematicsComponent.h"
#include "TransformComponent.h"
#include "entt/entt.hpp"
/*
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
            
            // Update components using euler method (x(n+1) = x(n) + dx * dt)
            kinematic.velocity += kinematic.acceleration * dt; 
            transform.position += kinematic.velocity * dt; 
        }
    }
};
*/
class KinematicSystem
{
    public: 
        void Update(const double dt, entt::registry& world)
        {
            auto view = world.view<TransformComponent, KinematicsComponent>();
            // Loop all entities that the system is interested in
            for (auto entity: view)
            {
                auto& transform = view.get<TransformComponent>(entity);
                auto& kinematics = view.get<KinematicsComponent>(entity);

                // Integrate linear motion
                kinematics.velocity += kinematics.acceleration * dt;
                transform.position += kinematics.velocity * dt;

                // Integrate angular motion
                kinematics.angularVelocity += kinematics.angularAcceleration * dt;
                transform.rotation += kinematics.angularVelocity * dt;

                // We need to update the vertices of the Shape
                /*
                if (world.all_of<RigidBodyComponent>(entity))
                {
                    Shape* shape;
                    shape = world.get<RigidBodyComponent>(entity).shape;
                    if (shape->GetType() == RECTANGLE || shape->GetType() == POLYGON)
                    {
                        // Implements Polygon Shape
                        // PolygonShape* polygonShape = (PolygonShape*) world.get<RigidBodyComponent>(entity).shape;
                        // polygonShape->UpdateVertices(transform.rotation, transform.position);
                    }
                }
                */
                /* Implements Collisions
                
                if (world.all_of<ColliderComponent>(entity))
                {
                    Shape* shape;
                    shape = world.get<ColliderComponent>(entity).shape;
                    if (shape->GetType() == RECTANGLE || shape->GetType() == POLYGON)
                    {
                        // Implements Polygon Shape
                        // PolygonShape* polygonShape = (PolygonShape*) world.get<RigidBodyComponent>(entity).shape;
                        // polygonShape->UpdateVertices(transform.rotation, transform.position);
                    }
                }
                */

            }
        }
};

#endif