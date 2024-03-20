/*
 * main_algorithm.c
 *
 *  Created on: Mar 12, 2024
 *      Author: tasneem
 */


#include "main_algorithm.h"
#include "driver.h"
//define variables
int get_Pval = 0;
int threshold = 20;

//state pointer to function
void(*mainALG_state)();

void setPressureVal(int Pval)
{
	get_Pval = Pval;
}

//states function
STATE_define (mainALG_HP_detected)
{
    //state name
    mainALG_state_id = higher_pressure_detected;
    //state action
    if(get_Pval>threshold)
    {
    	High_pressure_detected();
    }
    //else
       //No high pressure detected
    mainALG_state = STATE(mainALG_HP_detected);
}
