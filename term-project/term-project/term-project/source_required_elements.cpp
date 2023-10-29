#include "source_required_elements.h"

namespace racing_context
{

	race_type get_race_type(Racing* new_racing) //выбор пользователем типа гонки
	{
		int race_type_number = 0;

		while (race_type_number == 0)
		{
			std::cout << new_racing->race_type_invitation_string();
			std::cin >> race_type_number;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Неверный тип гонки \n";
				race_type_number = 0;
			}

			race_type race_type_temp = static_cast<race_type>(race_type_number);

			if ((race_type_number < 1) ||
				(race_type_number > 3))
			{
				std::cout << "Неверный тип гонки \n";
				race_type_number = 0;
			}
		}

		return static_cast<race_type>(race_type_number);

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

		std::cout << "\n";
		if (!temp_bool) // зарегистрировано ли минимальное число участников 
		{
			std::cout << "Должно быть зарегестрировано хотя бы " << new_racing->get_minimum_transports_number() << " транспортных средства\n";
		}

		std::cout << "1. Зарегистрировать транспорт\n";

		if (temp_bool)
		{
			std::cout << "2. Начать гонку\n";
		}

		while (!valid_action_before_racing(new_action, new_racing))	//valid_action_before_racing - является ли выбор действия  пользователем корректным
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
			register_transport(new_racing); //зарегестрировать транспорт на гонку		
		}
		else
			if (new_action == action_start_racing)
			{
				//перед выводом результатов нужно сортировать массив по времени
				new_racing->sort_transport_places();
				print_results(new_racing);
			}
	}

	void register_transport(Racing* new_racing) //зарегестрировать транспорт на гонку
	{
		while (1)
		{
			//вывести общую информацию по гонке
			switch (new_racing->get_race_type())
			{
			case race_type::race_type_land:
				std::cout << "Гонка для наземного транспорта. ";
				break;
			case race_type::race_type_air:
				std::cout << "Гонка для воздушного транспорта. ";
				break;
			case race_type::race_type_all:
				std::cout << "Гонка для наземного и воздушного транспорта. ";
				break;
			}

			std::cout << "Расстояние: " << new_racing->get_race_distance() << "\n";

			// вывести список уже зарегестрированных
			std::string temp_str = new_racing->get_registered_transports_list(); //список имен транспортов, зарегестрированных на гонку
			if (temp_str != "")
			{
				std::cout << "Зарегистрированные транспорты: " << temp_str << "\n";
			}

			//вывести список доступных для регистрации транспортов
			for (int i = 0; i < new_racing->get_available_transports_number(); ++i)
			{
				std::cout << i + 1 << ". " << new_racing->transport_name(i) << "\n"; //имя транспорта по индексу в массиве transports_array
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

			if (registration_action == 0)
			{
				return;
			}
			else
			{
				registration_status reg_status = new_racing->register_transport(registration_action - 1);
				std::cout << "\n";

				switch (reg_status)
				{
				case registration_status::reg_status_ok:
					std::cout << new_racing->transport_name(registration_action - 1) << " успешно зарегестрирован!\n";
					break;
				case registration_status::reg_status_second_attempt:
					std::cout << new_racing->transport_name(registration_action - 1) << " уже зарегестрирован!\n";
					break;
				case registration_status::reg_status_type_error:
					std::cout << "Попытка зарегестрировать неправильный тип транспортного средства!\n";
					break;
				}
			}
		}
	}

	void print_results(Racing* new_racing) //отобразить результаты гонок
	{
		std::cout << "Результаты гонки: \n";

		int counter = 1; //номер места
		for (int i = 0; i < new_racing->get_available_transports_number(); ++i) //перебрать массив транспортов гонки
		{
			double temp;
			temp = new_racing->transport_result(i); //прочитать время прохождения гонки
			if (temp > 0)  //транспорты, не участвующие в гонке, имеют время прохождения -1
			{
				std::cout << counter << ". " << new_racing->transport_name(i) << ". Время: " << temp << "\n";
				++counter; //увеличить номер места для следующего участника гонки
			}
		}
	}

	actions_after_racing get_racing_end_action() //выбор пользователем действий после гонкой
	{
		int new_action = -1;

		std::cout << "\n";
		std::cout << "1. Провести еще одну гонку\n";
		std::cout << "2. Выйти\n";

		while ((new_action <= 0) || (new_action > 2))
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

		return static_cast<actions_after_racing>(new_action);
	}

} // namespace racing_context
