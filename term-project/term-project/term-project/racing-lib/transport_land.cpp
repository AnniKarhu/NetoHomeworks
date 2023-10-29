#include "include/transport_land.h"

Transport_land::Transport_land(int new_speed, int new_move_time, int new_rests_array_size) : Transport(new_speed, transport_type::tr_type_land)
{
	set_move_time(new_move_time); //���������� ����� �������� �� ������
	set_rests_array_size(new_rests_array_size); //���������� � ���������� ������ ������������� ������
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

void Transport_land::set_rests_array_size(int new_rests_array_size) //���������� ������ ������� rests_array
{
	rests_array_size = new_rests_array_size;
}

int Transport_land::get_rests_array_size(int new_rests_array_size) //������ ������� rests_array
{
	return rests_array_size;
}

void Transport_land::set_move_time(int new_move_time) //���������� ����� �������� �� ������
{
	move_time = new_move_time;
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

	//static int array_index = 0; //������ ������ ���������
	double result = rests_array[rests_array_index];

	if (rests_array_index < (rests_array_size - 1)) //���� ��� �� ��������� ������� �������
	{
		++rests_array_index; //� ��������� ��� ������ ��������� �������
	}

	return result;
}

double Transport_land::calculate_total_distance_time(const double distance)
{	
	int temp_speed = get_tr_speed();  //��������
	int temp_move_time = get_move_time(); //����� �������� �� ���������

	//�������� � ����� �������� �� ��������� �� ����� ���� <= 0
	if ((temp_speed <= 0) ||   
		(temp_move_time <= 0))
	{
		return -1;
	}

	double temp_time; //����� �������� ��� ������
	temp_time = distance / get_tr_speed();

	int temp_rests; //������� ��� ����� ��������
	temp_rests = (temp_time / get_move_time()) - 1; //-1 - ��� ��� ���� ����� ����  ��������� � �������� �� ������, �� ����� ����� ��� �� ������ ������

	if (temp_time / get_move_time() - (static_cast<int>(temp_time) / get_move_time()) > 0) //���� ����� �� ������� �� ������
	{
		temp_rests += 1; //�������� ��� ��� ���������
	}
	
	for (int i = 0; i <= rests_array_size - 1; ++i) //��������� � ������������ �������� ������ ��������� � ������� rests_array, ������ �������� rests_array_size
	{
		temp_time += get_rest_time();
	}

	temp_rests -= rests_array_size; //������� ��������� � ���������� �������� ������
	temp_time += temp_rests * get_rest_time();

	return temp_time;

}