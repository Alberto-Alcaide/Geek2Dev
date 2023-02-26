#include "Vec2D.h"
#include <math.h>

//#define _USE_MATH_DEFINES
#define PI 3.14159265358979323846 

Vec2D::Vec2D(float x = 0.0, float y = 0.0) : x(x), y(y) {}

void Vec2D::add(const Vec2D &v)
{
    x = v.x;
    y = v.y;
}

void Vec2D::scale(const float scale)
{
    x *= scale;
    y *= scale;
}

void Vec2D::scale(const Vec2D &v)
{
    // TODO
}

Vec2D Vec2D::rotate(const float angle) const
{
    return Vec2D(x*cos(angle) - y*sin(angle), x*cos(angle) + y*sin(angle));
}

float Vec2D::magnitude() const
{
    return sqrt(x*x + y*y);
}

float Vec2D::magnitudeSquared() const
{
    float m = magnitude();
    return m * m;
}

// @return Angle in degrees
float Vec2D::angle() const
{
    return atan2(y, x) * 180.0 / PI;
}

Vec2D Vec2D::normalize()
{
    // TODO
    return Vec2D();
}

Vec2D Vec2D::unitVector() const
{
    // TODO 
    return Vec2D();
}

Vec2D Vec2D::normal() const
{
    // TODO
    return Vec2D();
}

float Vec2D::dotProduct(const Vec2D &v) const
{
    // TODO
    return 0.0f;
}

float Vec2D::crossProduct(const Vec2D &v) const
{
    // TODO
    return 0.0f;
}

Vec2D& Vec2D::operator=(const Vec2D &v)
{
    x = v.x;
    y = v.y;
    
    return *this;
}

bool Vec2D::operator==(const Vec2D &v) const
{
    return x == v.x && y == v.y;
}

bool Vec2D::operator!=(const Vec2D &v) const
{
    return x != v.x || y != v.y;
}

Vec2D Vec2D::operator+(const Vec2D &v) const
{
    return Vec2D(x + v.x, y + v.y);
}

Vec2D Vec2D::operator-(const Vec2D &v) const
{
    return Vec2D(x - v.x, y - v.y);
}

Vec2D Vec2D::operator*(const Vec2D &v) const
{
    return Vec2D(x * v.x, y * v.y);
}

Vec2D Vec2D::operator*(const float scale) const
{
    return Vec2D(x * scale, y * scale);
}

Vec2D Vec2D::operator/(const Vec2D &v) const
{
    return Vec2D(x / v.x, y / v.y);
}

Vec2D Vec2D::operator-()
{
    return Vec2D(-x, -y);
}

Vec2D& Vec2D::operator+=(const Vec2D &v)
{
    x += v.x;
    y += v.y;

    return *this;
}

Vec2D &Vec2D::operator-=(const Vec2D &v)
{
    x -= v.x;
    y -= v.y;

    return *this;
}

Vec2D &Vec2D::operator*=(const Vec2D &v)
{
    x *= v.x;
    y *= v.y;

    return *this;
}

Vec2D &Vec2D::operator/=(const Vec2D &v)
{
    x /= v.x;
    y /= v.y;

    return *this;
}

std::ostream& operator<<(std::ostream os, const Vec2D &v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}
