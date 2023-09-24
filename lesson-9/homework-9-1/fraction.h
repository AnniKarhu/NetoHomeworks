#pragma once

#include "FractionException.h"

class Fraction
{
private:
	float float_value;
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator);
	bool operator==(Fraction num_f2);
	bool operator!=(Fraction num_f2);
	bool operator>(Fraction num_f2);
	bool operator<=(Fraction num_f2);
	bool operator<(Fraction num_f2);
	bool operator>=(Fraction num_f2);
	float get_fraction_value();
	
};