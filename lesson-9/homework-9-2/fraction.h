#pragma once

#include "FractionException.h"

class Fraction
{
private:
	float float_value;
	int numerator_;
	int denominator_;
	int greatest_common_divisor(int numer, int denom); //вычисление наибольшего общего делителя
	void simplify_fraction(); //сократить дробь

public:
	Fraction(int numerator, int denominator);
	bool operator==(Fraction num_f2);
	bool operator!=(Fraction num_f2);
	bool operator>(Fraction num_f2);
	bool operator<=(Fraction num_f2);
	bool operator<(Fraction num_f2);
	bool operator>=(Fraction num_f2);

	float get_fraction_value();  //значение в виде десятичной  дроби
	std::string  print_fraction(); //строка - значение в виде дроби

	Fraction operator+(Fraction num_f2); //сложение;
	Fraction operator-(Fraction num_f2); //вычитание;
	Fraction operator*(Fraction num_f2); //умножение;
	Fraction operator/(Fraction num_f2); //деление;
	Fraction& operator-(); //унарный минус;
	Fraction& operator++(); //инкремент префиксный;
	Fraction operator++(int); //инкремент постфиксный;
	Fraction& operator--();//декремент префиксный
	Fraction operator--(int); //декремент постфиксный 
	
};