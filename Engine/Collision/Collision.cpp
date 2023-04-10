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

bool Collision::IsCollidingCircleCircle(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world)
{
    const CircleShape* aCircleShape = (CircleShape*)world.get<ColliderComponent>(a).shape;
    const CircleShape* bCircleShape = (CircleShape*)world.get<ColliderComponent>(b).shape;

    const auto aTransform = world.get<TransformComponent>(a);
    const auto bTransform = world.get<TransformComponent>(b);

    const Vec2D ab = bTransform.position - aTransform.position;
    const float radiusSum = aCircleShape->radius + bCircleShape->radius;

    bool isColliding = ab.magnitudeSquared() <= (radiusSum * radiusSum);

    if (!isColliding)
        return false;
    
    contact.a=a;
    contact.b=b;
    contact.normal=ab;
    contact.normal.normalize();
    contact.start = bTransform.position - contact.normal * bCircleShape->radius;
    contact.end = aTransform.position + contact.normal * aCircleShape->radius;
    contact.depth = (contact.end - contact.start).magnitude();

    return true;
}