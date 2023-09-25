// homework-8-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

int function(std::string str, int forbidden_length); // длина переданной строки

class ForbiddenLengthException : public std::exception
{
public:
	const char* what() const override 
	{ 
		return "Вы ввели слово запретной длины! До свидания"; 
	}
};



int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");
	
	int forbidden_length = 0;
	std::cout << "Введите запретную длину: ";

	std::cin >> forbidden_length;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите запретную длину: ";
		std::cin >> forbidden_length;
	}

	std::string new_string;
	int new_str_lenght;

	while (1)
	{
		std::cout << "Введите слово: ";
		std::cin >> new_string;

		try
		{
			new_str_lenght = function(new_string, forbidden_length); // длина переданной строки
			
		}
		catch (const ForbiddenLengthException& ex)
		{
			std::cout << ex.what() << "\n";			
			return 1;

		}
		catch (...)
		{
			std::cout << "Неизвестная ошибка" << std::endl;
			return 2;
		}

		
		std::cout << "Длина слова \"" << new_string << "\" равна " << new_str_lenght << "\n";
	}

	

	
}

int function(std::string str, int forbidden_length) // длина переданной строки
{
	int str_length = str.length();
	if (str_length == forbidden_length)
	{
		throw ForbiddenLengthException();
	}

	return str_length;
}