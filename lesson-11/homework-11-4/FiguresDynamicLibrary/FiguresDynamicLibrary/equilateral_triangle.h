#pragma once
#include "isosceles_triangle.h" 

#ifdef EQUILATERAL_TRIANGLE_DYN_LIB_EXPORTS
#define EQUILATERAL_TRIANGLE_LIB_API __declspec(dllexport)
#else
#define EQUILATERAL_TRIANGLE_API __declspec(dllimport)
#endif


//Равносторонний  треугольник
class Equilateral_triangle : public Isosceles_triangle
{
public:
    EQUILATERAL_TRIANGLE_API  Equilateral_triangle(int a); // : Isosceles_triangle(a, a, 60, 60);
    
};