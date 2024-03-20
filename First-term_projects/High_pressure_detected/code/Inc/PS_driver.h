/*
 * PS_driver.h
 *
 *  Created on: Mar 12, 2024
 *      Author: tasneem
 */

#ifndef PS_DRIVER_H_
#define PS_DRIVER_H_

#include "states.h"
typedef enum
{
    PS_Reading,
    PS_Waiting

}PS_states;

// define ps states variable
extern PS_states PS_state_id;
extern volatile int pressure_val;
// INIT FUNC
void PS_init();

//state functions
STATE_define(PS_Reading);
STATE_define(PS_Waiting);

//pointer to function
extern void (*ps_state)();


#endif /* PS_DRIVER_H_ */
