/*
 * main.c
 *
 *  Created on: Feb 9, 2024
 *      Author: Apex
 */

#include "linkedList.h"

#define DPRINTF(...)    {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

char temp_text1[40];

int main()
{
	while(1)
	{
		DPRINTF("\n  <-------------------->");
		DPRINTF("\n\t Choose one of the following options: \n");
		DPRINTF("\n 1: Add_student ");
		DPRINTF("\n 2: Delete_student ");
		DPRINTF("\n 3: View_students ");
		DPRINTF("\n 4: Delete all ");
		DPRINTF("\n 5: Get specific data ");
		DPRINTF("\n 6: lenght of list is ");
		DPRINTF("\n 7: Get specific data from the end");
		DPRINTF("\n 8: Get middle data ");
		DPRINTF("\n 9: Get data in reverse");

		DPRINTF("\n Enter option number : ");
		gets(temp_text1);
		DPRINTF("\n  <-------------------->");
		switch(atoi(temp_text1))
		{
		case 1:
			add_student();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_student();
			break;
		case 4:
			delete_all();
			break;
		case 5:
			GetNth();
			break;
		case 6:
			printf("\n length with iterative method is %d",getLenght());
			//getLenght();
			//printf("\n length with recursive method is ");
			//rgetLenght();
			break;
		case 7:
			GetNth_from_theEnd();
			break;
		case 8:
			getMiddle_student();
			break;
		case 9:
			reverse_list();
			break;
		default:
			DPRINTF("\n Wrong option");
			break;
		}
	}
	return 0;
}


