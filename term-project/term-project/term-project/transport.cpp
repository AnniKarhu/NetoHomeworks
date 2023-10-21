#include "transport.h"
#include <iostream>
#include "transport_exception.h"

Transport::Transport()
{
	//tr_type = new_type;
	tr_speed = 1;
	result_time = -2;
}
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

double Transport::calculate_total_distance_time(double distance)
{
	//1. ����� ���������� ��� ������� �� 0 - �������� �� ����� ���� ����� 0 - ����������� �� ����� �������� �������
	//2. � ���� ������ ���������� ����/��������
	//3. � ������ ������� ���������

	return (distance / get_tr_speed());
}

bool Transport::get_active_for_racing() //��������� �� ������� � �����
{
	return active_for_racing;
}

void Transport::set_active_for_racing(bool new_active, double distance) //��������� �� ������� � ����� - ����������
{
	active_for_racing = new_active;
	
	if (new_active) //��������� ��������� � �����
	{
		//��������� � ��������� ����� ����������� ���������		
		result_time = calculate_total_distance_time(distance);
	}	
}

double Transport::get_distance_time() //������ ��������� �����
{
	return result_time;
}