#include "service_functions.h"

bool need_init_counter() //нужно ли инициализировать значение счетчика
{
    std::string yes_or_no_str = "";
    while ((yes_or_no_str != "да") && (yes_or_no_str != "нет"))
    {
        std::cout << "Вы хотите указать начальное значение счётчика ? Введите да или нет: ";
        std::cin >> yes_or_no_str;
        std::cout << "\n";

        if (yes_or_no_str == "да")
            return true;

        if (yes_or_no_str == "нет")
            return false;
    }
}

int  get_start_value()   //получить начальное значение счетчика
{
    std::cout << "Введите начальное значение счётчика: ";
    int start_value;     

    std::cin >> start_value;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Число введено некорректно. Стартовое значение счетчика принимается 0. \n";
        start_value = 0;        
    }

    return start_value;
}

counter_command get_command(Counter& counter) //получить команду для счетчика от пользователя
{

    std::string cmd_str = "";

    while (1)
    {
        std::cout << counter.invite_cmd_str;
        std::cin >> cmd_str;

        if (cmd_str == "+")
            return counter_command::plus;

        if (cmd_str == "-")
            return counter_command::minus;

        if (cmd_str == "=")
            return counter_command::equal;

        if ((cmd_str == "x") || (cmd_str == "х"))
            return counter_command::quit;
    }
}

void start_counter(Counter& counter) //цикл с использованием счетчика
{

    counter_command counter_cmd;

    while ((counter_cmd = get_command(counter)) != counter_command::quit)
    {
        switch (counter_cmd)
        {

        case counter_command::plus:
            counter.inc_value();
            break;
        case counter_command::minus:
            counter.dec_value();
            break;
        case counter_command::equal:
            std::cout << counter.get_value() << "\n";
            break;

        }
    }
    std::cout << "До свидания!\n";
}