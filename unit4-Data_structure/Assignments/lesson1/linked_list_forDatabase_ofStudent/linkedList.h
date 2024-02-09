/*
 * linkedList.h
 *
 *  Created on: Feb 9, 2024
 *      Author: Apex
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

//effective data
struct Sdata
{
	int ID;
	char name[40];
	float height;
};

//linked list node
struct Sstudent
{
	struct Sdata student;
	struct Sstudent* pNextStudent;
};

//API
void fill_record(struct Sstudent* new_student);
void add_student();
int delete_student();
void view_student();
void delete_all();
void GetNth();
//iterative method
int getLenght();
//recursive method
int rgetLenght();
void GetNth_from_theEnd();
void getMiddle_student();
void reverse_list();


#endif /* LINKEDLIST_H_ */
