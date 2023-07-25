/*
 ============================================================================
 Name        : EX4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n,x,loc;
	printf("Enter no of elemnts : \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n Enter the elemnt to be inserted : \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&x);

	printf("Enter the location : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&loc);

	for(int i=n;i>=loc;i--)
	{
		arr[i]=arr[i-1];
	}
	n++;
	arr[loc-1]=x;

	for(int i=0;i<n;i++)
	{
		printf(" %d ",arr[i]);
	}
}
