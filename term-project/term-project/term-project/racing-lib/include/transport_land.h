/*Ќаземное транспортное средство*/
#pragma once
#include "transport.h"

class Transport_land : public Transport
{
private:
	int move_time; //врем€ движени€ до отдыха
	int rests_array_index = 0; //индекс номера остановки
	int rests_array_size = 0; //размер массива rests_array
	
	void set_move_time(int new_move_time); //установить врем€ движени€ до отдыха
	void set_rests_array_size(int new_rests_array_size); //установить размер массива rests_array

protected:
	double* rests_array = nullptr; //массив, содержащий информацию об остановках дл€ отдыха.
	int get_rests_array_size(int new_rests_array_size); //размер массива rests_array
	
public:
	Transport_land(int new_speed, int new_move_time,  int new_rests_array_size);
	~Transport_land() override; 
	int get_move_time();
	virtual int get_rest_time();

	double calculate_total_distance_time(const double distance) override;
};
