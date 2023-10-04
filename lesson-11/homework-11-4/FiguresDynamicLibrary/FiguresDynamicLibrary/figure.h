#pragma once
#include <iostream>

#ifdef FIGURE_DYN_LIB_EXPORTS
#define FIGURE_DYN_LIB_API __declspec(dllexport)
#else
#define FIGURE_DYN_LIB_API __declspec(dllimport)
#endif


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
    FIGURE_DYN_LIB_API Figure();
    FIGURE_DYN_LIB_API int get_sides_number();
   
    FIGURE_DYN_LIB_API std::string get_figure_name();
    FIGURE_DYN_LIB_API virtual std::string get_sides_info();
    FIGURE_DYN_LIB_API virtual std::string get_angles_info();
    

};