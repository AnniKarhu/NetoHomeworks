/*Воздушное транспортное средство*/
#pragma once
#include "transport.h"

class Transport_air : public Transport
{
private: 
	int reduction_factor; //коэффициент сокращения расстояния
	void set_reduction_factor(int new_reduction_factor); //установить коэффициент сокращения расстояния
public:
	
	Transport_air(int new_speed, int new_reduction_factor);
	~Transport_air() override;  
	virtual int get_reduction_factor(const double distance); //коэффициент зависит от дистанции
	double calculate_total_distance_time(const double distance) override;
};
