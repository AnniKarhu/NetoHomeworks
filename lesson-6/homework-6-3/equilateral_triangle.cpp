#include "equilateral_triangle.h"

//Равносторонний  треугольник

    Equilateral_triangle::Equilateral_triangle(int a) : Isosceles_triangle(a, a, 60, 60)
    {
        set_figure_name("Равносторонний треугольник");
    }
