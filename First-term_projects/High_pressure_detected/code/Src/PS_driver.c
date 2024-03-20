/*
 * PS_driver.c
 *
 *  Created on: Mar 12, 2024
 *      Author: tasneem
 */

#include "PS_driver.h"
#include "driver.h"
//variables:
int Pval =0;
int pull_timer = 0;

//pointer to func
void (*ps_state)();

//init pressure sensor
void PS_init()
{
   GPIO_INITIALIZATION();
}

//states func
STATE_define(PS_Reading)
{
    //state name
    PS_state_id = PS_Reading;
    //action
    Pval = getPressureVal();
    setPressureVal(Pval);
    pull_timer = 100000;
    ps_state = STATE(PS_Waiting);

}
STATE_define(PS_Waiting)
{
    //state name
    PS_state_id = PS_Waiting;
    //ACTION
    Delay(pull_timer);
    pull_timer = 0;
    ps_state = STATE(PS_Reading);

}

