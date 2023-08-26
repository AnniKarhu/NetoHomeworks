// homework-2-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct address
{
    std::string city;
    std::string street;
    int building_num;
    int flat_num;
    int zip_code;
};

void print_address(const address& p_address); //вывод адреса

int main()
{
    setlocale(LC_ALL, "Russian");
    
    address addr_1 = {"Москва", "Арбат", 12, 8, 123456};
    address addr_2 = {"Ижевск", "Пушкина", 59, 143, 456789};

    print_address(addr_1);
    print_address(addr_2);

}

void print_address(const address& p_address) //вывод адреса
{
    std::cout << "Город: "          << p_address.city << "\n";
    std::cout << "Улица: "          << p_address.street << "\n";
    std::cout << "Номер дома: "     << p_address.building_num << "\n";
    std::cout << "Номер квартиры: " << p_address.flat_num << "\n";
    std::cout << "Индекс: "         << p_address.zip_code << "\n";
    std::cout << "\n";
}