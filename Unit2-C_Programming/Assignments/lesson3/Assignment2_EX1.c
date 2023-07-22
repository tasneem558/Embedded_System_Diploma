/*
 ============================================================================
 Name        : Assignment2_EX1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	
		printf("Enter an integer you want to check:  \n ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&a);
		if(a%2==0)
		{
			printf("%d",a);
			printf(" is even \n");
		}
		else
		{
			printf("%d",a);
			printf(" is odd \n");
		}
	
}
