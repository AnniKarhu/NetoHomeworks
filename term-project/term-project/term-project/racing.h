#pragma once

#include "transport.h"

enum class race_type //��������� ���� �����
					{  
						race_type_land = 1, //����� ������ ��� ��������
						race_type_air,  //����� ������ ��� ���������
						race_type_all   //����� ��� ����
					 };

class Racing
{
private:
	int race_distance = 0;
	race_type my_race_type; //��� �����
	int transports_array_size; //������ ������� ���������� �� ���������� 
	Transport* transports_array[7]; //������ ���������� �� ����������
	int transports_array_index = 0; //��������� �� �������  ������ ������� transports_array
	int minimum_transports_number = 2; //����������� ���������� ����������� ��� �����
public: 
	Racing(race_type new_race_type, int new_distance);
	~Racing();

};


