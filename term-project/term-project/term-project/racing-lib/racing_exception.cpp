#include <iostream>
#include "include/racing_exception.h"

RacingException::RacingException(std::string error_reason_str)
{
	error_reason_string = error_reason_str;
}

const char* RacingException::what() const noexcept
{
	return  "Ошибка создания гонки";
}

std::string RacingException::error_reason()
{
	return error_reason_string;
}
