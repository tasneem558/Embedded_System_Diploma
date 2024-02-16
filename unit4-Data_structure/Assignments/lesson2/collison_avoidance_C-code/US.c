/*
 * US.c
 *
 *  Created on: Feb 15, 2024
 *      Author: Apex
 */


#include "US.h"
//variables
int US_distance=0;

//state pointer to function
void(*US_state)();
int US_get_distance_random(int l,int r,int count);

void US_init()
{
	//init_us_driver
	printf("US_init \n");
}

STATE_define (US_busy)
{
	//state_name
	US_state_id = US_busy;
	//state_action
    US_distance = US_get_distance_random(45,55,1);
    printf("US_busy state: distance =%d \n",US_distance);
    US_set_distance(US_distance);
    US_state = STATE(US_busy);
}
int US_get_distance_random(int l,int r,int count)
{
	int i , rand_num;
	for(i=0;i<count;i++)
	{
	   rand_num = (rand() %(r-l+1))+l;
	}
	return rand_num;
}

