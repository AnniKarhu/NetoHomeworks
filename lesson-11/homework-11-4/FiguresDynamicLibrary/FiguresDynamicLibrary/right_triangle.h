#pragma once
#include "triangle.h"

#ifdef RIGHT_TRIANGLE_DYN_LIB_EXPORTS
#define RIGHT_TRIANGLE_DYN_LIB_API __declspec(dllexport)
#else
#define RIGHT_TRIANGLE_DYN_LIB_API __declspec(dllimport)
#endif


//прямоугольный треугольник
class Right_triangle : public Triangle
{
public:
    RIGHT_TRIANGLE_DYN_LIB_API  Right_triangle(int a, int b, int c, int A, int B); // : Triangle(a, b, c, A, B, 90);
    
};
