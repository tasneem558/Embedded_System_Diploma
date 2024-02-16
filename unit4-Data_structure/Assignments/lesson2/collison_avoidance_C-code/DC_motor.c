/*
 * DC_motor.c
 *
 *  Created on: Feb 15, 2024
 *      Author: Apex
 */


#include "DC_motor.h"

//variables
int DC_motor_speed=0;

//state pointer to function
void(*DC_motor_state)();
void DC_motor_set_speed(int s)
{
   DC_motor_speed = s;
   DC_motor_state = STATE(DC_motor_busy);
   printf("CA------->speed=%d------>DC_motor \n",DC_motor_speed);
}

void DC_motor_init()
{
	//init_DC_motor
	printf("DC_motor_init \n");
}

STATE_define (DC_motor_idle)
{
	//state_name
	DC_motor_state_id = DC_motor_idle;
	DC_motor_state = STATE(DC_motor_idle);
	printf("DC_motor_idle state: speed=%d \n",DC_motor_speed);
}

STATE_define (DC_motor_busy)
{
	//state_name
     DC_motor_state_id = DC_motor_busy ;
     DC_motor_state = STATE(DC_motor_busy);
     printf("DC_motor_busy state: speed=%d \n",DC_motor_speed);
}
