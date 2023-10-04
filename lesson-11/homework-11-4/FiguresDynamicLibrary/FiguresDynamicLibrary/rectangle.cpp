#include "rectangle.h"

//прямоугольник

    Rectangle::Rectangle(int a, int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90)
    {
        set_figure_name("Прямоугольник");
    }
