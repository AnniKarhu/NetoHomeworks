#pragma once
#include <iostream>

/*
https://learn.microsoft.com/ru-ru/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170
в проекте библиотеки
DLL Visual Studio автоматически определ€ет макрос <»ћяѕ–ќ≈ “ј>_EXPORTS) и
когда он используетс€ при сборке модул€-клиента (тогда макрос не определЄн и
символы не экспортируютс€, а импортируютс€

#ifndef FIGURE_DYN_LIB_EXPORTS
или по имени проекта (заглавными буквами) - 
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
    std::string figure_name = "‘игура";
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