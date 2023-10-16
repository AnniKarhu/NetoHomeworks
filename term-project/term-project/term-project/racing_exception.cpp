#include <iostream>
#include "racing_exceptions.h"



RacingException::RacingException(std::string error_reason_str)
{
	error_reason_string = error_reason_str;
}

const char* RacingException::what() const
{
	return  "Ошибка создания гонки";
}

std::string RacingException::error_reason()
{
	return error_reason_string;
}
