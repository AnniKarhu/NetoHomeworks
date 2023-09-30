#include "fraction.h"
#include <iostream>
#include <string>


	Fraction::Fraction(int numerator, int denominator)
	{
		if (denominator == 0)
		{
			throw FractionException();
		}
		numerator_ = numerator;
		denominator_ = denominator;
		simplify_fraction(); //сократить дробь
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

	std::string  Fraction::print_fraction() //строка - значение в виде дроби
	{
		return (std::to_string(this->numerator_) + "/" + std::to_string(this->denominator_));
	}

	float Fraction::get_fraction_value() //значение в виде десятичной  дроби
	{
		return float_value;
	}

	Fraction Fraction::operator+(Fraction num_f2) //сложение;
	{
		
		int temp_num = (this->numerator_ * num_f2.denominator_ + this->denominator_ * num_f2.numerator_);
		int temp_den =  (this->denominator_ * num_f2.denominator_);				
		
		Fraction new_fraction(temp_num, temp_den);
		new_fraction.simplify_fraction();

		return new_fraction;
	}

	Fraction Fraction::operator-(Fraction num_f2) //вычитание;
	{
				
		int	temp_num = (this->numerator_ * num_f2.denominator_ - this->denominator_ * num_f2.numerator_);
		int	temp_den = (this->denominator_ * num_f2.denominator_);

		Fraction new_fraction(temp_num, temp_den);
		new_fraction.simplify_fraction();

		return new_fraction;
	}


	Fraction Fraction::operator*(Fraction num_f2) //умножение;
	{
		
		int temp_num = this->numerator_ * num_f2.numerator_;
		int temp_den = this->denominator_ * num_f2.denominator_;

		Fraction new_fraction(temp_num, temp_den);
		new_fraction.simplify_fraction();

		return new_fraction;
	}


	Fraction Fraction::operator/(Fraction num_f2) //деление;
	{
		int temp_num = this->numerator_ * num_f2.denominator_;
		int temp_den = this->denominator_ * num_f2.numerator_;

		Fraction new_fraction(temp_num, temp_den);
		new_fraction.simplify_fraction();

		return new_fraction;
	}


	Fraction Fraction::operator-() //унарный минус;
	{
		int temp_num = this->numerator_ * (-1);
		
		Fraction new_fraction(temp_num, this->denominator_);
		new_fraction.simplify_fraction();

		return new_fraction;
		
	}

	Fraction& Fraction::operator++() //инкремент префиксный;
	{
		this->numerator_ += this->denominator_;
		return *this;
	}

	Fraction  Fraction::operator++(int) //инкремент постфиксный;
	{
		Fraction temp = *this;
		this->numerator_ += this->denominator_;
		return temp;
	}


	Fraction& Fraction::operator--()//декремент префиксный
	{
		this->numerator_ -= this->denominator_;
		return *this;
	}


	Fraction  Fraction::operator--(int) //декремент постфиксный 
	{
		Fraction temp = *this;
		this->numerator_ -= this->denominator_;
		return temp;
	}

	int Fraction::greatest_common_divisor(int numerator, int denominator) //вычисление наибольшего общего делителя
	{
		int numer = numerator;
		int denom = denominator;
		int remainder;

		if (numer < denom)
		{
			int temp = numer;
			numer = denom;
			denom = temp;
		}

		while (remainder = numer % denom)
		{
			numer = denom;
		    denom = remainder;
		}

		if (denom < 0)
		{
			denom *= (-1);
		}
		
		return denom;
	}

	void Fraction::simplify_fraction() //сократить дробь
	{
		int gcd = greatest_common_divisor(numerator_, denominator_);
		this->numerator_ /= gcd;
		this->denominator_ /= gcd;
		return;
	}
	

