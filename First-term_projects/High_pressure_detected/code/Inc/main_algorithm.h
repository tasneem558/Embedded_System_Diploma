/*
 * main_algorithm.h
 *
 *  Created on: Mar 12, 2024
 *      Author: tasneem
 */

#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_

#include "states.h"
//define states
typedef enum {
    higher_pressure_detected

} mainALG_States;


// Define mainALG state variable
extern mainALG_States mainALG_state_id;
extern volatile int pressure_val;

//define states function
STATE_define(mainALG_HP_detected);

//state pointer to function
extern void(*mainALG_state)();

#endif /* MAIN_ALGORITHM_H_ */
