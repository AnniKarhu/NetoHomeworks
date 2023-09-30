// homework-9-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include "fraction.h"


int main()
{
	setlocale(LC_ALL, "rus");
	
	Fraction* num_f1 = nullptr;
	Fraction* num_f2 = nullptr;

	try
	{
		num_f1 = new Fraction(4, 3);
		num_f2 = new Fraction(6, 11);		

	}
	catch (FractionException& ex)
	{
		std::cout << ex.what();
		return 1;

	}
	catch (...)
	{
		std::cout << "Неизвестная ошибка\n";
		return 1;
	}
		
	std::cout << "f1 = " << num_f1->get_fraction_value() << "\n";
	std::cout << "f2 = " << num_f2->get_fraction_value() << "\n";
	std::cout << "\n";

	std::cout << "f1" << ((*num_f1 == *num_f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((*num_f1 != *num_f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((*num_f1 < *num_f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((*num_f1 > *num_f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((*num_f1 <= *num_f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((*num_f1 >= *num_f2) ? " >= " : " not >= ") << "f2" << '\n';

	delete num_f1;
	delete num_f2;
		
	return 0;
}