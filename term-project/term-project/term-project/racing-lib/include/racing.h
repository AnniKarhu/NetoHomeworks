#pragma once

#include "transport.h"
#include "racing_exception.h"
#include "transport_exception.h"

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
	bool racing_ready = false; //������ racing ����� � ������������� ������ ����� ���������� ������������� 
	race_type my_race_type; //��� �����
	int race_distance = 0;  //��������� �����
	const int minimum_transports_number = 2; //����������� ���������� ����������� ��� �����

	const int transports_array_size = 7; //������ ������� ���������� �� ���������� 
	Transport* transports_array[7] = {}; //������ ���������� �� ���������� - �� 1 ������, ����� �� �������� �� ������� ������� ��� ����������	
	
	//���������� �����������
	void sort_transport_array(Transport** arr, int left, int right); //������������� ������ �� ����������� ������� ����������� �����
	int pivoting(Transport** arr, int left, int right); //�������������
	void swap_transports(int i, int j); //�������� ������� ���������� � ��������� i � j
public: 
	explicit Racing(race_type new_race_type, int new_distance);
	Racing();	
	~Racing();

	void racing_init(); //������������� ����� - ���������� ������� ���������� ��������� ������ Transport
	bool get_racing_ready(); //����� �� ������ racing  � �������������

	//��� �����
	void set_race_type(race_type new_race_type); //������� ��� �����
	race_type get_race_type(); //�������� ��� �����

	//���������
	void set_race_distance(int new_distance); //������� ���������
	int get_race_distance(); //�������� ���������

	std::string race_type_name(race_type race_type_x); //�������� ����� �� �� ����
	std::string race_type_invitation_string(); //����������� ������� ��� �����
	std::string race_distance_invitation_string(); //����������� ������� ��������� �����
	std::string get_registered_transports_list(); //������ ���� �����������, ������������������ �� �����
	std::string transport_name(int arr_index); //��� ���������� �� ������� � ������� transports_array

	bool get_racing_registered_transports(); //��������, ���������������� �� ����������� ����� ���������� 
	int get_minimum_transports_number(); //����������� ���������� ����������� ��� �����
	int get_available_transports_number(); //������� ����� �������� ���������� - ������ ������� transports_array = transports_array_size	
	
	registration_status register_transport(int index); //���������������� ��������� �� �����
	double transport_result(int arr_index); //��������� (����� ����������� ���������) ���������� �� ������� � ������� transports_array
	void sort_transport_places(); //������������ �����		
	
};



