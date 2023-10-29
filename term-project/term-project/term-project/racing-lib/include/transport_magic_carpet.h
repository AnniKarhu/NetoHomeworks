#pragma once

#include "transport_air.h"

struct carpet_reduction_factors
{
	int distance;
	int value;
};

class Transport_magic_carpet : public Transport_air
{
private:
	int carpet_reduction_factors_number = 4;
	carpet_reduction_factors array_carpet_reduction_factors[4] = { {1000, 0}, {5000, 3}, {10000, 10}, {1000,5} };
	
public:
	Transport_magic_carpet();

	int get_reduction_factor(const double distance) override; //коэффициент зависит от дистанции
};


