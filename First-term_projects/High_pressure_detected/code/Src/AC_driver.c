/*
 * AC_driver.c
 *
 *  Created on: Mar 12, 2024
 *      Author: tasneem
 */

#include "AC_driver.h"
#include "driver.h"

extern int alarm_flag;

//define state pointer to func
void (*AC_state)();

//define init func
void init_AC()
{
    //init alarm actuator driver
    GPIO_INITIALIZATION();
}

void start_alarm()
{
    Set_Alarm_actuator(0);
}

void stop_alarm()
{
   Set_Alarm_actuator(1);
}

//define states func
STATE_define(AC_waiting)
{
  if(alarm_flag ==0)
  {
    stop_alarm();
    AC_state =STATE(AC_alarm_off);
  }
  if(alarm_flag ==1)
  {
    start_alarm();
    AC_state =STATE(AC_alarm_on);
  }
  
}
STATE_define(AC_alarm_off)
{
  //STATE NAME
  AC_state_id = AC_alarm_off;

  AC_state = STATE(AC_waiting);
}
STATE_define(AC_alarm_on)
{
    //STATE NAME
    AC_state_id = AC_alarm_on;

    AC_state = STATE(AC_waiting);
}
