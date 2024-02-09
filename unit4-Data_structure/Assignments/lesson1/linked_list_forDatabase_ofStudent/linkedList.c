/*
 * linkedList.c
 *
 *  Created on: Feb 9, 2024
 *      Author: Apex
 */

#include "linkedList.h"

#define DPRINTF1(...)    {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

char temp_text[40];
struct Sstudent* gpFirstStudent = NULL;

void fill_record(struct Sstudent* new_student)
{
	DPRINTF1("\n Enter The ID : ");
	gets(temp_text);
	new_student->student.ID = atoi(temp_text);

	DPRINTF1("\n Enter Student Full Name : ");
	gets(new_student->student.name);

	DPRINTF1("\n Enter Height : ");
	gets(temp_text);
	new_student->student.height = atof(temp_text);
}

void add_student()
{
	struct Sstudent* pLastStudent ;
	struct Sstudent* pNew_student;
	if(gpFirstStudent == NULL) //list is empty
	{
		//create first record
		pNew_student = (struct Sstudent*)malloc(sizeof(struct Sstudent));
		//ASSIGN GPFIRST_student to it
		gpFirstStudent = pNew_student;
	}
	else //list is not empty
	{
		//navigate untill reach to the last record
		pLastStudent = gpFirstStudent;
		while(pLastStudent->pNextStudent) // while not = null
		{
			pLastStudent=pLastStudent->pNextStudent;
		}
		//create new record and assign pnext to it
		pNew_student = (struct Sstudent*)malloc(sizeof(struct Sstudent));
		pLastStudent->pNextStudent = pNew_student;

	}
	//fill new record
	fill_record(pNew_student);
	//set next record to null
	pNew_student->pNextStudent = NULL;
}

int delete_student()
{
	int selected_id;
	//get selected recorded id from user
	DPRINTF1("\n Enter Student Id to be deleted : ");
	gets(temp_text);
	selected_id = atoi(temp_text);

	if(gpFirstStudent) // list have records
	{
		struct Sstudent* pPreviousStudent = NULL;
		struct Sstudent* pSelectedStudent = gpFirstStudent;
		//loop on all records untill get selected id record
		while(pSelectedStudent)
		{
			//compare recorded id with selected
			if(pSelectedStudent->student.ID == selected_id)
			{
				if(pPreviousStudent)
				{
					pPreviousStudent->pNextStudent =pSelectedStudent->pNextStudent;
				}
				else // in first record
				{
					gpFirstStudent=pSelectedStudent->pNextStudent;
				}
				free(pSelectedStudent);
				return 1;//find it
			}
			//store previous record pointer
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->pNextStudent;
		}

	}

	DPRINTF1("\n cannot find student ID.");
	return 0; // can't find
}

void view_student()
{
	int count =0;
	struct Sstudent* pCurrent_student = gpFirstStudent;
	if(gpFirstStudent == NULL)
		DPRINTF1("\n List Is Empty ");
	while(pCurrent_student)
	{
		DPRINTF1("\n Record Number %d",count+1);
		DPRINTF1("\n ID: %d",pCurrent_student->student.ID);
		DPRINTF1("\n Name: %s",pCurrent_student->student.name);
		DPRINTF1("\n Height: %f",pCurrent_student->student.height);
		pCurrent_student = pCurrent_student->pNextStudent;
		count++;
	}
}

void delete_all()
{

	struct Sstudent* pCurrent_student = gpFirstStudent;
	if(gpFirstStudent == NULL)
		DPRINTF1("\n List Is Empty ");
	while(pCurrent_student)
	{
		struct Sstudent* pTemp_student= pCurrent_student;
		pCurrent_student = pCurrent_student->pNextStudent;
		free(pTemp_student);
	}
	gpFirstStudent = NULL;

}

void GetNth()
{
	int index,count =0;
	DPRINTF1("\n Enter The Index Of Node that you want to get it's data :");
	gets(temp_text);
	index = atoi(temp_text);
	struct Sstudent* pCurrent_student = gpFirstStudent;
	if(gpFirstStudent == NULL)
		printf("\n List is empty ");
	while(pCurrent_student)
	{
		if(index == count) // data user want
		{
			DPRINTF1("\n Data you want are :");
			DPRINTF1("\n ID: %d",pCurrent_student->student.ID);
			DPRINTF1("\n Name: %s",pCurrent_student->student.name);
			DPRINTF1("\n Height: %f",pCurrent_student->student.height);
		}
		else if(pCurrent_student->pNextStudent == NULL)
		{
			if(index != count)
				printf("\n --------->Not valid index<------------ ");
		}
		count++;
		pCurrent_student=pCurrent_student->pNextStudent;

	}


}

//iterative method
int getLenght()
{
	int count =0;
	struct Sstudent* pCurrent_student = gpFirstStudent;
	while(pCurrent_student)
	{
		pCurrent_student=pCurrent_student->pNextStudent;
		count++;
	}
	//printf("%d",count);
	return count;

}

//recursive method
int rgetLenght()
{
	int count =1;
	struct Sstudent* pCurrent_student = gpFirstStudent;
	while(pCurrent_student)
	{
		pCurrent_student=pCurrent_student->pNextStudent;
		return count + rgetLenght();
	}
	return 0;
}


void GetNth_from_theEnd()
{
	int n , count =0;
	struct Sstudent* pMain_student = gpFirstStudent;
	struct Sstudent* pReference_student = gpFirstStudent;
	DPRINTF1("\n Enter Number of node: ");
	gets(temp_text);
	n=atoi(temp_text);

	while( n != count)
	{
		pReference_student=pReference_student->pNextStudent;
		count++;
	}
	if(n==count)
	{
		while(pReference_student)
		{
			pReference_student=pReference_student->pNextStudent;
			pMain_student=pMain_student->pNextStudent;
		}
		DPRINTF1("\n Data you want are :");
		DPRINTF1("\n ID: %d",pMain_student->student.ID);
		DPRINTF1("\n Name: %s",pMain_student->student.name);
		DPRINTF1("\n Height: %f",pMain_student->student.height);
	}
}


void getMiddle_student()
{
	struct Sstudent* pFast_student = gpFirstStudent;
	struct Sstudent* pSlow_student = gpFirstStudent;
	while(pFast_student->pNextStudent)
	{
		pFast_student=pFast_student->pNextStudent->pNextStudent;
		pSlow_student=pSlow_student->pNextStudent;
		if((getLenght())%2 !=0)  //if length is odd
		{
			DPRINTF1("\n Data you want are :");
			DPRINTF1("\n ID: %d",pSlow_student->student.ID);
			DPRINTF1("\n Name: %s",pSlow_student->student.name);
			DPRINTF1("\n Height: %f",pSlow_student->student.height);
			break;
		}
		else if(pFast_student->pNextStudent->pNextStudent == NULL) //if length is even 2 middle are there and output second middle
		{
			pSlow_student=pSlow_student->pNextStudent;
			DPRINTF1("\n Data you want are :");
			DPRINTF1("\n ID: %d",pSlow_student->student.ID);
			DPRINTF1("\n Name: %s",pSlow_student->student.name);
			DPRINTF1("\n Height: %f",pSlow_student->student.height);
			break;
		}
	}
}

void reverse_list()
{
    int i;
    DPRINTF1("\n Enter size of list:");
    gets(temp_text);
    i = atoi(temp_text);

    // Clear the previous list
    delete_all();

    // Add new records to the list
    while (i > 0)
    {
        add_student();
        i--;
    }

    // Display the original list before reversal
    DPRINTF1("\n Original list before reversal: \n");
    view_student();
    DPRINTF1("\n---------------------------------------------");
    // Reversing the list
    struct Sstudent* pPrevious = NULL;
    struct Sstudent* pCurrent = gpFirstStudent;
    struct Sstudent* next = NULL;

    while (pCurrent != NULL) {
        next = pCurrent->pNextStudent; // Store the next pointer
        pCurrent->pNextStudent = pPrevious; // Reverse the pointer
        pPrevious = pCurrent; // Move pointers one step forward
        pCurrent = next;
    }

    // Update the head pointer to the last node
    gpFirstStudent = pPrevious;

    // Display the reversed list after reversal
    DPRINTF1("\n Reversed list after reversal:");
    view_student();
}



