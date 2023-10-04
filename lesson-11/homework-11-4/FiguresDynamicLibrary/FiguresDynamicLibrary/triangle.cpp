#include "triangle.h"
#include <iostream>
#include <string>

    Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Figure(3)
    {
        side_a = a;
        side_b = b;
        side_c = c;

        angle_a = A;
        angle_b = B;
        angle_c = C;

        set_figure_name("Треугольник");
    }

    int Triangle::get_side_a()
    {
        return side_a;
    }

    int Triangle::get_side_b()
    {
        return side_b;
    }

    int Triangle::get_side_c()
    {
        return side_c;
    }

    int Triangle::get_angle_a()
    {
        return angle_a;
    }

    int Triangle::get_angle_b()
    {
        return angle_b;
    }

    int Triangle::get_angle_c()
    {
        return angle_c;
    }

    std::string Triangle::get_sides_info() 
    {
        return "a=" + std::to_string(side_a) + " b=" + std::to_string(side_b) + " c=" + std::to_string(side_c);
    }

    std::string Triangle::get_angles_info()
    {
        return "A=" + std::to_string(angle_a) + " B=" + std::to_string(angle_b) + " C=" + std::to_string(angle_c);
    }


