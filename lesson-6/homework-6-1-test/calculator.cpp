
#include <math.h>

float add(float num_1, float num_2); //��������
float subtract(float num_1, float num_2); //���������
float multiply(float num_1, float num_2); // ���������, 
bool divide(float num_1, float num_2, float* result); // �������
bool power(float num_1, float num_2, float* result); //  ���������� � �������.

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

	*result =  num_1 / num_2;
	return true;
}

bool power(float num_1, float num_2, float* result) //  ���������� � �������
{
	

	if (num_1 < 0) //���������� � ������� ������������� �������� 
	{
		if (num_2 < 1) //�� ������������� ����� ������ ��������� ������
		{
			return false;
		}
	}

	*result = pow(num_1, num_2);
	return true;
}

