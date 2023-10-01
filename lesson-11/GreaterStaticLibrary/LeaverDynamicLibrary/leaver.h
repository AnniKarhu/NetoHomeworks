#pragma once
#include <iostream>

#ifdef LEAVERDYNAMICLIBRARY_EXPORTS
#define LEAVERDYNAMICLIBRARY_API __declspec(dllexport)
#else
#define LEAVERDYNAMICLIBRARY_API __declspec(dllimport)
#endif

class Leaver
{
public:

	LEAVERDYNAMICLIBRARY_API std::string leave(std::string str_in);

};
