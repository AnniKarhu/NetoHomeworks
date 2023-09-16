#include "counter.h"
#pragma once

enum class counter_command { quit = 0, plus, minus, equal };

bool need_init_counter(); //нужно ли инициализировать значение счетчика
int  get_start_value();   //получить начальное значение счетчика
counter_command get_command(Counter& counter); //получить команду для счетчика от пользователя
void start_counter(Counter& counter); //цикл с использованием счетчика