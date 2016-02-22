#pragma once

#include "GMath.h"


struct Matrix3
{
    union
    {
        Vector3 c[3];
        float   m[3][3];
        float   v[9];
    };

    Vector3  operator[](unsigned idx) const { return c[idx]; }
    Vector3 &operator[](unsigned idx)       { return c[idx]; }

    Vector2 &right()    { return c[0].xy; }
    Vector2 &up()       { return c[1].xy; }
    Vector2 &position() { return c[2].xy; }

    inline Matrix3 transpose()  const { Matrix3 t; for (unsigned i = 0; i < 3; ++i) for (unsigned j = 0; j < 3; ++j) t[i][j] = c[j][i]; return t; }

    Matrix3 &operator*=(const Matrix3 &a) { Matrix3 t = transpose(); for (unsigned i = 0; i < 3; ++i) for (unsigned j = 0; j < 3; ++j) c[i][j] = dot(t[j], a[i]);  return *this; }
    Matrix3 &operator*=(float a)          { for (unsigned i = 0; i < 3; ++i) c[i] *= a;    return *this; }
    Matrix3 &operator+=(const Matrix3 &a) { for (unsigned i = 0; i < 3; ++i) c[i] += a[i]; return *this; }
    Matrix3 &operator-=(const Matrix3 &a) { for (unsigned i = 0; i < 3; ++i) c[i] -= a[i]; return *this; }

    inline float determinant()  const { return dot(c[0], cross(c[1], c[2])); }
    inline Matrix3 inverse()    const { return Matrix3{ cross(c[1], c[2]), cross(c[2], c[0]), cross(c[0], c[1]) }.transpose() *= (1 / determinant()); }

    
    static Matrix3 identity() { return{ 1,0,0, 0,1,0, 0,0,1 }; }


    static Matrix3 rotate   (float angle)      { Matrix3 r = identity(); r.right() = Vector2::fromAngle(angle); r.up() = r.right().perp(); return r; }
    static Matrix3 scale    (const Vector2 &a) { Matrix3 r = identity(); r[0][0] = a[0]; r[1][1] = a[1]; return r; }
    static Matrix3 translate(const Vector2 &a) { Matrix3 r = identity(); r.position() = a; return r; }
};

inline Matrix3 operator*(Matrix3 a, const Matrix3 &b) { return a *= b; }
inline Matrix3 operator*(Matrix3 a, float b)          { return a *= b; }
inline Vector3 operator*(const Matrix3 &a, const Vector3 &b)
{
    auto t = a.transpose();
    Vector3 r = {};
    for (unsigned i = 0; i < 3; ++i)
        r[i] = dot(t[i], b);
    return r;
}