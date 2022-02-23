#ifndef VEC2_H
#define VEC2_H

#include <iostream>

struct vec2
{
    float x = 0.0F;
    float y = 0.0F;

    vec2();

    vec2(float x_, float y_);
    
    vec2 operator + (const vec2& v) const;
    vec2 operator - (const vec2& v) const;
    vec2 operator * (const vec2& v) const;
    vec2 operator / (const vec2& v) const;
    
    vec2 operator * (float k) const;
    vec2 operator / (float k) const;

    vec2& operator += (const vec2& v);
    vec2& operator -= (const vec2& v);
    vec2& operator *= (const vec2& v);
    vec2& operator /= (const vec2& v);
    
    vec2& operator *= (float k);
    vec2& operator /= (float k);
    
    vec2 operator - ();

    bool operator == (const vec2& v) const;
    bool operator != (const vec2& v) const;
    
    float magnitute2() const;
    float magnitute() const;
    
    vec2& normalize();
    vec2 normalized() const;

    vec2& rotate(float angle);
    vec2 rotated(float angle) const;
};

vec2 operator * (float k, const vec2& v);
float dot(const vec2& u, const vec2& v);
float cross(const vec2& u, const vec2& v);
vec2 sign(const vec2& v);
vec2 round(const vec2& v);
vec2 abs(const vec2& v);

std::ostream& operator<<(std::ostream& os, const vec2& v);
std::istream& operator>>(std::istream& is, vec2& v);

#endif // VEC2_H