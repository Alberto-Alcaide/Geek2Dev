#ifndef KINEMATICSYSTEM_H
#define KINEMATICSYSTEM_H

#include "RigidBodyComponent.h"
#include "KinematicsComponent.h"
#include "TransformComponent.h"
#include "entt/entt.hpp"
#include "PolygonShape.h"

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
            
            // Integrate linear motion using euler method (x(n+1) = x(n) + dx * dt) 
            kinematic.velocity += kinematic.acceleration * dt; 
            transform.position += kinematic.velocity * dt; 

            // Integrate angular motion
            kinematic.angularVelocity += kinematic.angularAcceleration * dt;
            transform.rotation += kinematic.angularVelocity * dt;



            if (world.all_of<RigidBodyComponent>(entity))
            {
                Shape* shape;
                shape = world.get<RigidBodyComponent>(entity).shape;
                if (shape->GetType() == RECTANGLE || shape->GetType() == POLYGON)
                {
                    // Implements Polygon Shape
                    PolygonShape* polygonShape = (PolygonShape*) world.get<RigidBodyComponent>(entity).shape;
                    polygonShape->UpdateVertices(transform.rotation, transform.position);
                }
            }
        }

        
    }
};

/*class KinematicSystem
{
    public: 
        void Update(const double dt, entt::registry& world)
        {
            auto view = world.view<TransformComponent, KinematicsComponent, RigidBodyComponent>();
            // Loop all entities that the system is interested in
            for (auto entity: view)
            {
                auto& transform = view.get<TransformComponent>(entity);
                auto& kinematics = view.get<KinematicsComponent>(entity);

                auto& rigidbody = view.get<RigidBodyComponent>(entity);

                // Gets the acceleration of the object
                kinematics.acceleration= rigidbody.sumForces * rigidbody.invMass;

                // Gets the angularAcceleration of the object
                kinematics.angularAcceleration = rigidbody.sumTorques * rigidbody.invInertia;

                rigidbody.ClearForces();
                rigidbody.ClearTorque();

                // Integrate linear motion
                kinematics.velocity += kinematics.acceleration * dt;
                transform.position += kinematics.velocity * dt;

                // Integrate angular motion
                kinematics.angularVelocity += kinematics.angularAcceleration * dt;
                transform.rotation += kinematics.angularVelocity * dt;



                // We don't have PolygonShape just yet
                
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
                
                 Implements Collisions
                
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
                

            }
        }

        void Render(entt::registry& world)
        {
            auto view = world.view<TransformComponent, RigidBodyComponent>();
            for (auto entity: view)
            {
                const auto transform = view.get<TransformComponent>(entity);
                const auto rigidbody = view.get<RigidBodyComponent>(entity);
                
                rigidbody.circleShape->Render(transform);
            }
        }
};*/

#endif