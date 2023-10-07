#pragma once
#include "figure.h"


//���������������
class Quadrangle : public Figure
{
private:

    //����� ������
    int side_a;
    int side_b;
    int side_c;
    int side_d;

    //����
    int angle_a;
    int angle_b;
    int angle_c;
    int angle_d;
public:

    FIGURE_DYN_LIB_API Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D); // : Figure(4);
    
    int get_side_a();
    
    int get_side_b();
    
    int get_side_c();
    
    int get_side_d();
    
    int get_angle_a();
    
    int get_angle_b();
    
    int get_angle_c();
    
    int get_angle_d();
    
    FIGURE_DYN_LIB_API std::string get_sides_info()  override;
    
    FIGURE_DYN_LIB_API std::string get_angles_info() override;
    
};
