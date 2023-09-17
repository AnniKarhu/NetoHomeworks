#pragma once

#include <iostream>
class FiguresException : public std::exception
{
private:
	std::string error_reason_string = "Причина неизвестна.";

public:
	//FiguresException();
	
	FiguresException(std::string error_reason_str);
	
	const char* what() const override;	

	std::string error_reason();	

};
