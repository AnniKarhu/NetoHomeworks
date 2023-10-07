#pragma once
#include "isosceles_triangle.h" 


//Равносторонний  треугольник
class Equilateral_triangle : public Isosceles_triangle
{
public:
    FIGURE_DYN_LIB_API  Equilateral_triangle(int a); // : Isosceles_triangle(a, a, 60, 60);
    
};