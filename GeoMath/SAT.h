#pragma once
#include "Shapes.h"

struct Shape
{
    const enum { eAABB = 1, eCircle = 2, ePlane = 4, eRay = 8 } type;
         union { Circle c; Plane p; Ray r; AABB a; };
};

