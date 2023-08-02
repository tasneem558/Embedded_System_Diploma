/*
 ============================================================================
 Name        : EX4_less5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int power_func(int n1,int n2);

int main()
{
	int base_num ,power_num;
	printf("Enter base number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&base_num);
	printf("Enter power number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&power_num);
	printf("%d ^ %d = %d",base_num,power_num,power_func(base_num,power_num));
}

int power_func(int n1,int n2)
{
	int power=n1;
	if(n2 >0)
	{
		return power*power_func(n1,n2-1);
	}
	else
	{
		return 1;
	}
}
