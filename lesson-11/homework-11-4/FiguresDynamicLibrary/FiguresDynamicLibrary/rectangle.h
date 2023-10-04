#pragma once
#include "quadrangle.h"


#ifdef RECTANGLE_DYN_LIB_EXPORTS
#define RECTANGLE_DYN_LIB_API __declspec(dllexport)
#else
#define RECTANGLE_DYN_LIB_API __declspec(dllimport)
#endif


//прямоугольник
class Rectangle : public Quadrangle
{
public:
    RECTANGLE_DYN_LIB_API  Rectangle(int a, int b); // : Quadrangle(a, b, a, b, 90, 90, 90, 90)
    
};