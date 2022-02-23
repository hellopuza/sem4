#include "vec2.h"

#include <cmath>
#include <functional>

vec2::vec2() {}

vec2::vec2(float x_, float y_) : x(x_), y(y_) {}
    
vec2 vec2::operator + (const vec2& v) const
{
    return vec2(x + v.x,
                y + v.y);
}
    
vec2 vec2::operator - (const vec2& v) const
{
    return vec2(x - v.x,
                y - v.y);
}
    
vec2 vec2::operator * (const vec2& v) const
{
    return vec2(x * v.x,
                y * v.y);
}

vec2 vec2::operator / (const vec2& v) const
{
    return vec2(x / v.x,
                y / v.y);
}
    
vec2 vec2::operator * (float k) const
{
    return vec2(k * x,
                k * y);
}

vec2 vec2::operator / (float k) const
{
    return vec2(x / k,
                y / k);
}

vec2& vec2::operator += (const vec2& v)
{
    return *this = *this + v;
}
    
vec2& vec2::operator -= (const vec2& v)
{
    return *this = *this - v;
}

vec2& vec2::operator *= (const vec2& v)
{
    return *this = *this * v;
}

vec2& vec2::operator /= (const vec2& v)
{
    return *this = *this / v;
}
    
vec2& vec2::operator *= (float k)
{
    return *this = *this * k;
}
    
vec2& vec2::operator /= (float k)
{
    return *this = *this / k;
}
    
vec2 vec2::operator - ()
{
    return vec2(-x, -y);
}

bool vec2::operator == (const vec2& v) const
{
    return (x == v.x) && (y == v.y);
}

bool vec2::operator != (const vec2& v) const
{
    return (x != v.x) || (y != v.y);
}
    
float vec2::magnitute2() const
{
    return x * x + y * y;
}
    
float vec2::magnitute() const
{
    return std::sqrt(magnitute2());
}
    
vec2& vec2::normalize()
{
    return *this /= magnitute();
}

vec2 vec2::normalized() const
{
    return *this / magnitute();
}

vec2& vec2::rotate(float angle)
{
    return *this = vec2(x * std::cos(angle) - y * std::sin(angle),
                        x * std::sin(angle) + y * std::cos(angle));
}

vec2 vec2::rotated(float angle) const
{
    return vec2(x * std::cos(angle) - y * std::sin(angle),
                x * std::sin(angle) + y * std::cos(angle));
}

std::ostream& operator<<(std::ostream& os, const vec2& v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, vec2& v)
{
    is >> v.x >> v.y;
    return is;
}

vec2 operator * (float k, const vec2& v)
{
    return v * k;
}

float dot(const vec2& u, const vec2& v)
{
    return u.x * v.x + u.y * v.y;
}

float cross(const vec2& u, const vec2& v)
{
    return u.x * v.y - u.y * v.x;
}

vec2 sign(const vec2& v)
{
    return vec2((v.x > 0.0F) ? 1.0F : (v.x < 0.0F) ? -1.0F : 0.0F,
                (v.y > 0.0F) ? 1.0F : (v.y < 0.0F) ? -1.0F : 0.0F);
}

vec2 round(const vec2& v)
{
    return vec2(round(v.x), round(v.y));
}

vec2 abs(const vec2& v)
{
    return vec2(std::abs(v.x), std::abs(v.y));
}