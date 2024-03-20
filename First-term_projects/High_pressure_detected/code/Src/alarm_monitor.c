/*
 * alarm_monitor.c
 *
 *  Created on: Mar 12, 2024
 *      Author: tasneem
 */


#include "alarm_monitor.h"
#include "main_algorithm.h"
#include "driver.h"
//define variables
unsigned int alarm_timer = 0;
int alarm_flag = 0;
//define pointer to function
void (*AM_state)();


void High_pressure_detected()
{
    AM_state = STATE(AM_alarm_on);
}
//define states function
STATE_define(AM_alarm_off)
{
    //state name
    AM_state_id = AM_alarm_off;
    //STATE ACTION
    alarm_flag = 0;
    stop_alarm();
    AM_state = STATE(AM_alarm_off);

}
STATE_define(AM_alarm_on)
{
    //state name
    AM_state_id = AM_alarm_on;
    //STATE ACTION
    alarm_flag = 1;
    start_alarm();
    alarm_timer = 60000;
    AM_state = STATE(AM_waiting);
    AM_state();
}
STATE_define(AM_waiting)
{
    //state name
    AM_state_id = AM_waiting;
    //STATE ACTION
    Delay(alarm_timer);
    alarm_timer =0;
    stop_alarm();
    AM_state = STATE(AM_alarm_off);
    AM_state();
}
