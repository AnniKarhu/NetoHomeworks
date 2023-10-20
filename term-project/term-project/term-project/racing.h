#pragma once

#include "transport.h"
#include "racing_exceptions.h"
#include "transport_exceptions.h"

enum class race_type //��������� ���� �����
					{  
						race_type_land = 1, //����� ������ ��� ��������
						race_type_air,  //����� ������ ��� ���������
						race_type_all   //����� ��� ����
					 };

enum class registration_status  //��������� ���������� �����������
								{
									reg_status_ok,				//������� ���������������
									reg_status_second_attempt, //������� ���������������� ��������� ������ ���
									reg_status_type_error		//��������� �� �������� ��� ����� ���� �����
								};


class Racing
{
private:
	int race_distance = 0;
	race_type my_race_type; //��� �����
	int transports_array_size = 7; //������ ������� ���������� �� ���������� 
	Transport* transports_array[8] = {}; //������ ���������� �� ���������� - �� 1 ������, ����� �� �������� �� ������� ������� ��� ����������
	double* result_time_array[7];
	//int transports_array_index = -1; //��������� �� �������  ������ ������� transports_array
	int minimum_transports_number = 2; //����������� ���������� ����������� ��� �����

	
    int pivoting(Transport** arr, int size, int pi); //�������������
	void sort_transport_array(Transport** arr, int size); //������������� ������ �� ����������� ������� ����������� �����
	void sort_transport_array2(Transport** arr, int size); //������������� ������ �� ����������� ������� ����������� �����
public: 
	Racing(race_type new_race_type, int new_distance);
	Racing();
	
	~Racing();
	void set_race_type(race_type new_race_type); //������� ��� �����
	race_type get_race_type(); //�������� ��� �����
	void set_race_distance(int new_distance); //������� ���������
	int get_race_distance(); //�������� ���������
	std::string race_type_name(race_type race_type_x); //�������� ����� �� �� ����
	std::string race_type_invitation_string(); //����������� ������� ��� �����
	std::string race_distance_invitation_string(); //����������� ������� ��������� �����
	bool get_racing_registered_transports(); //��������, ���������������� �� ����������� ����� ���������� 
	int get_minimum_transports_number(); //����������� ���������� ����������� ��� �����
	int get_available_transports_number(); //������� ����� �������� ���������� - ������ ������� transports_array = transports_array_size
	std::string transport_name(int arr_index); //��� ���������� �� ������� � ������� transports_array
	double transport_result(int arr_index); //��������� (����� ����������� ���������) ���������� �� ������� � ������� transports_array
	std::string get_registered_transports_list(); //������ ���� �����������, ������������������ �� �����
	registration_status register_transport(int index); //���������������� ��������� �� �����
	void sort_transport_places(); //������������ ����� 
	
	void swap(int i, int j); //�������� �������
};



