/*������������ ��������*/
#pragma once
#include <iostream>

enum class transport_type //���� ������������ �������
                        {
                            tr_type_land, //��������
                            tr_type_air, //���������
                          //  tr_type_all  //������������� - ����� �� ������, ��� ������� ������� ������������ ����������
                        };

class Transport
{
private:
    transport_type tr_type; //��� ������������� ��������
    int tr_speed;           //��������    
    std::string tr_name = "������������ ��������";
protected:
    Transport(int new_speed, transport_type new_type);
   
    void set_transport_name(std::string new_name);
public:
   
    int get_tr_speed();
    std::string get_tr_name();  
    transport_type get_tr_type();

   virtual double get_total_distance_time(double distance);


};