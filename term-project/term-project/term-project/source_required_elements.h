#pragma once

#include <iostream>
#include <string>

//модуль гонок
#include "racing-lib/include/racing.h"

//транспорт
#include "racing-lib/include/transport_broom.h"
#include "racing-lib/include/transport_eagle.h"
#include "racing-lib/include/transport_magic_carpet.h"
#include "racing-lib/include/transport_crosscountry_boots.h"
#include "racing-lib/include/transport_centaur.h"
#include "racing-lib/include/transport_high_speed_camel.h"
#include "racing-lib/include/transport_camel.h"

namespace racing_context
{
	enum actions_before_racing { action_br_incorrect = -1, action_register_transport = 1, action_start_racing };
	enum actions_after_racing { action_ar_incorrect = -1, action_new_racing = 1, action_exit };

	race_type get_race_type(Racing* new_racing); //выбор пользователем типа гонки
	int get_distance(Racing* new_racing); //выбор пользователем дистанции
	actions_before_racing get_racing_start_action(Racing* new_racing); //выбор пользователем действий перед гонкой
	actions_after_racing get_racing_end_action(); //выбор пользователем действий после гонкой
	bool valid_action_before_racing(int new_action, Racing* new_racing); //является ли выбор действия  пользователем корректным
	void execute_action_before_racing(actions_before_racing new_action, Racing* new_racing); //выполнить действие, выбранное пользователем перед гонкой
	void register_transport(Racing* new_racing); //зарегестрировать транспорт на гонку
	void print_results(Racing* new_racing); //отобразить результаты гонок

} //namespace racing_context