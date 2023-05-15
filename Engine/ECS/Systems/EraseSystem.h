#ifndef ERASESYSTEM_H
#define ERASESYSTEM_H

#include "Graphics.h"
#include "entt/entt.hpp"
#include "KinematicsComponent.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "EraseComponent.h"
#include "Log.h"

class EraseSystem
{
    public:
        void Update(entt::registry& world)
        {
            auto view = world.view<EraseComponent>();


            for (auto entity: view)
            {
                world.destroy(entity);
                
            }
        }
        
};

#endif