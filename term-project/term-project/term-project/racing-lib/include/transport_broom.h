#pragma once

#include "transport_air.h"

class Transport_broom : public Transport_air
{
private:
	int red_factor_inc = 1; //на сколько процентов увеличивается коэффициент сокращения расстояния в зависимости от дистанции - red_factor_inc_distance
	int red_factor_inc_distance = 1000; //какое расстояние приводит к увеличению коэффициента сокращения расстояния на red_factor_inc процентов

public:
	Transport_broom();
	
	int get_reduction_factor(const double distance) override; //коэффициент зависит от дистанции
};
