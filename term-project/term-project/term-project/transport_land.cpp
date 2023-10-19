#include "transport_land.h"

Transport_land::Transport_land(int new_speed, int new_move_time, int new_rests_array_size) : Transport(new_speed, transport_type::tr_type_land)
{
	move_time = new_move_time;
	rests_array_size = new_rests_array_size; //���������� � ���������� ������ ������������� ������
	if (rests_array_size > 0)
	{
		rests_array = new double[rests_array_size];
	}
	set_transport_name("�������� ������������ ��������");
}

Transport_land::~Transport_land()
{
	delete[] rests_array;
}

int Transport_land::get_move_time()
{
	return  move_time;
}

int Transport_land::get_rest_time()
{
	if (rests_array == nullptr)  //������ �� ������		
	{
		return 0;
	}

	static int array_index = 0; //������ ������ ���������
	double result = rests_array[array_index];

	if (array_index < (rests_array_size - 1)) //���� ��� �� ��������� ������� �������
	{
		++array_index; //� ��������� ��� ������ ��������� �������
	}

	return result;
}

double Transport_land::calculate_total_distance_time(double distance)
{
	double temp_time; //����� �������� ��� ������
	temp_time = distance / get_tr_speed();

	int temp_rests; //������� ��� ����� ��������
	temp_rests = (temp_time / get_move_time()) - 1; //-1 - ��� ��� ���� ����� ����  ��������� � �������� �� ������, �� ����� ����� ��� �� ������ ������

	if ((temp_time / get_move_time()) > 0) //���� ����� �� ������� �� ������
	{
		temp_rests += 1; //�������� ��� ��� ���������
	}

	
	for (int i = 0; i < rests_array_size - 1; ++i) //��������� � ������������ �������� ������ ��������� � ������� rests_array, ������ �������� rests_array_size
	{
		temp_time += get_rest_time();
	}

	temp_rests -= rests_array_size; //������� ��������� � ���������� �������� ������
	temp_time += temp_time * get_rest_time();

	return temp_time;

}