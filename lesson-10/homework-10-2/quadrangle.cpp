#include "quadrangle.h"
#include <string>

//четырехугольник

    Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4)
    {
        side_a = a;
        side_b = b;
        side_c = c;
        side_d = d;

        angle_a = A;
        angle_b = B;
        angle_c = C;
        angle_d = D;

        set_figure_name("Четырёхугольник");
    }

    int Quadrangle::get_side_a()
    {
        return side_a;
    }

    int Quadrangle::get_side_b()
    {
        return side_b;
    }

    int Quadrangle::get_side_c()
    {
        return side_c;
    }

    int Quadrangle::get_side_d()
    {
        return side_d;
    }

    int Quadrangle::get_angle_a()
    {
        return angle_a;
    }

    int Quadrangle::get_angle_b()
    {
        return angle_b;
    }

    int Quadrangle::get_angle_c()
    {
        return angle_c;
    }

    int Quadrangle::get_angle_d()
    {
        return angle_d;
    }

    std::string Quadrangle::get_sides_info()  
    {
        return "a=" + std::to_string(side_a) + " b=" + std::to_string(side_b) + " c=" + std::to_string(side_c) + " d=" + std::to_string(side_d);
    }

    std::string Quadrangle::get_angles_info()
    {
        return "A=" + std::to_string(angle_a) + " B=" + std::to_string(angle_b) + " C=" + std::to_string(angle_c) + " D=" + std::to_string(angle_d);
    }

