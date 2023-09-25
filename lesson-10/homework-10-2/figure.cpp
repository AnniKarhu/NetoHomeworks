#include "figure.h"
#include <iostream>


Figure::Figure(int sides_num, std::string fig_name)
    {
        sides_number = sides_num;
        figure_name = fig_name;
    }

Figure::Figure(int sides_num)
    {
        sides_number = sides_num;
    }

void Figure::set_figure_name(std::string fig_name)
    {
        figure_name = fig_name;
    }

Figure::Figure()
    {

    }

int Figure::get_sides_number()
    {
        return sides_number;
    }

std::string Figure::get_figure_name()
    {
        return figure_name;
    }


 std::string Figure::get_sides_info()
    {
        return "";
    }

 std::string Figure::get_angles_info()
    {
        return "";
    }

