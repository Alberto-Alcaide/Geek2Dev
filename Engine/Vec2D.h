#ifndef VEC2_H
#define VEC2_H

#include <iostream>

struct Vec2D
{
    float x;
    float y;

    Vec2D(float x, float y);
    ~Vec2D() = default;

    void add(const Vec2D& v);
    void sub(const Vec2D& v);
    void scale(const float n);  
    void scale(const Vec2D& v);
    Vec2D rotate(const float angle) const;

    float magnitude() const;
    float magnitudeSquared() const;
    
    // @return Angle in degrees
    float angle() const;

    Vec2D normalize();
    Vec2D unitVector() const;
    Vec2D normal() const;

    float dotProduct(const Vec2D& v) const;
    float crossProduct(const Vec2D& v) const;

    static Vec2D lerp(Vec2D &a, Vec2D &b, float t);

    Vec2D& operator = (const Vec2D& v);
    bool operator == (const Vec2D& v) const;
    bool operator != (const Vec2D& v) const;

    Vec2D operator + (const Vec2D& v) const;
    Vec2D operator - (const Vec2D& v) const;
    Vec2D operator * (const Vec2D& v) const;
    Vec2D operator * (const float scale) const;
    Vec2D operator / (const Vec2D& v) const;
    Vec2D operator - ();

    Vec2D& operator += (const Vec2D& v);
    Vec2D& operator -= (const Vec2D& v);
    Vec2D& operator *= (const Vec2D& v);
    Vec2D& operator /= (const Vec2D& v);

    friend std::ostream& operator<<(std::ostream os, const Vec2D& v);
};

#endif