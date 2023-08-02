/*
 ============================================================================
 Name        : EX1_less5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void get_prime_num(int n1,int n2);
int main()
{
	int x,y;
	printf("Enter two numbers(intervals): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&x,&y);
	printf("Prime numbers between %d and %d are: ",x,y);
	get_prime_num(x,y);
}

void get_prime_num(int n1,int n2)
{
	int prime = 1;
	if(n2>n1)
	{
		for(int i=n1+1;i<n2;i++)
		{
			for(int j=2;j< i/2 ;j++)
			{
				if(i%j ==0)
				{
					prime=0;
				}
			}
			if(prime)
			{
				printf("%d ",i);
			}
		}
	}
	else
	{
		return;
	}
	get_prime_num(n1+1,n2);

}
