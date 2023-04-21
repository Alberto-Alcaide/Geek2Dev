#ifndef SCRIPTSYSTEM_H
#define SCRIPTSYSTEM_H

#include "ScriptComponent.h"
#include "TransformComponent.h"
#include "KinematicsComponent.h"
#include "entt/entt.hpp"
#include "Log.h"

class ScriptSystem
{
    public:
        void CreateLuaBindings(sol::state& lua)
        {
            lua.new_usertype<Vec2D>(
                "Vec2D",
                sol::constructors<Vec2D(float, float)>(),
                "x", &Vec2D::x,
                "y", &Vec2D::y
            );
            lua.set_function("set_position", [](entt::entity entity, entt::registry& world, double x, double y)
            {
                if (world.all_of<TransformComponent>(entity))
                {
                    auto& transform = world.get<TransformComponent>(entity);
                    transform.position = Vec2D(x, y);
                }
                else
                {
                    Log::Error("Trying to set the position of an entity that has no transform component");
                }
            });
            lua.set_function("set_velocity", [](entt::entity entity, entt::registry& world, double x, double y)
            {
                if (world.all_of<KinematicsComponent>(entity))
                {
                    auto& kinematic = world.get<KinematicsComponent>(entity);
                    kinematic.velocity = Vec2D(x, y);
                }
                else
                {
                    Log::Error("Trying to set the velocity of an entity that has no kinematic component");
                }
            });
            lua.set_function("get_position", [](entt::entity entity, entt::registry& world)
            {
                if (world.all_of<TransformComponent>(entity))
                {
                    auto& transform = world.get<TransformComponent>(entity);
                    return transform.position;
                }
                else
                {
                    Log::Error("Trying to get the position of an entity that has no transform component");
                    return Vec2D(0.0,0.0);
                }
            });
            lua.set_function("get_velocity", [](entt::entity entity, entt::registry& world)
            {
                if (world.all_of<KinematicsComponent>(entity))
                {
                    auto& kinematic = world.get<KinematicsComponent>(entity);
                    return kinematic.velocity;
                }
                else
                {
                    Log::Error("Trying to get the velocity of an entity that has no kinematic component");
                    return Vec2D(0.0,0.0);
                }
            });
        }

        void Update(const double dt, const int ellapsedTime, entt::registry& world)
        {
            auto view = world.view<ScriptComponent>();
            for (auto entity: view)
            {
                const auto script = view.get<ScriptComponent>(entity);
                script.func(entity, world, dt, ellapsedTime);
            }
        }
};


#endif