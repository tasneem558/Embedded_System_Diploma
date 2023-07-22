/*
 ============================================================================
 Name        : Assignment2_EX8.c
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
	char ch;
	float x,y,res;
	printf("Enter operator either + or - or * or divide: \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&ch);
	printf("Enter two operands: \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f",&x,&y);
	switch(ch)
	{
	case '+':
	{
		res=x+y;
		printf("%f %c %f",x,ch,y);
		printf(" = %f",res);
	}
	break;
	case '-':
	{
		res=x-y;
		printf("%f %c %f",x,ch,y);
		printf(" = %f",res);
	}
	break;
	case '*':
	{
		res=x*y;
		printf("%f %c %f",x,ch,y);
		printf(" = %f",res);
	}
	break;
	case '/':
	{
		res=x/y;
		printf("%f %c %f",x,ch,y);
		printf(" = %f",res);
	}
	break;

	}


}
