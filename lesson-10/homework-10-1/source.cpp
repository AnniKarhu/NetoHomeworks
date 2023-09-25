#include <iostream>
#include <Windows.h> 

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");

	//для ввода кириллицы с консоли
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//system("chcp 1251"); 

	std::string name_str;

	std::cout << "Введите имя: ";
	std::cin >> name_str;
	std::cout << "Здравствуйте, " << name_str << "!\n";


}