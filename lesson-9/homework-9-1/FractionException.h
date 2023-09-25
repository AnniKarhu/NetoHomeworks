#pragma once

#include <iostream>
class FractionException : public std::exception
{

public:
	
	FractionException();
	const char* what() const override;	

};
