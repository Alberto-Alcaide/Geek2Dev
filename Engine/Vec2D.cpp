#include "Vec2D.h"
#include <math.h>

//#define _USE_MATH_DEFINES
#define PI 3.14159265358979323846

Vec2D::Vec2D() : x(0.0), y(0.0) {}

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

float Vec2D::angle() const
{
    return atan2(y, x) * 180.0 / PI;
}

Vec2D Vec2D::fromModuleAngle(float module, float angle)
{
    // convert
    float a = angle * PI /180;
    return Vec2D(module * cos(a), module * sin(a));
}

Vec2D &Vec2D::normalize()
{
    if(x!=0 && y!=0)
    {
        float m = magnitude();
        x = x / m;
        y = y / m;
    }

    return *this;
}

Vec2D Vec2D::unitVector() const
{ 
    if(x==0 && y==0)
    {
        return Vec2D(0.0, 0.0);
    }

    float m = magnitude();
    return Vec2D(x/m, y/m);
}

Vec2D Vec2D::normalClockwise() const
{
    return Vec2D(y, -x);
}

Vec2D Vec2D::normalCounterclockwise() const
{
    return Vec2D(-y, x);
}

float Vec2D::dotProduct(const Vec2D &v) const
{   
    return x*v.x + y*v.y;
}

float Vec2D::crossProduct(const Vec2D &v) const
{
    return x * v.y - y * v.x;
}

Vec2D Vec2D::lerp(Vec2D &a, Vec2D &b, float t)
{
    float x = (1 - t) * a.x + t * b.x;
    float y = (1 - t) * a.y + t * b.y;

    return Vec2D(x, y);
}

Vec2D &Vec2D::operator=(const Vec2D &v)
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

std::ostream& operator<<(std::ostream &os, const Vec2D &v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}
