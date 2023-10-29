#include <iostream>

#include "include/transport_exception.h"

TransportException::TransportException(std::string error_reason_str)
{
	error_reason_string = error_reason_str;
}

const char* TransportException::what() const noexcept
{
	return  "Ошибка создания транспорта";
}

std::string TransportException::error_reason()
{
	return error_reason_string;
}
