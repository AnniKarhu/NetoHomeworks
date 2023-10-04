#pragma once
#include "triangle.h"

#ifdef ISOLESCELES_TRIANGLE_DYN_LIB_EXPORTS
#define ISOLESCELES_TRIANGLE_DYN_LIB_API __declspec(dllexport)
#else
#define ISOLESCELES_TRIANGLE_DYN_LIB_API __declspec(dllimport)
#endif


//равнобедренный треугольник
class Isosceles_triangle : public Triangle
{
public:
	ISOLESCELES_TRIANGLE_DYN_LIB_API  Isosceles_triangle(int a, int b, int A, int B); // : Triangle(a, b, a, A, B, A);

};
