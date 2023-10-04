#pragma once
#include "quadrangle.h"

#ifdef PARALLELOGRAM_DYN_LIB_EXPORTS
#define PARALLELOGRAM_DYN_LIB_API __declspec(dllexport)
#else
#define PARALLELOGRAM_DYN_LIB_API __declspec(dllimport)
#endif


//ןאנאככוכמדנאלל
class Parallelogram : public Quadrangle
{
public:
    PARALLELOGRAM_DYN_LIB_API  Parallelogram(int a, int b, int A, int B); // : Quadrangle(a, b, a, b, A, B, A, B)
    
};
