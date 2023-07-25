/*
 ============================================================================
 Name        : EX1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a[2][2];
	float b[2][2];
	float s[2][2];

	printf("Enter the elements of 1st matrix \n");
	for (int i=0; i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("Enter a%d%d: \n",i+1,j+1);
			fflush(stdout);
			fflush(stdin);
			scanf("%f",&a[i][j]);
			printf(";");
		}
	}

	printf("Enter the elements of 2nd matrix \n");

	for (int i=0; i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("Enter a%d%d: ",i+1,j+1);
			fflush(stdout);
			fflush(stdin);
			scanf("%f",&b[i][j]);
			printf(";\n");
		}

	}
	printf("Sum Of Matrix: \n");
	for (int i=0; i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			s[i][j]=a[i][j] + b[i][j];
		}

	}

	for (int i=0; i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("%.1f\t",s[i][j]);
		}
		printf("\r\n");

	}



}
