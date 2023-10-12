#include "transport_air.h"


Transport_air::Transport_air(int new_speed, int new_reduction_factor) : Transport(new_speed, transport_type::tr_type_air)
{
	reduction_factor = new_reduction_factor; //����������� ���������� ���������� - ��������� ��������
	set_transport_name("��������� ������������ ��������");
}


int Transport_air::get_reduction_factor(double distance)
{
	return reduction_factor; //����������� ���������� ����������
}

double Transport_air::get_total_distance_time(double distance)
{
	int red_ration = get_reduction_factor(distance); //�������� ����� �������� ����������� ���������� ����������

	double temp_distance = distance * (100 - red_ration)/100;

	return temp_distance / get_tr_speed();
}