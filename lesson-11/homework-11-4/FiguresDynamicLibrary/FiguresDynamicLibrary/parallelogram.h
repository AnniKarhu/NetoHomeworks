#pragma once
#include "quadrangle.h"


//��������������
class Parallelogram : public Quadrangle
{
public:
    FIGURE_DYN_LIB_API  Parallelogram(int a, int b, int A, int B); // : Quadrangle(a, b, a, b, A, B, A, B)
    
};
