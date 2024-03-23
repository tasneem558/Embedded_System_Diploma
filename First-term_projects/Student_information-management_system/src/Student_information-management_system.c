/*
 ============================================================================
 Name        : Student_information-management_system.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "SIMS.h"
st buff[100];
int main(void) {
	int task;
	    SISM_Buff_t buff_controller;
	    FIFO_init(&buff_controller,buff,100);
		DPRINTF("Welcome to the Student Management System\n");
		while(1)
		{
			DPRINTF("Choose The Task that you want to perform\n");
			DPRINTF("--------------------------------------------------\n");
			DPRINTF("1. Add the Student Details Manually\n");
			DPRINTF("2. Add the Student Details From Text File\n");
			DPRINTF("3. Find the Student Details by Roll Number\n");
			DPRINTF("4. Find the Student Details by First Name\n");
			DPRINTF("5. Find the Student Details by Course Id\n");
			DPRINTF("6. Find the Total Number of Students\n");
			DPRINTF("7. Delete the Students Details by Roll Number\n");
			DPRINTF("8. Update the Students Details by Roll Number\n");
			DPRINTF("9. Show all information\n");
			DPRINTF("10. To Exist\n");
			DPRINTF("--------------------------------------------------\n");
			DPRINTF("Enter your choice to perform the task: \n");
			scanf("%d",&task);
			DPRINTF("\n<---------------------->");
			switch(task)
			{
			case 1:
				add_student_manually(&buff_controller);
				break;
			case 2:
				add_student_file(&buff_controller);
				break;
			case 3:
				find_rl(&buff_controller);
				break;
			case 4:
				find_Fn(&buff_controller);
				break;
			case 5:
				find_C(&buff_controller);
				break;
			case 6:
				tot_s(&buff_controller);
				break;
			case 7:
				del_s(&buff_controller);
				break;
			case 8:
				up_s(&buff_controller);
				break;
			case 9:
				show_s(&buff_controller);
				break;
			case 10:
				DPRINTF("\nExist system");
				break;
			default:
				DPRINTF("\nThis task is not available");
				break;
			}
		}
		return 0;
}
