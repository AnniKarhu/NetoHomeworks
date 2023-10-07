#pragma once
#include <iostream>

/*
https://learn.microsoft.com/ru-ru/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170
� ������� ����������
DLL Visual Studio ������������� ���������� ������ <����������>_EXPORTS) �
����� �� ������������ ��� ������ ������-������� (����� ������ �� �������� �
������� �� ��������������, � �������������

#ifndef FIGURE_DYN_LIB_EXPORTS
��� �� ����� ������� (���������� �������) - 
#ifdef FIGURESDYNAMICLIBRARY_EXPORTS

*/


#ifdef FIGURESDYNAMICLIBRARY_EXPORTS
    #define FIGURE_DYN_LIB_API __declspec(dllexport)
#else
    #define FIGURE_DYN_LIB_API __declspec(dllimport)
#endif


class Figure
{
private:
    int sides_number = 0;
    std::string figure_name = "������";
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