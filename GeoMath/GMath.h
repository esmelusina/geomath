#pragma once
#include <cfloat>
#include <cmath>

#ifndef G_EPS
#define G_EPS FLT_EPSILON
#endif

#define RAD2DEG 57.2958
#define DEG2RAD 0.0174533
#define PI 3.14159265359

#ifdef  G_USE_DEGREES
#define ADJUST DEG2RAD
#else
#define ADJUST 1
#endif

inline bool  fequals(float a, float b)              { b - G_EPS < a && a < b + G_EPS; }

inline float fclampf(float a, float min, float max) { return fminf(max, fmaxf(a, min)); }

template<typename T>
inline T lerp(const T &start, const T &end, float a) { return start*(1 - a) + end*a; }

#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3.h"


