#pragma once

#include "FractionException.h"

class Fraction
{
private:
	float float_value;
	int numerator_;
	int denominator_;
	int greatest_common_divisor(int numer, int denom); //���������� ����������� ������ ��������
	void simplify_fraction(); //��������� �����

public:
	Fraction(int numerator, int denominator);
	bool operator==(Fraction num_f2);
	bool operator!=(Fraction num_f2);
	bool operator>(Fraction num_f2);
	bool operator<=(Fraction num_f2);
	bool operator<(Fraction num_f2);
	bool operator>=(Fraction num_f2);

	float get_fraction_value();  //�������� � ���� ����������  �����
	std::string  print_fraction(); //������ - �������� � ���� �����

	Fraction operator+(Fraction num_f2); //��������;
	Fraction operator-(Fraction num_f2); //���������;
	Fraction operator*(Fraction num_f2); //���������;
	Fraction operator/(Fraction num_f2); //�������;
	Fraction& operator-(); //������� �����;
	Fraction& operator++(); //��������� ����������;
	Fraction operator++(int); //��������� �����������;
	Fraction& operator--();//��������� ����������
	Fraction operator--(int); //��������� ����������� 
	
};