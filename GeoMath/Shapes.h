#pragma once
#include "GMath.h"
#include <vector>

struct AABB
{
    Vector2 position, halfextent;
    Vector2 min() const { return position - halfextent; }
    Vector2 max() const { return position + halfextent; }
};

struct Circle     { Vector2 position; float radius; };
struct Plane      { Vector2 position, normal; };
struct Ray        { Vector2 position, direction; float length; };

struct ConvexHull { std::vector<Vector2> verts; };

AABB        operator*(const Matrix3 &, const AABB       &);
Circle      operator*(const Matrix3 &, const Circle     &);
Plane       operator*(const Matrix3 &, const Plane      &);
Ray         operator*(const Matrix3 &, const Ray        &);
ConvexHull  operator*(const Matrix3 &, const ConvexHull &);

