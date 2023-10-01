#include <iostream>
#include "leaver.h"

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");

    std::string name_str;
    std::cout << "¬ведите им€: ";
    std::cin >> name_str;

    Leaver lv;
    std::cout << lv.leave(name_str) << "\n";

    return 0;

}