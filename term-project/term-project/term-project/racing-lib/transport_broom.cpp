#include "include/transport_broom.h"

Transport_broom::Transport_broom() : Transport_air(20, 0)
{
	set_transport_name("�����");
}

int Transport_broom::get_reduction_factor(const double distance)  //����������� � ��������� ������� �� ���������
{
	if (red_factor_inc_distance == 0)
	{
		return 0;
	}	
	
	int distances_1000 = distance / red_factor_inc_distance;
	
	return distances_1000 * red_factor_inc;

}
