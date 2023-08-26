// homework-2-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>

struct bank_account
{
    std::string name;
    int bank_account_number;
    int balance;
    
};

void fill_in_account(bank_account& account); //заполнение информации о счете
void print_account_info(const bank_account& account); //вывод информации об аккаунте

int main()
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bank_account new_account = { "без имени", 0, 0};
   // print_account_info(new_account); //вывод информации об аккаунте

   
    fill_in_account(new_account); //заполнение информации о счете
    print_account_info(new_account); //вывод информации об аккаунте
}

void fill_in_account(bank_account& account) //заполнение информации о счете
{
    //номер счета
    int temp_int = 0;
    while (temp_int <= 0)
    {
        std::cout << "Введите номер счёта: ";
        std::cin >> temp_int;
    }
    account.bank_account_number = temp_int;

    //имя владельца
    std::string temp_str;
    std::cout << "Введите имя владельца: ";
    std::cin >> account.name; 

    //баланс
    std::cout << "Введите баланс: ";
    std::cin >> account.balance;
    
    //новый баланс
    std::cout << "Введите новый баланс: ";
    std::cin >> account.balance;    

    return;
} 
void print_account_info(const bank_account& account) //вывод информации об аккаунте
{
   // после ввода имени кириллицей на вывод выходит что-то не то
    std::cout << "Ваш счет: " << account.name << ", " << account.bank_account_number << ", " << account.balance << std::endl;
    return;
}