/*
 * AC_driver.h
 *
 *  Created on: Mar 12, 2024
 *      Author: tasneem
 */

#ifndef AC_DRIVER_H_
#define AC_DRIVER_H_

#include "states.h"
//define states
typedef enum
{
   AC_waiting,
   AC_alarm_off,
   AC_alarm_on
}AC_states;

//define state variable
extern AC_states AC_state_id;

//define init func
void init_AC();

//define state func
STATE_define(AC_waiting);
STATE_define(AC_alarm_off);
STATE_define(AC_alarm_on);

//define state pointer to func
extern void (*AC_state)();

#endif /* AC_DRIVER_H_ */
