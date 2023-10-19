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
    bool active_for_racing = false; //��������� �� ������� � �����
    void set_transport_name(std::string new_name);
    double result_time = -1; //��������� (�����) ����������� �����
    virtual double calculate_total_distance_time(double distance);   //��������� ����� ����������� ��������� 
public:
   
    int get_tr_speed();
    std::string get_tr_name();  
    transport_type get_tr_type();
    bool get_active_for_racing(); //��������� �� ������� � �����
    void set_active_for_racing(bool new_active, double distance); //��������� �� ������� � ����� - ����������
   
    double get_distance_time(); //������ ��������� �����
};