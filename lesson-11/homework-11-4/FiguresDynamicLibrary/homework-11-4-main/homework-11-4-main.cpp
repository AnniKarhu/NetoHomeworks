// homework-11-4-main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <string>
#include "diamond.h"
#include "equilateral_triangle.h"
#include "square.h"
#include "right_triangle.h"


void print_info(Figure* p_figure); //вывести информацию о фигуре

int main()
{
    setlocale(LC_ALL, "rus");


    Triangle triangle_1(10, 20, 30, 50, 60, 70);
    Right_triangle right_triangle_1(10, 20, 30, 50, 60);
    Isosceles_triangle isosceles_triangle_1(10, 20, 50, 60);
    Equilateral_triangle equilateral_triangle_1(30);
    Quadrangle quadrangle_1(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle_1(10, 20);
    Square square_1(20);
    Parallelogram parallelogram_1(20, 30, 30, 40);
    Diamond diamond_1(30, 30, 40);

    print_info(&triangle_1);
    print_info(&right_triangle_1);
    print_info(&isosceles_triangle_1);
    print_info(&equilateral_triangle_1);
    print_info(&quadrangle_1);
    print_info(&square_1);
    print_info(&parallelogram_1);
    print_info(&diamond_1);

    
}

void print_info(Figure* p_figure) //вывести информацию о фигуре
{
    std::cout << p_figure->get_figure_name() << ":\n";
    std::cout << "Стороны: " << p_figure->get_sides_info() << "\n";
    std::cout << "Углы: " << p_figure->get_angles_info() << "\n\n";
}