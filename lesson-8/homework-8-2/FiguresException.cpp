#include <iostream>
#include "FiguresException.h"


//	FiguresException::FiguresException()
//	{
	
//	}

	FiguresException::FiguresException(std::string error_reason_str)
	{
		error_reason_string = error_reason_str;
	}
	
	const char* FiguresException::what() const
	{
		return "Ошибка создания фигуры."; 
	}

	std::string FiguresException::error_reason()
	{
		return error_reason_string;
	}
