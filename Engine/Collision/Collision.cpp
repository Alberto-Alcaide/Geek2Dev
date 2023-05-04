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
        return IsCollidingRectangleRectangle(a,b,contact,world);
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


void Collision::ResolvePenetration(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world)
{
    auto const rigidbodyA = world.get<RigidBodyComponent>(a);
    auto const rigidbodyB = world.get<RigidBodyComponent>(b);
    auto& transformA = world.get<TransformComponent>(a);
    auto& transformB = world.get<TransformComponent>(b);


    if (rigidbodyA.IsStatic() && rigidbodyB.IsStatic())
    {
        return;
    }

    float da = contact.depth / (rigidbodyA.invMass + rigidbodyB.invMass) * rigidbodyA.invMass;
    float db = contact.depth / (rigidbodyA.invMass + rigidbodyB.invMass) * rigidbodyB.invMass;

    transformA.position -= contact.normal * da;
    transformB.position += contact.normal * db;
}

void Collision::ResolveCollision(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world)
{
    ResolvePenetration(a,b,contact,world);
    std::cout << "Resolve Penetration" << std::endl;

    auto const rigidbodyA = world.get<RigidBodyComponent>(a);
    auto const rigidbodyB = world.get<RigidBodyComponent>(b);
    auto& kinematicA = world.get<KinematicsComponent>(a);
    auto& kinematicB = world.get<KinematicsComponent>(b);

    //Define elasticity (coefficient of restitution e)
    float e = std::min(rigidbodyA.restitution, rigidbodyB.restitution);

    // Calculate the relative velocity between the two objects
    const Vec2D vrel = (kinematicA.velocity - kinematicB.velocity);

    // Calculate the relative velocity along the normal collision vector
    float vrelDotNormal = vrel.dotProduct(contact.normal);

    // Now we proceed to calculate the collision impulse
    const Vec2D impulseDirection = contact.normal;
    const float impulseMagnitude = -(1 + e) * vrelDotNormal / (rigidbodyA.invMass + rigidbodyB.invMass);

    Vec2D jn = impulseDirection * impulseMagnitude;

    // Apply the impulse vector to both objects in opposite direction
    kinematicA.velocity += jn * rigidbodyA.invMass;
    kinematicB.velocity -= jn * rigidbodyB.invMass;
}

bool Collision::IsCollidingRectangleRectangle(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world)
{
    const RectangleShape* aRectangleShape = (RectangleShape*)world.get<ColliderComponent>(a).shape;
    const RectangleShape* bRectangleShape = (RectangleShape*)world.get<ColliderComponent>(b).shape;

    const auto aTransform = world.get<TransformComponent>(a);
    const auto bTransform = world.get<TransformComponent>(b);

    auto right1 = aTransform.position.x + aRectangleShape->width/2.0; // The right part of Box 1
    auto left1 = aTransform.position.x - aRectangleShape->width/2.0; // The left part of Box 1
    auto top1 = aTransform.position.y - aRectangleShape->height/2.0; // The top part of Box 1
    auto bottom1 = aTransform.position.y + aRectangleShape->height/2.0; // The bottom part of Box 1

    auto right2 = bTransform.position.x + bRectangleShape->width/2.0; // The right part of Box 2
    auto left2 = bTransform.position.x - bRectangleShape->width/2.0; // The left part of Box 2
    auto top2 = bTransform.position.y - bRectangleShape->height/2.0; // The top part of Box 2
    auto bottom2 = bTransform.position.y + bRectangleShape->height/2.0; // The bottom part of Box 2

    if ((right1 >= left2) && (right2 >= left1) && (bottom1 >= top2) && (bottom2 >= top1))
    {


        contact.a = a;
        contact.b = b;

        Vec2D ab=aTransform.position-bTransform.position;
        
        contact.normal=ab;
        contact.normal.normalize();

        float x_overlap = std::min(right1,right2) - std::max(left1, left2);
        float y_overlap = std::min(bottom1, bottom2) - std::max(top1, top2);

        if (x_overlap < y_overlap)
        {
            if (right1 < right2)
            {
                contact.normal = Vec2D(1,0);
            }
            else
            {
                contact.normal = Vec2D(-1,0);
            }
        }
        else
        {
            if (bottom1 < bottom2)
            {
                contact.normal = Vec2D(0,1);
            }
            else
            {
                contact.normal = Vec2D(0,-1);
            }
        }

        contact.start = Vec2D(std::max(left1,left2),std::max(top1,top2));
        contact.end = Vec2D(std::min(right1,right2),std::min(bottom1,bottom2));

        contact.depth = (contact.end - contact.start).magnitude();

       return true;
    }
    
    return false;
}

bool Collision::IsCollidingPolygonCircle(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world)
{
    return false;
}