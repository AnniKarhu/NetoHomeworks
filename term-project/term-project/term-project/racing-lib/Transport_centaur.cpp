#include "include/transport_centaur.h"

Transport_centaur::Transport_centaur() : Transport_land(15, 8, 1)
{
	set_transport_name("�������");

	//���������� � �����  ������ ����� ���������
	if (rests_array != nullptr) //����� ������ �� ����������
	{
		rests_array[0] = 2;
		
	}
}

