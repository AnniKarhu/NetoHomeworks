// greaterClient.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "greater.h"
#include "leaver.h"

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");

    std::string name_str;
    std::cout << "Введите имя: ";
    std::cin >> name_str;

    Greeter gr;
    std::cout << gr.greet(name_str) << "\n";
    
    Leaver lv;
    std::cout << lv.leave(name_str) << "\n";

    return 0;
}
