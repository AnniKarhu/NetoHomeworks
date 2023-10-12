/*Транспортное средство*/
#pragma once
#include <iostream>

enum class transport_type //типы транспортных средств
                        {
                            tr_type_land, //наземное
                            tr_type_air, //воздушное
                          //  tr_type_all  //универсальное - такое не бывает, при попытке создать генерируется исключение
                        };

class Transport
{
private:
    transport_type tr_type; //тип транспортного средства
    int tr_speed;           //скорость    
    std::string tr_name = "Транспортное средство";
protected:
    Transport(int new_speed, transport_type new_type);
   
    void set_transport_name(std::string new_name);
public:
   
    int get_tr_speed();
    std::string get_tr_name();  
    transport_type get_tr_type();

   virtual double get_total_distance_time(double distance);


};