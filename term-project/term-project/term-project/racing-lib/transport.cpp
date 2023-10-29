
#include <iostream>

#include "include/transport.h"
#include "include/transport_exception.h"

//конструктор со списком инициализации
Transport::Transport(): tr_speed(1)
{
	
}

Transport::~Transport()
{

}

Transport::Transport(int new_speed, transport_type new_type)
{
	SetSpeed(new_speed);
	SetType(new_type);		
}
int Transport::get_tr_speed()
{
	return tr_speed;
}

std::string Transport::get_tr_name()
{
	return tr_name;
}

transport_type Transport::get_tr_type()
{
	return tr_type;
}

void Transport::set_transport_name(std::string new_name)
{
	tr_name = new_name;
}

void Transport::SetSpeed(int new_speed) //установить скорость
{	
	//скорость не может быть равной или меньше 0
	if (new_speed <= 0)
	{
		//throw TransportException("Ошибка создания транспорта -  \"" + get_tr_name() + "\". Транспорт дисквалифицирован с гонки за несоблюдение скорости");
		new_speed = 1;
	}
	tr_speed = new_speed;
}

void Transport::SetType(transport_type new_type) //установить тип транспорта
{
	tr_type = new_type;
}


double Transport::calculate_total_distance_time(const double distance)
{
	//1. класс исключения для деления на 0 - скорость не может быть равно 0 - проверяется на этапе создания объекта
	//2. в этом классе возвращать дист/скорость
	//3. в других классах подменить
	
	int temp_speed = get_tr_speed();

	if (temp_speed <= 0)
	{
		return -1;
	}

	return (distance / temp_speed);
}

bool Transport::get_active_for_racing() //принимает ли участие в гонке
{
	return active_for_racing;
}

void Transport::set_active_for_racing(bool new_active, const double distance) //принимает ли участие в гонке - установить
{
	active_for_racing = new_active;
	
	if (new_active) //транспорт участвует в гонке
	{
		//вычислить и сохранить время прохождения дистанции		
		result_time = calculate_total_distance_time(distance);
	}	
}

double Transport::get_distance_time() //узнать результат гонки
{
	return result_time;
}