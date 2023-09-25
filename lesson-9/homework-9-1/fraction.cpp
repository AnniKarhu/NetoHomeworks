#include "fraction.h"
#include <iostream>


	Fraction::Fraction(int numerator, int denominator)
	{
		if (denominator == 0)
		{
			throw FractionException();
		}
		numerator_ = numerator;
		denominator_ = denominator;
		float_value = float(numerator_) / float(denominator_);
	}

	bool Fraction::operator==(Fraction num_f2)
	{			
		
		if (float_value == num_f2.float_value)
		{
			return true;
		}
		else
			return false;
	}

	bool Fraction::operator!=(Fraction num_f2)
	{
		return !(*this == num_f2);
	}

	bool Fraction::operator>(Fraction num_f2)	
	{
				
		if (float_value > num_f2.float_value)
		{
			return true;
		} 
		else
		{
				return false;
		}	
		
	}

	bool Fraction::operator<=(Fraction num_f2)
	{
		return !(*this > num_f2);
	}

	bool Fraction::operator<(Fraction num_f2)
	{
		return num_f2 > *this;
	}
	bool Fraction::operator>=(Fraction num_f2)
	{
		return !(*this < num_f2);
	}

	float Fraction::get_fraction_value()
	{
		return float_value;
	}

	

