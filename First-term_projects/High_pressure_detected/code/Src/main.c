/*
 * main.c
 *
 *  Created on: Mar 12, 2024
 *      Author: tasneem
 */
#include "states.h"
#include "driver.h"
#include "PS_driver.h"
#include "main_algorithm.h"
#include "alarm_monitor.h"
#include "AC_driver.h"

PS_states PS_state_id;
mainALG_States mainALG_state_id;
AM_states AM_state_id;
AC_states AC_state_id;

void setup()
{
	init_AC();
	PS_init();
	AM_state = STATE(AM_alarm_off);
	ps_state= STATE(PS_Reading);
	mainALG_state = STATE(mainALG_HP_detected);
	stop_alarm();
	AC_state = STATE(AC_waiting);
}

int main ()
{
//	GPIO_INITIALIZATION();
	setup();
	while (1)
	{
		ps_state();
		mainALG_state();
		AM_state();
        AC_state();
	}
	Delay(50000);
    return 0;
}

