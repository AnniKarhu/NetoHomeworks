#pragma once
#include "quadrangle.h"


//прямоугольник
class Rectangle : public Quadrangle
{
public:
    FIGURE_DYN_LIB_API  Rectangle(int a, int b); // : Quadrangle(a, b, a, b, 90, 90, 90, 90)
    
};