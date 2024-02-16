/*
 * CA.c
 *
 *  Created on: Feb 15, 2024
 *      Author: Apex
 */


//variables

#include "CA.h"
int CA_speed=0;
int CA_distance=0;
int CA_threshold=50;

//state pointer to function
void(*CA_state)();
void US_set_distance (int d)
{
	CA_distance = d;
    (CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
	printf("Us------->distance=%d------>CA \n",CA_distance);
}
STATE_define (CA_waiting)
{
	//state_name
	CA_state_id = CA_waiting;
	printf("CA_waiting state: distance =%d speed=%d \n",CA_distance,CA_speed);
	//state_action
    CA_speed =0;
    DC_motor_set_speed(CA_speed);

}

STATE_define (CA_driving)
{
	//state_name
     CA_state_id = CA_driving ;
     printf("CA_waiting state: distance =%d speed=%d \n",CA_distance,CA_speed);
	//state_action
    CA_speed = 30;
    DC_motor_set_speed(CA_speed);
}
