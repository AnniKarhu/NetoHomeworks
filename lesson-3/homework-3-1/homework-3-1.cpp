// homework-3-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>



class Calculator
{
private:
    double num1 = 1;
    double num2 = 1;
    const std::string str_error = "Неверный ввод!\n";

public:
    const std::string str_num1 = "Введите num1: ";
    const std::string str_num2 = "Введите num2: ";

public:
    Calculator()
    {
        set_num1(num1);
        set_num2(num2);
    }

    double add() // метод должен возвращать результат сложения num1 и num2
    {
        return num1 + num2;
    }

    double multiply() // метод должен возвращать результат перемножения num1 и num2
    {
        return num1 * num2;
    }

    double subtract_1_2() // метод должен возвращать результат вычитания num2 из num1
    {
        return num1 - num2;
    }

    double subtract_2_1() // метод должен возвращать результат вычитания num1 из num2
    {
        return num2 - num1;
    }

    double divide_1_2() // метод должен возвращать результат деления num1 на num2
    {
        return num1 / num2;
    }

    double divide_2_1() // метод должен возвращать результат деления num2 на num1
    {
        return num2 / num1;
    }

    bool set_num1(double num1) // метод должен установить значение поля num1 равное значению аргумента num1 в случае, если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, в обратном случае false
    {
        if (num1)
        {
            this->num1 = num1;
            return true;
        }
        else
        {
            print_input_error();  //вывести сообщение о неверном вводе
            return false;
        }

    }

    bool set_num2(double num2) // метод должен установить значение поля num2 равное значению аргумента num2 в случае, если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, в обратном случае false
    {
        if (num2)
        {
            this->num2 = num2;
            return true;
        }
        else
        {
            print_input_error();  //вывести сообщение о неверном вводе
            return false;
        }
    }

    void print_input_error()  //вывести сообщение о неверном вводе
    {
        std::cout << str_error;
    }

    void print_calculations()
    {
        std::cout << "num1 + num2 = " << add() << "\n";
        std::cout << "num1 - num2 = " << subtract_1_2() << "\n";
        std::cout << "num2 - num1 = " << subtract_2_1() << "\n";
        std::cout << "num1 * num2 = " << multiply() << "\n";
        std::cout << "num1 / num2 = " << divide_1_2() << "\n";
        std::cout << "num2 / num1 = " << divide_2_1() << "\n";
    }

};

double get_num(std::string str); //ввод числа с консоли

int main()
{
    setlocale(LC_ALL, "rus");

    double n1 = 0;
    double n2 = 0;

    Calculator calculator_1;

    while (1)
    {
        while (!(calculator_1.set_num1(get_num(calculator_1.str_num1))))
        {
        };

        while (!(calculator_1.set_num2(get_num(calculator_1.str_num2))))
        {
        };

        calculator_1.print_calculations();

    }

};

double get_num(std::string str) //ввод числа с консоли
{
    double num;
    std::cout << str; // сообщение для пользователя
    std::cin >> num;  //to-do - как проверить, что пользователь ввел число?
    return num;
}





