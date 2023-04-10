#include "entt/entt.hpp"
#include "Vec2D.h"
#include "Shape.h"
#include "ColliderComponent.h"

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
    static bool IsCollidingPolygonPolygon(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world);
    static bool IsCollidingPolygonCircle(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world);
    static void ResolveCollision(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world);
    static void ResolvePenetration(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world);
};