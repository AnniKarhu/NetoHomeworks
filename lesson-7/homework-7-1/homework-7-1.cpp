// homework-7-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#define MODE 1

#if !defined MODE
    #error "необходимо определить MODE"
#else
    #if MODE == 1
        float add(float num_1, float num_2);
    #endif
#endif

int main()
{


    setlocale(LC_ALL, "rus");

#if MODE == 0
        std::cout << "Работаю в режиме тренировки\n";
        return 0;
#elif MODE == 1
    std::cout << "Работаю в боевом режиме\n";
    float num_1;
    float num_2;
    std::cout << "Введите число 1: ";
    std::cin >> num_1;
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите число 1: ";
        std::cin >> num_1;
    }

    std::cout << "Введите число 2: ";
    std::cin >> num_2;
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите число 2: ";
        std::cin >> num_2;
    }

    std::cout << "Результат сложения: " << add(num_1, num_2);

#else
    std::cout << "Неизвестный режим. Завершение работы\n";
    return 0;
#endif
   
    return 0;
}

#if defined MODE

    #if MODE == 1
    float add(float num_1, float num_2)
    {
        return num_1 + num_2;
    }
    #endif
#endif