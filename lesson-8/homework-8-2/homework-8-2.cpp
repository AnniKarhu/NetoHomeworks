// homework-8-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

    try
    {
        //хорошие фигуры
            
        Triangle triangle_1(10, 20, 30, 50, 60, 70);
        print_info(&triangle_1);

        Right_triangle right_triangle_1(10, 20, 70, 50, 40);
        print_info(&right_triangle_1);

        Isosceles_triangle isosceles_triangle_1(10, 20, 50, 80);
        print_info(&isosceles_triangle_1);

        Equilateral_triangle equilateral_triangle_1(30);
        print_info(&equilateral_triangle_1);

        Quadrangle quadrangle_1(10, 20, 30, 40, 100, 80, 90, 90);
        print_info(&quadrangle_1);

        Rectangle rectangle_1(10, 20);
        print_info(&rectangle_1);

        Square square_1(20);
        print_info(&square_1);

        Parallelogram parallelogram_1(20, 30, 30, 150);
        print_info(&parallelogram_1);

        Diamond diamond_1(30, 30, 150);
        print_info(&diamond_1);   
        
        // фигуры с ошибками - генерируют исключения

        std::cout << "\n\n***********************************\n\n";

        Triangle triangle_2(10, 20, 30, 50, 60, 50);
        print_info(&triangle_2);

        Right_triangle right_triangle_2(10, 20, 30, 50, 60);
        print_info(&right_triangle_2);

        Isosceles_triangle isosceles_triangle_2(10, 20, 50, 60);
        print_info(&isosceles_triangle_2);

        //эту фигуру невозможно создать неправильно
        //Equilateral_triangle equilateral_triangle_2(30);
        //print_info(&equilateral_triangle_2);

        Quadrangle quadrangle_2(10, 20, 30, 40, 50, 60, 70, 80);
        print_info(&quadrangle_2);

        //эту фигуру невозможно создать неправильно
        //Rectangle rectangle_2(10, 20);
        //print_info(&rectangle_2);

        //эту фигуру невозможно создать неправильно
        //Square square_2(20);
        //print_info(&square_2);

        Parallelogram parallelogram_2(20, 30, 30, 40);
        print_info(&parallelogram_2);

        Diamond diamond_2(30, 30, 40);
        print_info(&diamond_2);
        
    }
   catch (FiguresException& ex)
        {
       std::cout << ex.what() << " Причина: " << ex.error_reason(); 

        }
   catch (...)
        {
            std::cout << "Неизвестная ошибка\n";
        }
   ;

     

}

void print_info(Figure* p_figure) //вывести информацию о фигуре
{
    std::cout << p_figure->get_figure_name();
    std::cout << "(стороны " << p_figure->get_sides_info();
    std::cout << "; углы: " << p_figure->get_angles_info();
    std::cout << ") создан\n";
    
  //  std::cout << p_figure->get_figure_name() << ":\n";
  //  std::cout << "Стороны: " << p_figure->get_sides_info() << "\n";
  //  std::cout << "Углы: " << p_figure->get_angles_info() << "\n\n";
}