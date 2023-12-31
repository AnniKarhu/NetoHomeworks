﻿// homework-5-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class Figure
{
private:
    int sides_number = 0;
    std::string figure_name = "Фигура";
    
protected:
    Figure(int sides_num, std::string fig_name)
    {
        sides_number = sides_num;
        figure_name = fig_name;
    }

    Figure(int sides_num)
    {
        sides_number = sides_num;
    }

    void set_figure_name(std::string fig_name)
    {
        figure_name = fig_name;
    }

    int get_sides_number()
    {
        return sides_number;
    }

    virtual bool figure_correct()
    {
        if (get_sides_number() == 0)
        {
            return true;
        }
        else return false;
    }

   
    std::string get_figure_name()
    {
        return figure_name;
    }

    virtual std::string get_sides_info()
    {
        return "";
    }

    virtual std::string get_angles_info()
    {
        return "";
    }

public:
    Figure()
    {

    }

    virtual void print_info()
    {
    std::cout << get_figure_name() << ":\n";
    if (figure_correct())
    {
        std::cout << "Правильная\n";
    }
    else
    {
        std::cout << "Неправильная\n";
    }
    
    std::cout <<  "Количество сторон: " << sides_number << "\n";
   
    }
};

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

    Triangle(int a, int b, int c, int A, int B, int C) : Figure(3)
    {
        side_a = a;
        side_b = b;
        side_c = c;

        angle_a = A;
        angle_b = B;
        angle_c = C;

        set_figure_name("Треугольник");
    }
    
    void print_info() override
    {
        Figure::print_info();        
       
        std::cout << "Стороны: " << get_sides_info() << "\n";
        std::cout << "Углы: "    << get_angles_info() << "\n";
    }

protected:
  int get_side_a()
    {
        return side_a;
    }

    int get_side_b()
    {
        return side_b;
    }

    int get_side_c()
    {
        return side_c;
    }

    int get_angle_a()
    {
        return angle_a;
    }

    int get_angle_b()
    {
        return angle_b;
    }

    int get_angle_c()
    {
        return angle_c;
    } 

    virtual bool figure_correct() override
    { 
        if ((get_sides_number() == 3) &&
            ((angle_a + angle_b + angle_c) == 180))
        {
            return true;
        }
        else return false;
    }

    std::string get_sides_info()  override
    {
        return "a=" + std::to_string(side_a) + " b=" + std::to_string(side_b) + " c=" + std::to_string(side_c);
    }

    std::string get_angles_info() override
    {
        return "A=" + std::to_string(angle_a) + " B=" + std::to_string(angle_b) + " C=" + std::to_string(angle_c);
    }

};

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
public:

    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4)
    {
        side_a = a;
        side_b = b;
        side_c = c;
        side_d = d;

        angle_a = A;
        angle_b = B;
        angle_c = C;
        angle_d = D;

        set_figure_name("Четырёхугольник");
    }

    void print_info() override
    {
        Figure::print_info();

        std::cout << "Стороны: " << get_sides_info() << "\n";
        std::cout << "Углы: " << get_angles_info() << "\n";
    }

protected:

    int get_side_a()
    {
        return side_a;
    }

    int get_side_b()
    {
        return side_b;
    }

    int get_side_c()
    {
        return side_c;
    }

    int get_side_d()
    {
        return side_d;
    }

    int get_angle_a()
    {
        return angle_a;
    }

    int get_angle_b()
    {
        return angle_b;
    }

    int get_angle_c()
    {
        return angle_c;
    }

    int get_angle_d()
    {
        return angle_d;
    } 

    virtual bool figure_correct() override
    {
        if ((get_sides_number() == 4) &&
            (angle_a + angle_b + angle_c + angle_d == 360))
        {
            return true;
        }
        else return false;
    }

    std::string get_sides_info()  override
    {
        return "a=" + std::to_string(side_a) + " b=" + std::to_string(side_b) + " c=" + std::to_string(side_c) + " d=" + std::to_string(side_d);
    }

    std::string get_angles_info() override
    {
        return "A=" + std::to_string(angle_a) + " B=" + std::to_string(angle_b) + " C=" + std::to_string(angle_c) + " D=" + std::to_string(angle_d);
    }
};

//прямоугольный треугольник
class Right_triangle : public Triangle
{
public:
    Right_triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
    {
        set_figure_name("Прямоугольный треугольник");
    };

protected:
   
    bool figure_correct() override
    {
        if (Triangle::figure_correct() && (get_angle_c() == 90))
        {
            return true;
        }
        else return false;
    }
};

//Равнобедренный треугольник
class Isosceles_triangle : public Triangle
{
public:
    Isosceles_triangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
    {
        set_figure_name("Равнобедренный треугольник");
    }

protected:

    bool figure_correct() override
    {
        if (Triangle::figure_correct() &&
            (get_angle_a() == get_angle_c()) &&
            (get_side_a() == get_side_c()))
        {
            return true;
        }
        else return false;
    }

};

//Равносторонний треугольник
class Equilateral_triangle : public Isosceles_triangle
{
public:
    Equilateral_triangle(int a) : Isosceles_triangle(a, a, 60, 60)
    {
        set_figure_name("Равносторонний треугольник");
    }

protected:

    bool figure_correct() override
    {
        if (Triangle::figure_correct() &&
            (get_angle_a() == 60) &&
            (get_angle_b() == 60) &&
            (get_angle_c() == 60) &&
            (get_side_a() == get_side_b()) &&
            (get_side_b() == get_side_c()) &&
            (get_side_a() == get_side_c()))
        {
            return true;
        }
        else return false;
    }


};

//прямоугольник
class Rectangle : public Quadrangle
{
public:
    Rectangle(int a, int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90)
    {
        set_figure_name("Прямоугольник");
    }

protected:
 
    virtual bool figure_correct() override
    {
        if (Quadrangle::figure_correct() && 
           (get_angle_a() == 90) &&
           (get_angle_b() == 90) &&
           (get_angle_c() == 90) &&
           (get_angle_d() == 90) &&
           (get_side_a()  == get_side_c()) &&
           (get_side_b() == get_side_d()))
             
        {
            return true;
        }
        else return false;
    }
};

//квадрат
class 	Square : public Rectangle
{
public:
    Square(int a) : Rectangle(a, a)
    {
        set_figure_name("Квадрат");
    }

protected:
  
    virtual bool figure_correct() override
    {
        if (Rectangle::figure_correct() &&            
            (get_side_a() == get_side_b()) &&
            (get_side_c() == get_side_d()))
        {
            return true;
        }
        else return false;
    }

};

//параллелограмм
class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B)
    {
        set_figure_name("Параллелограмм");
    }
   

protected:
    virtual bool figure_correct() override
    {
        if (Quadrangle::figure_correct() &&
            (get_angle_a() == get_angle_c()) &&
            (get_angle_b() == get_angle_d()) &&
            (get_side_a() == get_side_c()) &&
            (get_side_b() == get_side_d()))

        {
            return true;
        }
        else return false;
    }

};

//ромб
class Diamond : public Parallelogram
{
public:
    Diamond(int a, int A, int B) : Parallelogram(a, a, A, B)
    {
        set_figure_name("Ромб");
    }

protected:
 
    bool figure_correct() override
    {
        if (Parallelogram::figure_correct() &&
            (get_side_a() == get_side_b()) &&
            (get_side_c() == get_side_d()))

        {
            return true;
        }
        else return false;
    }


};

void print_info(Figure* p_figure); //вывести информацию о фигуре

int main()
{
    setlocale(LC_ALL, "rus");

    Figure figure_1;
    Triangle triangle_1(10, 20, 30, 50, 60, 70);
    Right_triangle right_triangle_1(10, 20, 30, 50, 60);
    Isosceles_triangle isosceles_triangle_1(10, 20, 50, 60);
    Equilateral_triangle equilateral_triangle_1(30);
    Quadrangle quadrangle_1(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle_1(10, 20);
    Square square_1(20);
    Parallelogram parallelogram_1(20, 30, 30, 40);
    Diamond diamond_1(30, 30, 40);

    print_info(&figure_1);
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
    p_figure->print_info();
    std::cout << "\n";
}