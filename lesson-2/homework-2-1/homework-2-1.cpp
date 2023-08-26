// homework-2-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>



enum class months {January = 1, February, March, April, May, June, July, August, September, October, November, December};
void print_month(months m_num); //вывод месяца по его номеру

int main()
{
	setlocale(LC_ALL, "Russian");

	int month_num = -1;

	while (month_num)
	{
		std::cout << "Введите номер месяца: ";
		std::cin >> month_num;

		if (month_num == 0)
		{
			std::cout << "До свидания!\n";
		} else
		if ((month_num < 0) || (month_num > 12))
		{
			std::cout << "Неправильный номер!\n";
		}
		else
		{
			print_month(static_cast<months> (month_num)); //вывод месяца по его номеру
		}

	}	
	
}

void print_month(months m_num) //вывод месяца по его номеру
{
	switch (m_num)
	{
		case(months::January):
			std::cout << "Январь\n";
			break;
		case(months::February):
			std::cout << "Февраль\n";
			break;
		case(months::March):
			std::cout << "Март\n";
			break;
		case(months::April):
			std::cout << "Апрель\n";
			break;
		case(months::May):
			std::cout << "Май\n";
			break;
		case(months::June):
			std::cout << "Июнь\n";
			break;
		case(months::July):
			std::cout << "Июль\n";
			break;
		case(months::August):
			std::cout << "Август\n";
			break;
		case(months::September):
			std::cout << "Сентябрь\n";
			break;
		case(months::October):
			std::cout << "Октябрь\n";
			break;
		case(months::November):
			std::cout << "Ноябрь\n";
			break;
		case(months::December):
			std::cout << "Декабрь\n";
			break;
	}
	
	return;
}