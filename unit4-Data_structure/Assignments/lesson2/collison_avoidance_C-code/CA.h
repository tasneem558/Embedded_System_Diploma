/*
 * CA.h
 *
 *  Created on: Feb 15, 2024
 *      Author: Apex
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"

//define states
typedef enum {
    CA_waiting,
    CA_driving
} CA_States;

// Define CA state variable
extern CA_States CA_state_id;

//define states function
STATE_define(CA_waiting);
STATE_define(CA_driving);


//state pointer to function
extern void(*CA_state)();
#endif /* CA_H_ */
