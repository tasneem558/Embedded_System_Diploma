/*
 * states.h
 *
 *  Created on: Mar 12, 2024
 *      Author: tasneem
 */

#ifndef STATES_H_
#define STATES_H_

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

#define HIGH_PRESSURE		((int)1)
#define NORMAL_PRESSURE		((int)0)

//states connection
void setPressureVal(int Pval);
void High_pressure_detected();
void start_alarm();
void stop_alarm();

#endif /* STATES_H_ */
