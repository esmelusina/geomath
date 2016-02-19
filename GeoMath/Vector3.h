#pragma once
#include "GMath.h"


struct Vector3
{
    union
    {
        struct { float x, y, z; };
        float v[3];
        Vector2 xy;
    };

    float &operator[](size_t idx)       { return v[idx]; }
    float  operator[](size_t idx) const { return v[idx]; }

    Vector3 &operator /=(float a)          { return *this = Vector3{ x / a  , y / a, z/a }; }
    Vector3 &operator *=(float a)          { return *this = Vector3{ x * a  , y * a, z/a }; }
    Vector3 &operator -=(const Vector3 &a) { return *this = Vector3{ x - a.x, y - a.y, z-a.z }; }
    Vector3 &operator +=(const Vector3 &a) { return *this = Vector3{ x + a.x, y + a.y, z+a.z }; }

    float   magnitude() const { return sqrt(x*x + y*y + z*z); }
    Vector3 normal()    const { return Vector3{ x, y, z } /= magnitude(); }
    Vector3 operator-() const { return{ -x,-y,-z }; }
};

inline float dot(const Vector3 &a, const Vector3 &b)     { return a.x*b.x + a.y*b.y + a.z*b.z; }

inline Vector3 cross(const Vector3 &a, const Vector3 &b) { return {a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x }; }

// component-wise min
inline Vector3 vmin(const Vector3 &a, const Vector3 &b) { return{ fminf(a.x,b.x), fminf(a.y,b.y), fminf(a.z,b.z) }; }

// component-wise max
inline Vector3 vmax(const Vector3 &a, const Vector3 &b) { return{ fmaxf(a.x,b.x), fmaxf(a.y,b.y), fmaxf(a.z,b.z) }; }


inline Vector3 operator+(Vector3 a, const Vector3 &b) { return a += b; }
inline Vector3 operator-(Vector3 a, const Vector3 &b) { return a -= b; }
inline Vector3 operator/(Vector3 a, float b)          { return a /= b; }
inline Vector3 operator*(Vector3 a, float b)          { return a *= b; }



// component-wise clamp
inline Vector3 vclamp(const Vector3 &a, const Vector3 &min, const Vector3 &max) { return vmin(max, vmax(a, min)); }

// normal should be normalized
inline Vector3 reflect(const Vector3 &incident, const Vector3 &normal) { incident - normal * 2 * dot(incident, normal); }

// normal should be normalized
inline Vector3 project(const Vector3 &incident, const Vector3 &normal) { normal * dot(incident, normal); }