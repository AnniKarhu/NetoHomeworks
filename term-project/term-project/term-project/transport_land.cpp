#include "transport_land.h"

Transport_land::Transport_land(int new_speed, int new_move_time, int new_rests_array_size) : Transport(new_speed, transport_type::tr_type_land)
{
	move_time = new_move_time;
	rests_array_size = new_rests_array_size; //информация о количестве разных длительностей отдыха
	if (rests_array_size > 0)
	{
		rests_array = new double[rests_array_size];
	}
	set_transport_name("Наземное транспортное средство");
}

Transport_land::~Transport_land()
{
	delete[] rests_array;
}

int Transport_land::get_move_time()
{
	return  move_time;
}

int Transport_land::get_rest_time()
{
	if (rests_array == nullptr)  //массив не создан		
	{
		return 0;
	}

	static int array_index = 0; //индекс номера остановки
	double result = rests_array[array_index];

	if (array_index < (rests_array_size - 1)) //если это не последний элемент массива
	{
		++array_index; //в следующий раз выдать сделующий элемент
	}

	return result;
}

double Transport_land::calculate_total_distance_time(double distance)
{
	double temp_time; //время движения без отдыха
	temp_time = distance / get_tr_speed();

	int temp_rests; //сколько раз нужно отдыхать
	temp_rests = (temp_time / get_move_time()) - 1; //-1 - так как если время дист  совпадает с временем до отдыха, то отдых будет уже за линией финиша

	if ((temp_time / get_move_time()) > 0) //если чуток не хватило до финиша
	{
		temp_rests += 1; //придется еще раз отдохнуть
	}

	
	for (int i = 0; i < rests_array_size - 1; ++i) //остановки с отличающимся временем отдыха прописаны в массиве rests_array, размер которого rests_array_size
	{
		temp_time += get_rest_time();
	}

	temp_rests -= rests_array_size; //сколько остановок с одинаковым временем отдыха
	temp_time += temp_time * get_rest_time();

	return temp_time;

}