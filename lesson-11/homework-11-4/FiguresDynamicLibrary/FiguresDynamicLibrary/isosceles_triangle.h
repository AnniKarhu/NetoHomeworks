#pragma once
#include "triangle.h"

//равнобедренный треугольник
class Isosceles_triangle : public Triangle
{
public:
	FIGURE_DYN_LIB_API  Isosceles_triangle(int a, int b, int A, int B); // : Triangle(a, b, a, A, B, A);

};
