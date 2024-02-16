/*
 * DC_motor.h
 *
 *  Created on: Feb 15, 2024
 *      Author: Apex
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "state.h"


typedef enum {
    DC_motor_idle,
    DC_motor_busy
} DC_Motor_States;

// Define DC motor state variable
extern DC_Motor_States DC_motor_state_id;

//define states function
STATE_define(DC_motor_idle);
STATE_define(DC_motor_busy);

void DC_motor_init();
//state pointer to function
extern void(*DC_motor_state)();


#endif /* DC_MOTOR_H_ */
