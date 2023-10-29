#include "include/transport_magic_carpet.h"

Transport_magic_carpet::Transport_magic_carpet() : Transport_air(10, 0)
{
	set_transport_name("Ковёр-самолёт");
}

int Transport_magic_carpet::get_reduction_factor(const double distance)  //коэффициент в процентах зависит от дистанции
{
	//массив array_carpet_reduction_factors содержит расстояния и соответствующие им коэффициенты
	//carpet_reduction_factors_number - размер массива array_carpet_reduction_factors
	
	for (int i = 0; i < carpet_reduction_factors_number - 1; ++i)
	{
		if (distance < array_carpet_reduction_factors[i].distance)
			return array_carpet_reduction_factors[i].value;
	}
	
	return array_carpet_reduction_factors[carpet_reduction_factors_number - 1].value;

}

	