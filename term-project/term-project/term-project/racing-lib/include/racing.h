#pragma once

#include "transport.h"
#include "racing_exception.h"
#include "transport_exception.h"

enum class race_type //возможные типы гонок
					{  
						race_type_land = 1, //гонка только для наземных
						race_type_air,  //гонка только для воздушных
						race_type_all   //гонка для всех
					 };

enum class registration_status  //возможные результаты регистрации
								{
									reg_status_ok,				//успешно зарегестрирован
									reg_status_second_attempt, //попытка зарегестрировать транспорт второй раз
									reg_status_type_error		//транспорт не подходит для этого типа гонок
								};


class Racing
{
private:
	bool racing_ready = false; //объект racing готов к использованию только после завершения инициализации 
	race_type my_race_type; //тип гонки
	int race_distance = 0;  //дистанция гонки
	const int minimum_transports_number = 2; //минимальное количество транспортов для гонки

	const int transports_array_size = 7; //размер массива указателей на транспорты 
	Transport* transports_array[7] = {}; //массив указателей на транспорты - на 1 больше, чтобы не вылезать за границу массива при сортировке	
	
	//сортировка результатов
	void sort_transport_array(Transport** arr, int left, int right); //отсортировать массив по возрастанию времени прохождения гонки
	int pivoting(Transport** arr, int left, int right); //пивотирование
	void swap_transports(int i, int j); //поменять местами транспорты с индексами i и j
public: 
	explicit Racing(race_type new_race_type, int new_distance);
	Racing();	
	~Racing();

	void racing_init(); //инициализация гонки - заполнение массива участников объектами класса Transport
	bool get_racing_ready(); //готов ли объект racing  к использованию

	//тип гонки
	void set_race_type(race_type new_race_type); //указать тип гонки
	race_type get_race_type(); //получить тип гонки

	//дистанция
	void set_race_distance(int new_distance); //указать дистанцию
	int get_race_distance(); //получить дистанцию

	std::string race_type_name(race_type race_type_x); //название гонки по ее типу
	std::string race_type_invitation_string(); //приглашение выбрать тип гонки
	std::string race_distance_invitation_string(); //приглашение выбрать дистанцию гонки
	std::string get_registered_transports_list(); //список имен транспортов, зарегестрированных на гонку
	std::string transport_name(int arr_index); //имя транспорта по индексу в массиве transports_array

	bool get_racing_registered_transports(); //проверка, зарегистрировано ли минимальное число участников 
	int get_minimum_transports_number(); //минимальное количество транспортов для гонки
	int get_available_transports_number(); //сколько всего возможно участников - размер массива transports_array = transports_array_size	
	
	registration_status register_transport(int index); //зарегестрировать транспорт на гонку
	double transport_result(int arr_index); //результат (время прохождения дистанции) транспорта по индексу в массиве transports_array
	void sort_transport_places(); //распределить места		
	
};



