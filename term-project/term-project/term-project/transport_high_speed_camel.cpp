#include "transport_high_speed_camel.h"

Transport_high_speed_camel::Transport_high_speed_camel() : Transport_land(40, 10, 3)
{
	set_transport_name("�������-���������");

	//���������� � �����  ������ ����� ���������
	if (rests_array != nullptr) //����� ������ �� ����������
	{
		rests_array[0] = 5;
		rests_array[1] = 6.5;
		rests_array[2] = 8;
	}
}

