#include "transport.h"
#include <iostream>
#include "transport_exceptions.h"

Transport::Transport(int new_speed, transport_type new_type)

{
	//�������� �� ����� ���� ������ ��� ������ 0
	if (new_speed <= 0)
	{
		throw TransportException("������ �������� ���������� -  \"" + get_tr_name() + "\". ��������� ����������������� � ����� �� ������������ ��������");
	}

	tr_type = new_type;
	tr_speed = new_speed;	
}
int Transport::get_tr_speed()
{
	return tr_speed;
}

std::string Transport::get_tr_name()
{
	return tr_name;
}

transport_type Transport::get_tr_type()
{
	return tr_type;
}

void Transport::set_transport_name(std::string new_name)
{
	tr_name = new_name;
}

double Transport::get_total_distance_time(double distance)
{
	//1. ����� ���������� ��� ������� �� 0 - �������� �� ����� ���� ����� 0 - ����������� �� ����� �������� �������
	//2. � ���� ������ ���������� ����/��������
	//3. � ������ ������� ���������

	return (distance / get_tr_speed());
}