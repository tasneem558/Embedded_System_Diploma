/*
 * main.c
 *
 *  Created on: Feb 15, 2024
 *      Author: Apex
 */

#include "CA.h"
#include "DC_motor.h"
#include "US.h"

CA_States CA_state_id;
US_States US_state_id;
DC_Motor_States DC_motor_state_id;

void setup()
{
	US_init();
	DC_motor_init();
	CA_state = STATE(CA_waiting);
	DC_motor_state = STATE(DC_motor_idle);
	US_state = STATE(US_busy);
}
int  main()
{
	volatile int d;
	setup();
	while(1)
	{
		//call state for each block
		US_state();
		CA_state();
		DC_motor_state();

		//delay
		for(d=0; d<=1000;d++);
	}
	return 0;
}
