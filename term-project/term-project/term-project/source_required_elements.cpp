#include "source_required_elements.h"

namespace racing_context
{

	race_type get_race_type(Racing* new_racing) //����� ������������� ���� �����
	{
		int race_type_number = 0;

		while (race_type_number == 0)
		{
			std::cout << new_racing->race_type_invitation_string();
			std::cin >> race_type_number;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "�������� ��� ����� \n";
				race_type_number = 0;
			}

			race_type race_type_temp = static_cast<race_type>(race_type_number);

			if ((race_type_number < 1) ||
				(race_type_number > 3))
			{
				std::cout << "�������� ��� ����� \n";
				race_type_number = 0;
			}
		}

		return static_cast<race_type>(race_type_number);

	}

	int get_distance(Racing* new_racing) //����� ������������� ���������
	{
		int new_distance = -1;

		while (new_distance < 0)
		{
			std::cout << new_racing->race_distance_invitation_string(); //"������� ����� ��������� (������ ���� ������������) \n";
			std::cin >> new_distance;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "�������� ��������� \n";
				new_distance = -1;
			}

			if (new_distance < 0)
			{
				std::cout << "��������� ������ ���� ������ 0 \n";
			}
		}

		return new_distance;
	}

	actions_before_racing get_racing_start_action(Racing* new_racing) //����� ������������� �������� ����� ������
	{
		int new_action = -1;
		bool temp_bool = new_racing->get_racing_registered_transports(); //��������, ���������������� �� ����������� ����� ���������� 

		std::cout << "\n";
		if (!temp_bool) // ���������������� �� ����������� ����� ���������� 
		{
			std::cout << "������ ���� ���������������� ���� �� " << new_racing->get_minimum_transports_number() << " ������������ ��������\n";
		}

		std::cout << "1. ���������������� ���������\n";

		if (temp_bool)
		{
			std::cout << "2. ������ �����\n";
		}

		while (!valid_action_before_racing(new_action, new_racing))	//valid_action_before_racing - �������� �� ����� ��������  ������������� ����������
		{
			std::cout << "�������� ��������: ";
			std::cin >> new_action;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "�������� ���� \n";
				new_action = -1;
			}
			std::cout << "\n";
		}

		return static_cast<actions_before_racing>(new_action);
	}

	bool valid_action_before_racing(int new_action, Racing* new_racing) //�������� �� ����� ��������  ������������� ����������
	{
		switch (new_action)
		{
		case 1: return true; //������ ����� ���������� ������� �����������
		case 2: //����� �� �������� �����

		{
			if (new_racing->get_racing_registered_transports()) //��������, ���������������� �� ����������� ����� ���������� 
			{
				return true;
			}
			else
			{
				return false;
			}
		default: return false; //������� ������ �������� �� �������������

		}
		}
	}

	void execute_action_before_racing(actions_before_racing new_action, Racing* new_racing) //��������� ��������, ��������� ������������� ����� ������
	{
		if (new_action == action_register_transport) //����������� ���������� �� �����
		{
			register_transport(new_racing); //���������������� ��������� �� �����		
		}
		else
			if (new_action == action_start_racing)
			{
				//����� ������� ����������� ����� ����������� ������ �� �������
				new_racing->sort_transport_places();
				print_results(new_racing);
			}
	}

	void register_transport(Racing* new_racing) //���������������� ��������� �� �����
	{
		while (1)
		{
			//������� ����� ���������� �� �����
			switch (new_racing->get_race_type())
			{
			case race_type::race_type_land:
				std::cout << "����� ��� ��������� ����������. ";
				break;
			case race_type::race_type_air:
				std::cout << "����� ��� ���������� ����������. ";
				break;
			case race_type::race_type_all:
				std::cout << "����� ��� ��������� � ���������� ����������. ";
				break;
			}

			std::cout << "����������: " << new_racing->get_race_distance() << "\n";

			// ������� ������ ��� ������������������
			std::string temp_str = new_racing->get_registered_transports_list(); //������ ���� �����������, ������������������ �� �����
			if (temp_str != "")
			{
				std::cout << "������������������ ����������: " << temp_str << "\n";
			}

			//������� ������ ��������� ��� ����������� �����������
			for (int i = 0; i < new_racing->get_available_transports_number(); ++i)
			{
				std::cout << i + 1 << ". " << new_racing->transport_name(i) << "\n"; //��� ���������� �� ������� � ������� transports_array
			}

			std::cout << "0. ��������� �����������\n";
			std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";

			//�����, ��������� �������������
			int registration_action = -1;
			while (registration_action < 0)
			{
				std::cin >> registration_action;

				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "�������� ���� \n";
					registration_action = -1;
				}

				if (registration_action > new_racing->get_available_transports_number())
				{
					std::cout << "������ ���������� ���. �������� ����� ���������� �� ������ ��� 0 ��� ���������� �����������. \n";
					registration_action = -1;
				}
			}

			if (registration_action == 0)
			{
				return;
			}
			else
			{
				registration_status reg_status = new_racing->register_transport(registration_action - 1);
				std::cout << "\n";

				switch (reg_status)
				{
				case registration_status::reg_status_ok:
					std::cout << new_racing->transport_name(registration_action - 1) << " ������� ���������������!\n";
					break;
				case registration_status::reg_status_second_attempt:
					std::cout << new_racing->transport_name(registration_action - 1) << " ��� ���������������!\n";
					break;
				case registration_status::reg_status_type_error:
					std::cout << "������� ���������������� ������������ ��� ������������� ��������!\n";
					break;
				}
			}
		}
	}

	void print_results(Racing* new_racing) //���������� ���������� �����
	{
		std::cout << "���������� �����: \n";

		int counter = 1; //����� �����
		for (int i = 0; i < new_racing->get_available_transports_number(); ++i) //��������� ������ ����������� �����
		{
			double temp;
			temp = new_racing->transport_result(i); //��������� ����� ����������� �����
			if (temp > 0)  //����������, �� ����������� � �����, ����� ����� ����������� -1
			{
				std::cout << counter << ". " << new_racing->transport_name(i) << ". �����: " << temp << "\n";
				++counter; //��������� ����� ����� ��� ���������� ��������� �����
			}
		}
	}

	actions_after_racing get_racing_end_action() //����� ������������� �������� ����� ������
	{
		int new_action = -1;

		std::cout << "\n";
		std::cout << "1. �������� ��� ���� �����\n";
		std::cout << "2. �����\n";

		while ((new_action <= 0) || (new_action > 2))
		{
			std::cout << "�������� ��������: ";
			std::cin >> new_action;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "�������� ���� \n";
				new_action = -1;
			}
			std::cout << "\n";
		}

		return static_cast<actions_after_racing>(new_action);
	}

} // namespace racing_context
