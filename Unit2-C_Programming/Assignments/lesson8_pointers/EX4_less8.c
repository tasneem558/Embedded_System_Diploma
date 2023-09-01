/*
 ============================================================================
 Name        : EX4_less8.c
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
	int size;
	printf("Input the number of elements to store in the array (max 15) :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&size);
	int arr[size];
	int *ptr =arr;
	printf("Input %d number of elements in the array :\n",size);
	for(int i=0;i<size;i++)
	{
		printf("element - %d :",i+1);
		fflush(stdin);
		fflush(stdout);
		scanf("%d",ptr+i);
	}

	printf("The elements of array in reverse order are :\n");
	for(int i=size-1;i>=0;i--)
	{
		printf("\nelement - %d : %d ",i+1,*(ptr+i));
	}

}
