#include <iostream>
#include <string>
//#include <Windows.h>

#define NOMINMAX

#include "racing.h"
#include "transport_broom.h"
#include "transport_eagle.h"
#include "transport_magic_carpet.h"
#include "transport_crosscountry_boots.h"
#include "transport_centaur.h"
#include "transport_high_speed_camel.h"
#include "transport_camel.h"

int get_race_type_number(); //выбор пользователем типа гонки
int get_distance(); //выбор пользователем дистанции

int main()
{

	setlocale(LC_ALL, "rus");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	std::cout << "ƒобро пожаловать в гоночный симул€тор!\n";

	race_type new_race_type = static_cast<race_type> (get_race_type_number()); //выбор пользователем типа гонки
	int new_distance = get_distance(); //выбор пользователем дистанции

	Racing* new_racing;
	new_racing = new Racing(new_race_type, new_distance);

	delete new_racing;


	return 0;
}

int get_race_type_number() //выбор пользователем типа гонки
{
	int race_type_number = 0;

	while (race_type_number == 0)
	{
		std::cout << "1. √онка дл€ наземного транспорта \n";
		std::cout << "2. √онка дл€ воздушного транспорта \n";
		std::cout << "3. √онка дл€ наземного и воздушного транспорта \n";
		std::cout << "¬ыберите тип гонки: \n";
		std::cin >> race_type_number;

		if (std::cin.fail())
		{
			std::cin.clear();
			
			//#ifdef max //конфликт c max из Windows.h
			///#undef max
			//#endif

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ќеверный тип гонки \n";
			race_type_number = 0;
		}

		if ((race_type_number < 1) ||
			(race_type_number > 3))
		{
			std::cout << "Ќеверный тип гонки \n";
			race_type_number = 0;
		}
	}

	return race_type_number;

}

int get_distance() //выбор пользователем дистанции
{
	int new_distance = -1;

	while (new_distance < 0)
	{
		std::cout << "”кажите длину дистанции (должна быть положительна) \n";
		std::cin >> new_distance;

		if (std::cin.fail())
		{
			std::cin.clear();

			//#ifdef max //конфликт c max из Windows.h
			///#undef max
			//#endif

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ќеверна€ дистанци€ \n";
			new_distance = -1;
		}

		if (new_distance < 0) 
		{
			std::cout << "ƒистанци€ должна быть больше 0 \n";
			new_distance = -1;
		}
	}

	return new_distance;


}
