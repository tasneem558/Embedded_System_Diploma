/*
 ============================================================================
 Name        : Assignment2_EX7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num , p=1;
	printf("Enter an integer: \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	if(num <0)
	{
		printf("Error!!! Factorial of negative number doesn't exist.");
	}
	else if(num ==0)
	{
		printf("Factorial = 1");
	}
	else

	{
		for(int i=num;i>=1;i--)
		{
			p *=i;
		}
		printf("Factorial = %d",p);
	}

}
