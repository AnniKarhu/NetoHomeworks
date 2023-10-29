#include "include/transport_air.h"


Transport_air::Transport_air(int new_speed, int new_reduction_factor) : Transport(new_speed, transport_type::tr_type_air)
{
	set_reduction_factor(new_reduction_factor); //����������� ���������� ���������� - ��������� ��������
	set_transport_name("��������� ������������ ��������");
}

Transport_air::~Transport_air()
{

}

int Transport_air::get_reduction_factor(const double distance)
{
	return reduction_factor; //����������� ���������� ����������
}

void Transport_air::set_reduction_factor(int new_reduction_factor) //���������� ����������� ���������� ����������
{
	reduction_factor = new_reduction_factor;
}

double Transport_air::calculate_total_distance_time(const double distance)
{	
	int red_ration = get_reduction_factor(distance); //�������� ����� �������� ����������� ���������� ����������

	double temp_distance = distance * (100 - red_ration)/100;

	int temp_speed = get_tr_speed();
	if (temp_speed <= 0)
	{
		return -1;
	}

	return (temp_distance / get_tr_speed());
}