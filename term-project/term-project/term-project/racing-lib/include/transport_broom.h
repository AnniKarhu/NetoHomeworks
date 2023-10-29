#pragma once

#include "transport_air.h"

class Transport_broom : public Transport_air
{
private:
	int red_factor_inc = 1; //�� ������� ��������� ������������� ����������� ���������� ���������� � ����������� �� ��������� - red_factor_inc_distance
	int red_factor_inc_distance = 1000; //����� ���������� �������� � ���������� ������������ ���������� ���������� �� red_factor_inc ���������

public:
	Transport_broom();
	
	int get_reduction_factor(const double distance) override; //����������� ������� �� ���������
};
