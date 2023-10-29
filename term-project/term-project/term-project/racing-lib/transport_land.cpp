#include "include/transport_land.h"

Transport_land::Transport_land(int new_speed, int new_move_time, int new_rests_array_size) : Transport(new_speed, transport_type::tr_type_land)
{
	set_move_time(new_move_time); //установить время движения до отдыха
	set_rests_array_size(new_rests_array_size); //информация о количестве разных длительностей отдыха
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

void Transport_land::set_rests_array_size(int new_rests_array_size) //установить размер массива rests_array
{
	rests_array_size = new_rests_array_size;
}

int Transport_land::get_rests_array_size(int new_rests_array_size) //размер массива rests_array
{
	return rests_array_size;
}

void Transport_land::set_move_time(int new_move_time) //установить время движения до отдыха
{
	move_time = new_move_time;
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

	//static int array_index = 0; //индекс номера остановки
	double result = rests_array[rests_array_index];

	if (rests_array_index < (rests_array_size - 1)) //если это не последний элемент массива
	{
		++rests_array_index; //в следующий раз выдать сделующий элемент
	}

	return result;
}

double Transport_land::calculate_total_distance_time(const double distance)
{	
	int temp_speed = get_tr_speed();  //скорость
	int temp_move_time = get_move_time(); //время движения до остановки

	//скорость и время движения до остановки не могут быть <= 0
	if ((temp_speed <= 0) ||   
		(temp_move_time <= 0))
	{
		return -1;
	}

	double temp_time; //время движения без отдыха
	temp_time = distance / get_tr_speed();

	int temp_rests; //сколько раз нужно отдыхать
	temp_rests = (temp_time / get_move_time()) - 1; //-1 - так как если время дист  совпадает с временем до отдыха, то отдых будет уже за линией финиша

	if (temp_time / get_move_time() - (static_cast<int>(temp_time) / get_move_time()) > 0) //если чуток не хватило до финиша
	{
		temp_rests += 1; //придется еще раз отдохнуть
	}
	
	for (int i = 0; i <= rests_array_size - 1; ++i) //остановки с отличающимся временем отдыха прописаны в массиве rests_array, размер которого rests_array_size
	{
		temp_time += get_rest_time();
	}

	temp_rests -= rests_array_size; //сколько остановок с одинаковым временем отдыха
	temp_time += temp_rests * get_rest_time();

	return temp_time;

}