#pragma once
#include "parallelogram.h"


#ifdef DIAMOND_DYN_LIB_EXPORTS
#define DIAMOND_DYN_LIB_API __declspec(dllexport)
#else
#define DIAMOND_DYN_LIB_API __declspec(dllimport)
#endif



//ромб
class Diamond : public Parallelogram
{
public:
	DIAMOND_DYN_LIB_API Diamond(int a, int A, int B); // : Parallelogram(a, a, A, B)
   

};
