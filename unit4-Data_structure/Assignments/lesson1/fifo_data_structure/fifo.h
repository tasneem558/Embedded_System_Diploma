/*
 * fifo.h
 *
 *  Created on: Feb 5, 2024
 *      Author: Apex
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "platform_types.h"
//user configuration:
//select element_data_type (uint8,uint16,uint32,....)
#define element_type uint8

//data types:
typedef struct
{
	unsigned int  length;
	unsigned int  count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buff_t;

typedef enum
{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_Buff_status;

//API
FIFO_Buff_status FIFO_init(FIFO_Buff_t* fifo,element_type* buff, uint32 length);
FIFO_Buff_status FIFO_enqeueu(FIFO_Buff_t* fifo,element_type item);
FIFO_Buff_status FIFO_deqeueu(FIFO_Buff_t* fifo,element_type* item);
FIFO_Buff_status FIFO_is_full(FIFO_Buff_t* fifo);
void FIFO_print(FIFO_Buff_t* fifo);

#endif /* FIFO_H_ */
