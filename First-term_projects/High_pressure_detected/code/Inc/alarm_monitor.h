/*
 * alarm_monitor.h
 *
 *  Created on: Mar 12, 2024
 *      Author: tasneem
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "states.h"
//define states
typedef enum
{
    AM_alarm_off,
    AM_alarm_on,
    AM_waiting
}AM_states;

//declar states variables
extern AM_states AM_state_id;
extern volatile int pressure_val;

//declare state pointer to function
extern void (*AM_state)();

//states func
STATE_define(AM_alarm_off);
STATE_define(AM_alarm_on);
STATE_define(AM_waiting);

#endif /* ALARM_MONITOR_H_ */
