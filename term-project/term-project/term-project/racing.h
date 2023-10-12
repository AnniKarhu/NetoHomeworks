#pragma once

#include "transport.h"

enum class race_type //возможные типы гонок
					{  
						race_type_land = 1, //гонка только для наземных
						race_type_air,  //гонка только для воздушных
						race_type_all   //гонка для всех
					 };

class Racing
{
private:
	int race_distance = 0;
	race_type my_race_type; //тип гонки
	int transports_array_size; //размер массива указателей на транспорты 
	Transport* transports_array[7]; //массив указателей на транспорты
	int transports_array_index = 0; //указатель на текущий  индекс массива transports_array
	int minimum_transports_number = 2; //минимальное количество транспортов для гонки
public: 
	Racing(race_type new_race_type, int new_distance);
	~Racing();

};


