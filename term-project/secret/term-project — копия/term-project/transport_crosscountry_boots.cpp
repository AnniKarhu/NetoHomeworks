#include "transport_crosscountry_boots.h"


Transport_crosscountry_boots::Transport_crosscountry_boots() : Transport_land(6, 60, 2)
{	
	set_transport_name("�������-���������");

	//���������� � �����  ������ ����� ���������
	if (rests_array != nullptr) //����� ������ �� ����������
	{
		rests_array[0] = 10;
		rests_array[1] = 5;		
	}
}

