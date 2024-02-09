/*
 * lifo.h
 *
 *  Created on: Feb 5, 2024
 *      Author: Apex
 */
#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdlib.h"
#include "platform_types.h"

//user configuration:
//choose data type of element (uint8_t,uint16_t,uint32_t,...)
#define element_type uint8

//data types:
typedef struct
{
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
}LIFO_Buf_t;

typedef enum
{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_null

}LIFO_Buf_status;

//API:

LIFO_Buf_status LIFO_init(LIFO_Buf_t* lifo,element_type* buffer,uint32 length);
LIFO_Buf_status LIFO_add_item(LIFO_Buf_t* lifo,element_type item);
LIFO_Buf_status LIFO_get_item(LIFO_Buf_t* lifo,element_type* item);



#endif /* LIFO_H_ */
