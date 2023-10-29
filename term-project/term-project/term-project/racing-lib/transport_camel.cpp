#include "include/transport_camel.h"

Transport_camel::Transport_camel() : Transport_land(10, 30, 2)
{
	
	set_transport_name("Верблюд");

	//количество и время  разных типов остановок
	if (rests_array != nullptr) //вдруг память не выделилась
	{
		rests_array[0] = 5;
		rests_array[1] = 8;
	}
	

}



