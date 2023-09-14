// homework-6-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "calculator.h"

bool get_number_from_user(float* num, std::string str); //получение числа от пользователя
void show_calculations(float num_1, float num_2); //отобразить результаты вычислений

int main()
{
    setlocale(LC_ALL, "rus");

    float num_1;
    float num_2;


    while (!get_number_from_user(&num_1, "Введите первое число: "))//получение числа от пользователя
    {
    };

    while (!get_number_from_user(&num_2, "Введите второе число: "))//получение числа от пользователя
    {
    };

    show_calculations(num_1, num_2); //отобразить результаты вычислений

    return 0;
}

bool get_number_from_user(float* num_1, std::string str) //получение числа от пользователя
{
    //  float temp = 0;
    std::cout << str;
    std::cin >> *num_1;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Число введено некорректно. Попробуйте еще. \n";
        *num_1 = 0.0;
        return false;
    }


    return true;
}

void show_calculations(float num_1, float num_2) //отобразить результаты вычислений
{
    
    
    bool power(float num_1, float num_2, float* result); //  возведение в степень.
    
    std::cout << num_1 << " + " << num_2 << " = " << add(num_1, num_2) << "\n"; //сложение
    std::cout << num_1 << " - " << num_2 << " = " << subtract(num_1, num_2) << "\n"; //вычитание
    std::cout << num_2 << " - " << num_1 << " = " << subtract(num_2, num_1) << "\n"; //вычитание
    std::cout << num_1 << " * " << num_2 << " = " << multiply(num_1, num_2) << "\n";// умножение 

    float result;

    if (divide(num_1, num_2, &result))
    {
        std::cout << num_1 << " / " << num_2 << " = " << result << "\n"; //вычитание
    }
    else
    {
        std::cout << "Деление " << num_1 << " на " << num_2 << " невозможно \n";
    }

    if (divide(num_2, num_1, &result))
    {
        std::cout << num_2 << " / " << num_1 << " = " << result << "\n"; //вычитание
    }
    else
    {
        std::cout << "Деление " << num_2 << " на " << num_1 << " невозможно \n";
    }

    if (power(num_1, num_2, &result))
    {
        std::cout << num_1 << " в степени " << num_2 << " = " << result << "\n";
    }
    else
    {
        std::cout << "Не умею возводить " << num_1 << " в степень " << num_2 << "\n";
    }

    if (power(num_2, num_1, &result))
    {
        std::cout << num_2 << " в степени " << num_1 << " = " << result << "\n";
    }
    else
    {
        std::cout << "Не умею возводить " << num_2 << " в степень " << num_1 << "\n";
    }
}

