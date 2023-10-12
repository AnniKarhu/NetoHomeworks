/*��������� ������������ ��������*/
#pragma once
#include "transport.h"

class Transport_air : public Transport
{
private: 
	int reduction_factor; //����������� ���������� ����������
public:
	
	Transport_air(int new_speed, int new_reduction_factor);
	virtual int get_reduction_factor(double distance); //����������� ������� �� ���������
	double get_total_distance_time(double distance) override;
};
