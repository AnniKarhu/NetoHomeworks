#include <iostream>
#include "transport_exceptions.h"



TransportException::TransportException(std::string error_reason_str)
{
	error_reason_string = error_reason_str;
}

const char* TransportException::what() const
{
	return  "Ошибка создания транспорта";
}

std::string TransportException::error_reason()
{
	return error_reason_string;
}
