#include "isosceles_triangle.h" 


//равнобедренный треугольник

    Isosceles_triangle::Isosceles_triangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
    {
        set_figure_name("Равнобедренный треугольник");
    }

