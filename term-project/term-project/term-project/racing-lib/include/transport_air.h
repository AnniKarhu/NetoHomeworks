/*��������� ������������ ��������*/
#pragma once
#include "transport.h"

class Transport_air : public Transport
{
private: 
	int reduction_factor; //����������� ���������� ����������
	void set_reduction_factor(int new_reduction_factor); //���������� ����������� ���������� ����������
public:
	
	Transport_air(int new_speed, int new_reduction_factor);
	~Transport_air() override;  
	virtual int get_reduction_factor(const double distance); //����������� ������� �� ���������
	double calculate_total_distance_time(const double distance) override;
};
