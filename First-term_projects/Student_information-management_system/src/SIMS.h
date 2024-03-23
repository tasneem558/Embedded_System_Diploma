/*
 * SIMS.h
 *
 *  Created on: Mar 21, 2024
 *      Author: tasneem
 */
#ifndef SIMS_H_
#define SIMS_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define DPRINTF(...)    {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

//data types:
typedef struct
{
	char Fname[50];
	char Lname[50];
	int roll;
	float GPA;
	int Cid[10];
}st;
extern st buff[100];

typedef struct
{
	unsigned int  length;
	unsigned int  count;
	st* base;
	st* head;
	st* tail;
}SISM_Buff_t;

typedef enum
{
	SISM_no_error,
    SISM_error,
	SISM_full,
	SISM_empty,
	SISM_null
}SISM_Buff_status;


//function declarations
int check_roll(SISM_Buff_t* fifo,int r);
SISM_Buff_status FIFO_init(SISM_Buff_t* fifo,st* buff, int length);
SISM_Buff_status add_student_file(SISM_Buff_t* fifo);
SISM_Buff_status add_student_manually(SISM_Buff_t* fifo);
SISM_Buff_status find_rl(SISM_Buff_t* fifo);
SISM_Buff_status find_Fn(SISM_Buff_t* fifo);
SISM_Buff_status find_C(SISM_Buff_t* fifo);
SISM_Buff_status tot_s(SISM_Buff_t* fifo);
SISM_Buff_status shift_buffer(int index,SISM_Buff_t* fifo);
SISM_Buff_status del_s(SISM_Buff_t* fifo);
SISM_Buff_status up_s(SISM_Buff_t* fifo);
SISM_Buff_status show_s(SISM_Buff_t* fifo);


#endif /* SIMS_H_ */
