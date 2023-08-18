/*
 ============================================================================
 Name        : EX1_less6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct  Sstudent
{
	char name[100];
	int roll_num;
	float marks;
};

int main()
{
	struct Sstudent S;

	printf("Enter information of students: \n\n");

	printf("Enter name: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s",&S.name);
	printf("Enter roll number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&S.roll_num);
	printf("Enter marks: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&S.marks);

	printf("\nDisplaying Information \n");

	printf("name: %s\nRoll: %d\nMarks: %0.2f",S.name,S.roll_num,S.marks);

}
