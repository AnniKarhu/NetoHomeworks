#pragma once
#include "rectangle.h"

#ifdef SQUARE_DYN_LIB_EXPORTS
#define SQUARE_DYN_LIB_API __declspec(dllexport)
#else
#define SQUARE_DYN_LIB_API __declspec(dllimport)
#endif

//квадрат
class 	Square : public Rectangle
{
public:
	SQUARE_DYN_LIB_API  Square(int a); // : Rectangle(a, a)
   
};

