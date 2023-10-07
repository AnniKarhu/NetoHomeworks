#pragma once
#include "figure.h"


class Triangle : public Figure
{
private:

    //длины сторон
    int side_a;
    int side_b;
    int side_c;

    //углы
    int angle_a;
    int angle_b;
    int angle_c;
public:

    FIGURE_DYN_LIB_API Triangle(int a, int b, int c, int A, int B, int C); // : Figure(3);

    int get_side_a();

    int get_side_b();
    
    int get_side_c();
    
    int get_angle_a();

    int get_angle_b();
    
    int get_angle_c();
    
    FIGURE_DYN_LIB_API std::string get_sides_info()  override;
    
    FIGURE_DYN_LIB_API std::string get_angles_info() override;
    
};
