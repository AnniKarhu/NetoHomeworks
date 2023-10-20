#pragma once

#include "transport.h"
#include "racing_exceptions.h"
#include "transport_exceptions.h"

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
	int race_distance = 0;
	race_type my_race_type; //тип гонки
	int transports_array_size = 7; //размер массива указателей на транспорты 
	Transport* transports_array[8] = {}; //массив указателей на транспорты - на 1 больше, чтобы не вылезать за границу массива при сортировке
	double* result_time_array[7];
	//int transports_array_index = -1; //указатель на текущий  индекс массива transports_array
	int minimum_transports_number = 2; //минимальное количество транспортов для гонки

	
    int pivoting(Transport** arr, int size, int pi); //пивотирование
	void sort_transport_array(Transport** arr, int size); //отсортировать массив по возрастанию времени прохождения гонки
	void sort_transport_array2(Transport** arr, int size); //отсортировать массив по возрастанию времени прохождения гонки
public: 
	Racing(race_type new_race_type, int new_distance);
	Racing();
	
	~Racing();
	void set_race_type(race_type new_race_type); //указать тип гонки
	race_type get_race_type(); //получить тип гонки
	void set_race_distance(int new_distance); //указать дистанцию
	int get_race_distance(); //получить дистанцию
	std::string race_type_name(race_type race_type_x); //название гонки по ее типу
	std::string race_type_invitation_string(); //приглашение выбрать тип гонки
	std::string race_distance_invitation_string(); //приглашение выбрать дистанцию гонки
	bool get_racing_registered_transports(); //проверка, зарегистрировано ли минимальное число участников 
	int get_minimum_transports_number(); //минимальное количество транспортов для гонки
	int get_available_transports_number(); //сколько всего возможно участников - размер массива transports_array = transports_array_size
	std::string transport_name(int arr_index); //имя транспорта по индексу в массиве transports_array
	double transport_result(int arr_index); //результат (время прохождения дистанции) транспорта по индексу в массиве transports_array
	std::string get_registered_transports_list(); //список имен транспортов, зарегестрированных на гонку
	registration_status register_transport(int index); //зарегестрировать транспорт на гонку
	void sort_transport_places(); //распределить места 
	
	void swap(int i, int j); //поменять местами
};



