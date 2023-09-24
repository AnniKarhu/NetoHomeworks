#include <iostream>
#include "FractionException.h"


FractionException::FractionException()
	{
		
	}
	
	const char* FractionException::what() const
	{
		return  "Знаменатель дроби не может быть равен нулю"; 
	}

	
