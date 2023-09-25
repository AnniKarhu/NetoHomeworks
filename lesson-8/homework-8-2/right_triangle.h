#pragma once
#include "triangle.h"

//прямоугольный треугольник
class Right_triangle : public Triangle
{
public:
    Right_triangle(int a, int b, int c, int A, int B); // : Triangle(a, b, c, A, B, 90);
    
};
