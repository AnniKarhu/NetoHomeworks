#include "transport_crosscountry_boots.h"


Transport_crosscountry_boots::Transport_crosscountry_boots() : Transport_land(6, 60, 2)
{	
	set_transport_name("Ѕотинки-вездеходы");

	//количество и врем€  разных типов остановок
	if (rests_array != nullptr) //вдруг пам€ть не выделилась
	{
		rests_array[0] = 10;
		rests_array[1] = 5;		
	}
}

