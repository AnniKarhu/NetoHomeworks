#include <iostream>
#include "FractionException.h"


FractionException::FractionException()
	{
		
	}
	
	const char* FractionException::what() const
	{
		return  "����������� ����� �� ����� ���� ����� ����"; 
	}

	
