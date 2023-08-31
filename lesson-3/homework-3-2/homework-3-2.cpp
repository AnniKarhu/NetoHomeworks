// homework-3-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

enum class counter_command { quit = 0, plus, minus, equal };


class Counter
{
private:
    int value;


public:
    std::string invite_cmd_str = "Введите команду('+', '-', '=' или 'x') : ";

    Counter()
    {
        value = 1;
        // std::cout << "\n start value = 1\n";
    }

    Counter(int num)
    {
        value = num;
        // std::cout << "\n start value = " << value << "\n";
    }



    void inc_value()
    {
        ++value;
    }

    void dec_value()
    {
        --value;
    }

    int get_value()
    {
        return value;
    }
};

bool need_init_counter(); //нужно ли инициализировать значение счетчика
int  get_start_value();   //получить начальное значение счетчика
counter_command get_command(Counter& counter); //получить команду для счетчика от пользователя
void start_counter(Counter& counter); //цикл с использованием счетчика

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string yes_or_no_str = "";

    Counter* p_counter;

    if (need_init_counter()) //нужно ли инициализировать значение счетчика
    {
        p_counter = new Counter(get_start_value());   //получить начальное значение счетчика)
          
    }
    else
    {
        p_counter = new  Counter;   //дефолтное начальное значение счетчика ( =1)       
    }

    start_counter(*p_counter);

    delete p_counter;
    return 0;
}

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