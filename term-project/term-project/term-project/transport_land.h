/*�������� ������������ ��������*/
#pragma once
#include "transport.h"

class Transport_land : public Transport
{
private:
	int move_time; //����� �������� �� ������
	
	
protected:
	int rests_array_size = 0; //������ ������� rests_array
	double* rests_array = nullptr; //������, ���������� ���������� �� ���������� ��� ������.
public:
	Transport_land(int new_speed, int new_move_time,  int new_rests_array_size);
	~Transport_land();
	int get_move_time();
	virtual int get_rest_time();

	double get_total_distance_time(double distance) override;
};
