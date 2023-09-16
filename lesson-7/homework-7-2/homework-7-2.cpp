// homework-7-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.



#include <iostream>
#define SUB(a,b) ((a) - (b))


int main()
{
	int a = 6;
	int b = 5;
	int c = 2;
	std::cout << SUB(a, b) << std::endl;
	std::cout << SUB(a, b) * c << std::endl;
	std::cout << SUB(a, b + c) * c << std::endl;
}

