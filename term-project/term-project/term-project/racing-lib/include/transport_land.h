/*�������� ������������ ��������*/
#pragma once
#include "transport.h"

class Transport_land : public Transport
{
private:
	int move_time; //����� �������� �� ������
	int rests_array_index = 0; //������ ������ ���������
	int rests_array_size = 0; //������ ������� rests_array
	
	void set_move_time(int new_move_time); //���������� ����� �������� �� ������
	void set_rests_array_size(int new_rests_array_size); //���������� ������ ������� rests_array

protected:
	double* rests_array = nullptr; //������, ���������� ���������� �� ���������� ��� ������.
	int get_rests_array_size(int new_rests_array_size); //������ ������� rests_array
	
public:
	Transport_land(int new_speed, int new_move_time,  int new_rests_array_size);
	~Transport_land() override; 
	int get_move_time();
	virtual int get_rest_time();

	double calculate_total_distance_time(const double distance) override;
};
