#include <iostream>
#include <Windows.h> 

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");

	//��� ����� ��������� � �������
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//system("chcp 1251"); 

	std::string name_str;

	std::cout << "������� ���: ";
	std::cin >> name_str;
	std::cout << "������������, " << name_str << "!\n";


}