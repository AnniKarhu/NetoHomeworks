/*Транспортное средство*/
#pragma once
#include <iostream>

enum class transport_type //типы транспортных средств
                        {
                            tr_type_land, //наземное
                            tr_type_air, //воздушное                          
                        };

class Transport
{
private:
    transport_type tr_type; //тип транспортного средства
    int tr_speed;           //скорость    
    std::string tr_name = "Транспортное средство";
    
    void SetSpeed(int new_speed); //установить скорость
    void SetType(transport_type new_type); //установить тип транспорта
protected:
    Transport(int new_speed, transport_type new_type);
    
    bool active_for_racing = false; //принимает ли участие в гонке
    void set_transport_name(std::string new_name);
    double result_time = -1; //результат (время) прохождения гонки
    virtual double calculate_total_distance_time(const double distance);   //вычислить время прохождения дистанции 
public:
    Transport();
    virtual ~Transport();

    int get_tr_speed();
    std::string get_tr_name();  
    transport_type get_tr_type();
    bool get_active_for_racing(); //принимает ли участие в гонке
    void set_active_for_racing(bool new_active, const double distance); //принимает ли участие в гонке - установить   
    double get_distance_time(); //узнать результат гонки

};