#include "counter.h"
#pragma once

enum class counter_command { quit = 0, plus, minus, equal };

bool need_init_counter(); //����� �� ���������������� �������� ��������
int  get_start_value();   //�������� ��������� �������� ��������
counter_command get_command(Counter& counter); //�������� ������� ��� �������� �� ������������
void start_counter(Counter& counter); //���� � �������������� ��������