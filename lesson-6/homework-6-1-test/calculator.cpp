
#include <math.h>

float add(float num_1, float num_2); //сложение
float subtract(float num_1, float num_2); //вычитание
float multiply(float num_1, float num_2); // умножение, 
bool divide(float num_1, float num_2, float* result); // деление
bool power(float num_1, float num_2, float* result); //  возведение в степень.

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

	*result =  num_1 / num_2;
	return true;
}

bool power(float num_1, float num_2, float* result) //  возведение в степень
{
	

	if (num_1 < 0) //возведение в степень отризательных значений 
	{
		if (num_2 < 1) //из отрицательных чисел нельзя извлекать корень
		{
			return false;
		}
	}

	*result = pow(num_1, num_2);
	return true;
}

