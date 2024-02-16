/*
 * state.h
 *
 *  Created on: Feb 15, 2024
 *      Author: Apex
 */


#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"

#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_


//states connection
void US_set_distance (int d);
void DC_motor_set_speed(int s);
#endif /* STATE_H_ */
