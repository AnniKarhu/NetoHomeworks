#include <iostream>
#include <math.h>
#include "calculator.h"

float add(float num_1, float num_2) //��������
{
	return num_1 + num_2;
}

float subtract(float num_1, float num_2) //���������
{
	return num_1 - num_2;
}

float multiply(float num_1, float num_2) // ���������
{
	return num_1 * num_2;
}

bool divide(float num_1, float num_2, float* result) // �������
{
	if (num_2 == 0)
	{
		return false;
	}

	*result = num_1 / num_2;
	return true;
}

bool power(float num_1, float num_2, float* result) //  ���������� � �������
{

   //���������� ������������� �������� � ������� �������
	if ((num_1 < 0)) 
	{
		int temp_int = static_cast<int>(num_2);		
		if ((num_2 - temp_int) != 0) //num_2 �� �����
		{			
			return false;
		}
		
	}

	*result = pow(num_1, num_2);
	return true;
}
