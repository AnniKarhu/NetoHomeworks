/*Наземное транспортное средство*/
#pragma once
#include "transport.h"

class Transport_land : public Transport
{
private:
	int move_time; //время движения до отдыха
	
	
protected:
	int rests_array_size = 0; //размер массива rests_array
	double* rests_array = nullptr; //массив, содержащий информацию об остановках для отдыха.
public:
	Transport_land(int new_speed, int new_move_time,  int new_rests_array_size);
	~Transport_land();
	int get_move_time();
	virtual int get_rest_time();

	double get_total_distance_time(double distance) override;
};
