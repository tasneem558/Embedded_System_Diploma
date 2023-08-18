/*
 ============================================================================
 Name        : EX4_less6.c
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
	int marks;
}s[10];

void EnteringOfInformation(struct Sstudent s[10]);
void PrintingOfInformation(struct Sstudent s[10]);

int main()
{
	printf("Enter information of students: \n\n");
	EnteringOfInformation(s);

	printf("\nDisplaying Information \n\n");
	PrintingOfInformation(s);
}

void EnteringOfInformation(struct Sstudent s[10])
{

	for(int i=0;i<10;i++)
	{
		printf("For roll number %d\n",i+1);

		printf("Enter name: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%s",&s[i].name);

		printf("Enter marks: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&s[i].marks);
	}
}


void PrintingOfInformation(struct Sstudent s[10])
{

	for(int i=0;i<10;i++)
	{
		printf("Information for roll number %d\n",i+1);
		printf("Name: %s\n",s[i].name);
		printf("marks: %d\n",s[i].marks);
	}
}
