#pragma once
#include <iostream>

class Figure
{
private:
    int sides_number = 0;
    std::string figure_name = "Фигура";
protected:
    Figure(int sides_num, std::string fig_name);
    Figure(int sides_num);
    
    void set_figure_name(std::string fig_name);
    
public:
    Figure();
    int get_sides_number();
   
    std::string get_figure_name();    
    virtual std::string get_sides_info();
    virtual std::string get_angles_info();
    

};