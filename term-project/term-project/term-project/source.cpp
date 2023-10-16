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

enum actions_before_racing { action_incorrect = -1, action_register_transport = 1, action_start_racing };
enum actions_after_racing  { action_incorrect = -1, action_new_racing = 1, action_exit};

int get_race_type_number(Racing* new_racing); //выбор пользователем типа гонки
int get_distance(Racing* new_racing); //выбор пользователем дистанции
actions_before_racing get_racing_start_action(Racing* new_racing); //выбор пользователем действий перед гонкой
bool valid_action_before_racing(int new_action, Racing* new_racing); //является ли выбор действия  пользователем корректным
void execute_action_before_racing(actions_before_racing new_action, Racing* new_racing); //выполнить действие, выбранное пользователем перед гонкой

int main()
{

	setlocale(LC_ALL, "rus");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	std::cout << "Добро пожаловать в гоночный симулятор!\n";

	Racing* new_racing;
	new_racing = new Racing();

	race_type new_race_type = static_cast<race_type> (get_race_type_number(new_racing)); //выбор пользователем типа гонки
	new_racing->set_race_type(new_race_type);
	int new_distance = get_distance(new_racing); //выбор пользователем дистанции
	new_racing->set_race_distance(new_distance);


	//выбор действия пользователем
	actions_before_racing new_action = actions_before_racing::action_incorrect;  // номер выбранного действия
	new_action = get_racing_start_action(new_racing); //выбор пользователем действий перед гонкой
	
	execute_action_before_racing(new_action, new_racing); //выполнить действие, выбранное пользователем перед гонкой
		



	
	
	

	delete new_racing;


	return 0;
}

int get_race_type_number(Racing* new_racing) //выбор пользователем типа гонки
{
	int race_type_number = 0;

	while (race_type_number == 0)
	{
		//std::cout << "1. Гонка для наземного транспорта \n";
		//std::cout << "2. Гонка для воздушного транспорта \n";
		//std::cout << "3. Гонка для наземного и воздушного транспорта \n";
		//std::cout << "Выберите тип гонки: ";
		std::cout << new_racing->race_type_invitation_string();
		std::cin >> race_type_number;

		if (std::cin.fail())
		{
			std::cin.clear();
			
			//#ifdef max //конфликт c max из Windows.h
			///#undef max
			//#endif

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Неверный тип гонки \n";
			race_type_number = 0;
		}

		if ((race_type_number < 1) ||
			(race_type_number > 3))
		{
			std::cout << "Неверный тип гонки \n";
			race_type_number = 0;
		}
	}

	return race_type_number;

}

int get_distance(Racing* new_racing) //выбор пользователем дистанции
{
	int new_distance = -1;

	while (new_distance < 0)
	{
		std::cout << new_racing->race_distance_invitation_string(); //"Укажите длину дистанции (должна быть положительна) \n";
		std::cin >> new_distance;

		if (std::cin.fail())
		{
			std::cin.clear();

			//#ifdef max //конфликт c max из Windows.h
			///#undef max
			//#endif

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Неверная дистанция \n";
			new_distance = -1;
		}

		if (new_distance < 0) 
		{
			std::cout << "Дистанция должна быть больше 0 \n";		
		}
	}

	return new_distance;

}

actions_before_racing get_racing_start_action(Racing* new_racing) //выбор пользователем действий перед гонкой
{
	int new_action = -1;
	bool temp_bool = new_racing->get_racing_registered_transports(); //проверка, зарегистрировано ли минимальное число участников 

	if (!temp_bool) // зарегистрировано ли минимальное число участников 
	{
			std::cout << "Должно быть зарегестрировано хотя бы " << new_racing->get_minimum_transports_number() << " транспортных средства\n";
	}

	std::cout << "1. Зарегистрировать транспорт\n";

	if (temp_bool)
	{
			std::cout << "2. Начать гонку\n";
	}
	

	//while (new_action < 0) 
	while(!valid_action_before_racing(new_action, new_racing))	//valid_action_before_racing - является ли выбор действия  пользователем корректным
	{
		std::cout << "Выберите действие: ";
		std::cin >> new_action;
		
		if (std::cin.fail())
		{
			std::cin.clear();

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Неверный ввод \n";
			new_action = -1;
		}
		std::cout << "\n";
	}	

	return static_cast<actions_before_racing>(new_action); 
	
}

bool valid_action_before_racing(int new_action, Racing* new_racing) //является ли выбор действия  пользователем корректным
{
	switch (new_action)
	{
		case 1: return true; //всегда можно отобразить процесс регистрации
		case 2: //можно ли начинать гонку
		
			{
			if (new_racing->get_racing_registered_transports()) //проверка, зарегистрировано ли минимальное число участников 
			{
				return true;
			}
			else
			{
				return false;
			}
		default: return false; //никакие другие действия не предусмотрены
		 
		}
	}
}

void execute_action_before_racing(actions_before_racing new_action, Racing* new_racing) //выполнить действие, выбранное пользователем перед гонкой
{
	if (new_action == action_register_transport) //регистрация транспорта на гонку
	{ 		
		// вывести список уже зарегестрированных
		std::string temp_str = new_racing->get_registered_transports_list(); //список имен транспортов, зарегестрированных на гонку
		if (temp_str != "")
		{
			std::cout << "Зарегистрированные транспорты: " << temp_str << "\n";
		}

		//вывести список доступных для регистрации транспортов
		for (int i = 0; i < new_racing->get_available_transports_number(); ++i)
		{
			std::cout << i << ". " << new_racing->transport_name(i) << "\n"; //имя транспорта по индексу в массиве transports_array
		}

		std::cout << "0. Закончить регистрацию\n";
		std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";

		//число, выбранное пользователем
		int registration_action = -1;
		while (registration_action < 0)
		{
			std::cin >> registration_action;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Неверный ввод \n";
				registration_action = -1;
			}

			if (registration_action > new_racing->get_available_transports_number())
			{
				std::cout << "Такого транспорта нет. Выберите номер транспорта из списка или 0 для завершения регистрации. \n";
				registration_action = -1;
			}

			
		}
		
	}

	if (new_action == action_start_racing)
	{
		//старт гонки - 
		//напечатать результаты транспортов предварительно отсортировав их по увеличению результата
	}
}