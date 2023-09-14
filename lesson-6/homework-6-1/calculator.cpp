#include <iostream>
#include <math.h>
#include "calculator.h"

float add(float num_1, float num_2) //сложение
{
	return num_1 + num_2;
}

float subtract(float num_1, float num_2) //вычитание
{
	return num_1 - num_2;
}

float multiply(float num_1, float num_2) // умножение
{
	return num_1 * num_2;
}

bool divide(float num_1, float num_2, float* result) // деление
{
	if (num_2 == 0)
	{
		return false;
	}

	*result = num_1 / num_2;
	return true;
}

bool power(float num_1, float num_2, float* result) //  возведение в степень
{

   //возведение отрицательных значений в дробную степень
	if ((num_1 < 0)) 
	{
		int temp_int = static_cast<int>(num_2);		
		if ((num_2 - temp_int) != 0) //num_2 не целое
		{			
			return false;
		}
		
	}

	*result = pow(num_1, num_2);
	return true;
}
