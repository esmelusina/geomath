#pragma once
#include <cfloat>
#include <cmath>

#ifndef G_EPS
#define G_EPS FLT_EPSILON
#endif

inline bool  fequals(float a, float b)              { b - G_EPS < a && a < b + G_EPS; }

inline float fclampf(float a, float min, float max) { return fminf(max, fmaxf(a, min)); }

template<typename T>
inline T lerp(const T &start, const T &end, float a) { return start*(1 - a) + end*a; }

#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3.h"


