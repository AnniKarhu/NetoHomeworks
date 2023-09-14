// homework-6-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
bool get_number_from_user(float* num, std::string str); //получение числа от пользователя

int main()
{
    setlocale(LC_ALL, "rus");

    float num_1;
    float num_2;


    while (!get_number_from_user(&num_1, "Введите первое число: "))//получение числа от пользователя
    {
    }; 

    while (!get_number_from_user(&num_2, "Введите второе число: "))//получение числа от пользователя
    {
    };

    std::cout << num_1 << " Hello World! " << num_2;
    return 0;
}

bool get_number_from_user(float* num_1, std::string str) //получение числа от пользователя
{
  //  float temp = 0;
    std::cout << str;
    std::cin >> *num_1;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Число введено некорректно. Попробуйте еще. \n";
        *num_1 = 0.0;
        return false;
    }


    return true;
}