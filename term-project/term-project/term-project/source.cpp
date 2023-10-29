#include <iostream>
#include <string>

//������ �����
#include "racing-lib/include/racing.h"

//���������
#include "racing-lib/include/transport_broom.h"
#include "racing-lib/include/transport_eagle.h"
#include "racing-lib/include/transport_magic_carpet.h"
#include "racing-lib/include/transport_crosscountry_boots.h"
#include "racing-lib/include/transport_centaur.h"
#include "racing-lib/include/transport_high_speed_camel.h"
#include "racing-lib/include/transport_camel.h"

//�������������� �������
#include "source_required_elements.h"

#define NOMINMAX


int main()
{
	setlocale(LC_ALL, "rus");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	std::cout << "����� ���������� � �������� ���������!\n";
	while (1)
	{
		Racing* new_racing;
		new_racing = new Racing();

		try
		{
			new_racing->racing_init();
		}
		catch (const RacingException& ex)
		{
			std::cout << ex.what();
		}
		catch (...)
		{
			std::cout << "������ ����� racing �� ������\n";			
		}

		if (! new_racing->get_racing_ready())
		{
			delete new_racing;
			new_racing = nullptr;
			std::cout << "���������� �������� �����\n";
			return 0;

		}
	
		race_type new_race_type = racing_context::get_race_type(new_racing); //����� ������������� ���� �����
		new_racing->set_race_type(new_race_type);
		int new_distance = racing_context::get_distance(new_racing); //����� ������������� ���������
		new_racing->set_race_distance(new_distance);

		//����� �������� �������������
		//�������� ����� ������
		racing_context::actions_before_racing new_action_br = racing_context::actions_before_racing::action_br_incorrect;  // ����� ���������� ��������
		while (new_action_br != racing_context::actions_before_racing::action_start_racing)
		{
				new_action_br = racing_context::get_racing_start_action(new_racing); //����� ������������� �������� ����� ������	
				execute_action_before_racing(new_action_br, new_racing); //��������� ��������, ��������� ������������� ����� ������				
		}
		
		delete new_racing;
		
		//�������� ����� �����
		racing_context::actions_after_racing new_action_ar = racing_context::actions_after_racing::action_ar_incorrect;  // ����� ���������� ��������
		new_action_ar = racing_context::get_racing_end_action(); //����� ������������� �������� ����� ������
		if (new_action_ar == racing_context::action_exit)
		{
				return 0; //����� �� ���������
		}

	}
	
	return 0;
}
