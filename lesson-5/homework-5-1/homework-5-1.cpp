// homework-5-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

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
public:
    Figure()
    {

    }

    int get_sides_number()
    {
        return sides_number;
    }

    std::string get_figure_name()
    {
        return figure_name;
    }
};

class Triangle : public Figure
{
public:

    Triangle() : Figure(3, "Треугольник")
    {

    }

};

class Quadrangle : public Figure
{
public:

    Quadrangle() : Figure(4, "Четырёхугольник")
    {

    }

};

int main()
{
    setlocale(LC_ALL, "rus");

    std::cout << "Количество сторон:\n";
    Figure   figure_1;
    Triangle triangle_1;
    Quadrangle quadrangle_1;

    std::cout << figure_1.get_figure_name() << ": " << figure_1.get_sides_number() << "\n";
    std::cout << triangle_1.get_figure_name() << ": " << triangle_1.get_sides_number() << "\n";
    std::cout << quadrangle_1.get_figure_name() << ": " << quadrangle_1.get_sides_number() << "\n";

}
