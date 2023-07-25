/*
 ============================================================================
 Name        : EX5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	 int n,x;
	   printf("Enter no of elemnts : \n");
	   fflush(stdin);
	   fflush(stdout);
	   scanf("%d",&n);
	   int arr[n];
	   for(int i=0;i<n;i++)
	   {
	     scanf("%d",&arr[i]);
	   }

	   printf("\nEnter the elemnt to be searched : ");
	   fflush(stdin);
	   fflush(stdout);
	   scanf("%d",&x);

	   for(int i=0;i<n;i++)
	   {
	     if(arr[i] ==x)
	     {
	        printf("Number found at the location = %d",i+1);
	        break;
	     }
	   }
}
