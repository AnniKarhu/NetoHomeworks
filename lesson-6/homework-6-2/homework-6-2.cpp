// homework-6-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <Windows.h>
#include "counter.h"
#include "service_functions.h"




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

