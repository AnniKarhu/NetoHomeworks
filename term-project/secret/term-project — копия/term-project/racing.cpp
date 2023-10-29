#include "racing.h"
#include <string>

//���������
#include "transport_camel.h"
#include "transport_high_speed_camel.h"
#include "transport_centaur.h"
#include "transport_crosscountry_boots.h"
#include "transport_eagle.h"
#include "transport_broom.h"
#include "transport_magic_carpet.h"

Racing::Racing(race_type new_race_type, int new_distance)
{
	my_race_type = new_race_type;
	race_distance = new_distance;		
}

Racing::Racing()
{	
	try
	{
		transports_array[0] = new Transport_crosscountry_boots();		
		transports_array[1] = new Transport_broom();		
		transports_array[2] = new Transport_camel();
		transports_array[3] = new Transport_centaur();
		transports_array[4] = new Transport_eagle();
		transports_array[5] = new Transport_high_speed_camel();
		transports_array[6] = new Transport_magic_carpet();	
		
	}
	catch (const TransportException& ex)
	{
		throw RacingException("������ �������� ����� -  ���� ��� ����� ����������� �� �������" );
	}
	catch (...)
	{
		throw RacingException("������ �������� ����� -  ������� ����������");
	}	

	//���������, ��� ��� ���������� ������� ������� (� ����� ������ �� ���� ��������)
	for (int i = 0; i < transports_array_size; ++i)
	{
		if (transports_array[i] == nullptr)
		{
			throw RacingException("������ �������� ����� -  ���� ��� ����� ����������� �� �������");
		}		
	}
}



Racing::~Racing()
{
	//������� ������ �� ������������������ �� ����� �����������
	for (int i = 0; i < transports_array_size; ++i)
	{
		if (transports_array[i] != nullptr)
		{
			delete transports_array[i];
			transports_array[i] = nullptr;
		}
	}
}

void Racing::set_race_type(race_type new_race_type) //������� ��� �����
{
	my_race_type = new_race_type;
}

race_type Racing::get_race_type() //�������� ��� �����
{
	return my_race_type;
}

void Racing::set_race_distance(int new_distance) //������� ���������
{
	race_distance = new_distance;
}

int Racing::get_race_distance() //�������� ���������
{
	return race_distance;
}

std::string Racing::race_type_invitation_string() //����������� ������� ��� �����
{	
	std::string tepm_str; 
	tepm_str =  std::to_string(static_cast<int>(race_type::race_type_land)) + ". " + race_type_name(race_type::race_type_land) + "\n";
	tepm_str += std::to_string(static_cast<int>(race_type::race_type_air))  + ". " + race_type_name(race_type::race_type_air) + "\n";
	tepm_str += std::to_string(static_cast<int>(race_type::race_type_all))  + ". " + race_type_name(race_type::race_type_all) + "\n";
	tepm_str += "�������� ��� �����: ";

	return tepm_str;
}

std::string Racing::race_distance_invitation_string() //����������� ������� ��������� �����
{
	return "������� ����� ��������� (������ ���� ������������): ";
}

std::string Racing::race_type_name(race_type race_type_x)
{	
	switch (race_type_x)
	{
	case race_type::race_type_land: return "����� ��� ��������� ����������";
	case race_type::race_type_air: return "����� ��� ���������� ����������";
	case race_type::race_type_all: return "����� ��� ��������� � ���������� ����������";
	}
}

bool Racing::get_racing_registered_transports() //��������, ���������������� �� ����������� ����� ���������� 
{
	int active_transports_counter = 0; //������� ������������������ �����������
	for (int i = 0; i < transports_array_size; ++i)
	{
		if (transports_array[i]->get_active_for_racing())
		{
			++active_transports_counter;
		}
	}
	

	if (active_transports_counter < minimum_transports_number)
	{
		return false; //����� ������ �������� - ����� ���������� ������ ���������� ����������� ����������
	}

	return true;
}

int  Racing::get_minimum_transports_number() //����������� ���������� ����������� ��� �����
{
	return minimum_transports_number;
}

int Racing::get_available_transports_number() //������� ����� �������� ���������� - ������ ������� transports_array = transports_array_size
{
	return transports_array_size;
}

std::string Racing::transport_name(int arr_index) //��� ���������� �� ������� � ������� transports_array
{
	std::string temp_str = "����������� ���������";
	if ((arr_index < transports_array_size) && (arr_index >= 0))
		if (transports_array[arr_index] != nullptr)
		{
			temp_str = transports_array[arr_index]->get_tr_name();
		}

	return temp_str;
}

double Racing::transport_result(int arr_index) //��������� (����� ����������� ���������) ���������� �� ������� � ������� transports_array
{
	if ((arr_index < transports_array_size) && (arr_index >= 0))
		if (transports_array[arr_index] != nullptr)
		{
			return transports_array[arr_index]->get_distance_time();
		}

	return -1;
}

std::string Racing::get_registered_transports_list() //������ ���� �����������, ������������������ �� �����
{
	std::string temp_str = "";
	for (int i = 0; i < transports_array_size; ++i)
	{
		if (transports_array[i] != nullptr)
		if (transports_array[i]->get_active_for_racing())
		{
			if (temp_str != "")
			{
				temp_str += ", ";
			}
			temp_str += transports_array[i]->get_tr_name();
		}
	}

	return temp_str;

}

registration_status Racing::register_transport(int index) //���������������� ��������� �� �����
{
	if ((index > transports_array_size - 1) || (index <  0))
	{
		return registration_status::reg_status_type_error;
	}
	
	if (transports_array[index]->get_active_for_racing()) //��� ���������������
	{
		return registration_status::reg_status_second_attempt; //������� ���������������� ��������� ������ ���
	}

	switch (my_race_type)
	{
		case race_type::race_type_land: //����� ������ ��� ��������
			{
				if (transports_array[index]->get_tr_type() == transport_type::tr_type_land)
				{
					transports_array[index]->set_active_for_racing(true, race_distance);
					return registration_status::reg_status_ok;
				}
				break;
			}
		case race_type::race_type_air://����� ������ ��� ���������
			{
				if (transports_array[index]->get_tr_type() == transport_type::tr_type_air)
				{
					transports_array[index]->set_active_for_racing(true, race_distance);
					return registration_status::reg_status_ok;
				}
				break;
			}
		case race_type::race_type_all:   //����� ��� ����
			{
				transports_array[index]->set_active_for_racing(true, race_distance);
				return registration_status::reg_status_ok;
				break;
			}
	}

	return registration_status::reg_status_type_error;
}

void Racing::sort_transport_places() //������������ �����
{
	sort_transport_array(transports_array, 0, transports_array_size -1);
}



void Racing::swap_transports(int i, int j) //�������� �������
{
	Transport* temp = transports_array[i];
	transports_array[i] = transports_array[j];
	transports_array[j] = temp;
}


void Racing::sort_transport_array(Transport** arr, int left, int right) //������������� ������ �� ����������� ������� ����������� �����
{
	if (left >= right)
	{
		return;
	}

	// ����������� ��������
	int pivot = pivoting(arr, left, right);

	// ����������� ��������� ����� �� ������
	sort_transport_array(arr, left, pivot - 1);

	// ����������� ��������� ������ �� ������
	sort_transport_array(arr, pivot + 1, right);
}

int Racing::pivoting(Transport** arr, int left, int right) //�������������
{
	// ����� -  ������� ������ �������  �������
	double pivot = arr[right]->get_distance_time();

	// �������� ������� ������ ������ �������������� ����� �� ������� temp
	// �������� ������� ������ ������ �������������� ������ �� ������� temp
	int temp = left;

	// ���� ������� ������� < = pivot, ������ temp �������������, �  ������� �������� ������� � �������
	for (int i = left; i < right; i++)
	{
		if (arr[i]->get_distance_time() <= pivot)
		{
			swap_transports(i, temp);
			temp++;
		}
	}

	// �������� �������  � �������
	swap_transports(temp, right);

	// ������� ����� ������ ������
	return temp;
}

