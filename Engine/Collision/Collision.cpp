#include "Collision.h"

bool Collision::IsColliding(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world)
{
    bool aIsCircle = world.get<ColliderComponent>(a).shape->GetType() == CIRCLE;
    bool bIsCircle = world.get<ColliderComponent>(b).shape->GetType() == CIRCLE;
    bool aIsPolygon = world.get<ColliderComponent>(a).shape->GetType() == RECTANGLE || world.get<ColliderComponent>(a).shape->GetType() == POLYGON;
    bool bIsPolygon = world.get<ColliderComponent>(b).shape->GetType() == RECTANGLE || world.get<ColliderComponent>(b).shape->GetType() == POLYGON;
    
    if (aIsCircle && bIsCircle)
    {
        return IsCollidingCircleCircle(a,b,contact,world);
    }
    if (aIsPolygon && bIsPolygon)
    {
        return IsCollidingPolygonPolygon(a,b,contact,world);
    }
    if (aIsPolygon && bIsCircle)
    {
        return IsCollidingPolygonCircle(a,b,contact,world);
    }
    if (aIsCircle && bIsPolygon)
    {
        return IsCollidingPolygonCircle(a,b,contact,world);
    }

    return false;
    
}