#pragma once
#include <iostream>

class Counter
{
private:
    int value;

public:
    std::string invite_cmd_str = "¬ведите команду('+', '-', '=' или 'x') : ";

    Counter();
    Counter(int num); 

    void inc_value();
    void dec_value();
    int get_value();
    
};