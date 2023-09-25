#pragma once
#include "figure.h"

//четырехугольник
class Quadrangle : public Figure
{
private:

    //длины сторон
    int side_a;
    int side_b;
    int side_c;
    int side_d;

    //углы
    int angle_a;
    int angle_b;
    int angle_c;
    int angle_d;

    int correct_angles_sum = 360; //допустимая сумма углов
    int correct_sides_num = 4;    //допустимое количество сторон
public:

    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D); // : Figure(4);
    
    int get_side_a();
    
    int get_side_b();
    
    int get_side_c();
    
    int get_side_d();
    
    int get_angle_a();
    
    int get_angle_b();
    
    int get_angle_c();
    
    int get_angle_d();
    
    std::string get_sides_info()  override;
    
    std::string get_angles_info() override;
    
};
