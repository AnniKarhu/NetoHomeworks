#include "include/transport_centaur.h"

Transport_centaur::Transport_centaur() : Transport_land(15, 8, 1)
{
	set_transport_name("Кентавр");

	//количество и время  разных типов остановок
	if (rests_array != nullptr) //вдруг память не выделилась
	{
		rests_array[0] = 2;
		
	}
}

