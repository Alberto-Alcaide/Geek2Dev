#ifndef COLLISION_H
#define COLLISION_H

#include "entt/entt.hpp"
#include "Vec2D.h"
#include "Shape.h"
#include "ColliderComponent.h"
#include "CircleShape.h"
#include "RigidBodyComponent.h"
#include "KinematicsComponent.h"
#include "NameGroupComponent.h"
#include "RectangleShape.h"
#include "PolygonShape.h"

struct Contact{
    entt::entity a;
    entt::entity b;
    Vec2D start;
    Vec2D end;
    Vec2D normal;
    float depth;
};

struct Collision{
    static bool IsColliding(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world);
    static bool IsCollidingCircleCircle(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world);
    static bool IsCollidingRectangleRectangle(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world);
    static bool IsCollidingPolygonCircle(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world);
    static void ResolveCollision(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world);
    static void ResolvePenetration(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world);
};

#endif