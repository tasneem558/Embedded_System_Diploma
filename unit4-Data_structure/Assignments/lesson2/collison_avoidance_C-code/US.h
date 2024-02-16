/*
 * US.h
 *
 *  Created on: Feb 15, 2024
 *      Author: Apex
 */

#ifndef US_H_
#define US_H_
#include "state.h"

typedef enum {
    US_busy
} US_States;

// Define US state variable
extern US_States US_state_id;

//define states function
STATE_define(US_busy);

void US_init();

//state pointer to function
extern void(*US_state)();

#endif /* US_H_ */
