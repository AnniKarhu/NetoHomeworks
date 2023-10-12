#include "racing.h"

Racing::Racing(race_type new_race_type, int new_distance)
{
	my_race_type = new_race_type;
	race_distance = new_distance;
		
}

Racing::~Racing()
{
	//очистка памяти от зарегистрированных на гонку транспортов
	for (int i = 0; i < transports_array_size; ++i)
	{
		if (transports_array[i] != nullptr)
		{
			delete transports_array[i];
			transports_array[i] = nullptr;
		}
	}
	
}