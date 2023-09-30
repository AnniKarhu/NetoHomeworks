// homework-9-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include "fraction.h"
void get_int_number(std::string invite_str, int& int_num); //получить от пользователя число интеджер

int main()
{
    
    setlocale(LC_ALL, "rus");

    int numerator_1, numerator_2, denominator_1, denominator_2;

    get_int_number("Введите числитель дроби 1: ", numerator_1); //получить от пользователя число интеджер
    get_int_number("Введите знаменатель дроби 1: ", denominator_1); //получить от пользователя число интеджер
    get_int_number("Введите числитель дроби 2: ", numerator_2); //получить от пользователя число интеджер
    get_int_number("Введите знаменатель дроби 2: ", denominator_2); //получить от пользователя число интеджер

   
    Fraction* num_1 = nullptr;
    Fraction* num_2 = nullptr;

    try
    {
        num_1 = new Fraction(numerator_1, denominator_1);
        num_2 = new Fraction(numerator_2, denominator_2);

        /*Fraction f1(numerator_1, denominator_1);
        num_1 = &f1;

        Fraction f2(numerator_2, denominator_2);
        num_2 = &f2;*/
    }
    catch (FractionException& ex)
    {
        std::cout << ex.what();
        return 1;
    }
    catch (...)
    {
        std::cout << "Неизвестная ошибка";
        return 1;
    }

    std::cout << "Первое число f1 = " << num_1->get_fraction_value() << "\n";
    std::cout << "Второе число f2 = " << num_2->get_fraction_value() << "\n";

    std::cout << num_1->print_fraction() << " + " << num_2->print_fraction() << " = " << (*num_1 + *num_2).print_fraction() << "\n";
    std::cout << num_1->print_fraction() << " - " << num_2->print_fraction() << " = " << (*num_1 - *num_2).print_fraction() << "\n";
    std::cout << num_1->print_fraction() << " * " << num_2->print_fraction() << " = " << (*num_1 * *num_2).print_fraction() << "\n";
    std::cout << num_1->print_fraction() << " / " << num_2->print_fraction() << " = " << (*num_1 / *num_2).print_fraction() << "\n";
    
    std::cout << "-(" << num_1->print_fraction() << ") = ";
    std::cout << (-(*num_1)).print_fraction() << "\n";

    std::cout << "++" << num_1->print_fraction() << " * " << num_2->print_fraction() << " = ";
    std::cout << (++(*num_1) * (*num_2)).print_fraction() << "\n";

    std::cout << "Значение дроби 1 = " << num_1->print_fraction() << "\n";
    std::cout << num_1->print_fraction() << "--" << " * " << num_2->print_fraction() << " = ";
    std::cout << ((*num_1)-- * (*num_2)).print_fraction() << "\n";
    std::cout << "Значение дроби 1 = " << num_1->print_fraction() << "\n";

    delete num_1;
    delete num_2;

    return 0;
}

void get_int_number(std::string invite_str, int& int_num) //получить от пользователя число интеджер
{
    std::cout << invite_str;
    std::cin >> int_num;

    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << invite_str;
        std::cin >> int_num;
    }

    return;
}