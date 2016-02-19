#pragma once
#include "GMath.h"


struct Vector2
{
    union
    {
        struct { float x, y; };
        float v[2];
    };

    float &operator[](size_t idx)       { return v[idx]; }
    float  operator[](size_t idx) const { return v[idx]; }

    Vector2 &operator /=(float a)           { return *this = Vector2{ x / a  , y / a   }; }
    Vector2 &operator *=(float a)           { return *this = Vector2{ x * a  , y * a   }; }
    Vector2 &operator -=(const Vector2 &a)  { return *this = Vector2{ x - a.x, y - a.y }; }
    Vector2 &operator +=(const Vector2 &a)  { return *this = Vector2{ x + a.x, y + a.y }; }

    float   magnitude() const { return sqrt(x*x + y*y); }
    float   angle()     const { return atan2f(y,    x); }

    Vector2 normal()    const { return Vector2{x, y} /= magnitude(); }
    Vector2 operator-() const { return { -x,-y }; }
    Vector2 perp()      const { return { -y, x }; }

    static Vector2 fromAngle(float a) { return{ cosf(a),sinf(a) }; }
};

inline float dot(const Vector2 &a, const Vector2 &b) { return a.x*b.x + a.y*b.y; }

inline Vector2 operator+(Vector2 a, const Vector2 &b) { return a += b; }
inline Vector2 operator-(Vector2 a, const Vector2 &b) { return a -= b; }
inline Vector2 operator/(Vector2 a, float b)          { return a /= b; }
inline Vector2 operator*(Vector2 a, float b)          { return a *= b; }

// component-wise min
inline Vector2 vmin(const Vector2 &a, const Vector2 &b) { return{ fminf(a.x,b.x), fminf(a.y,b.y) }; }

// component-wise max
inline Vector2 vmax(const Vector2 &a, const Vector2 &b) { return{ fmaxf(a.x,b.x), fmaxf(a.y,b.y) }; }

// component-wise clamp
inline Vector2 vclamp(const Vector2 &a, const Vector2 &min, const Vector2 &max) { return vmin(max, vmax(a, min)); }

// normal should be normalized
inline Vector2 reflect(const Vector2 &incident, const Vector2 &normal) { incident - normal * 2 * dot(incident, normal); }

// normal should be normalized
inline Vector2 project(const Vector2 &incident, const Vector2 &normal) {  normal * dot(incident, normal); }