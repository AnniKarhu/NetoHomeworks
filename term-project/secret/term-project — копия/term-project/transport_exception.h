#pragma once
#include <iostream>

class TransportException : public std::exception
{
private:
	std::string error_reason_string = "Причина неизвестна.";

public:
	
	TransportException(std::string error_reason_str);

	const char* what() const override;

	std::string error_reason();

};
