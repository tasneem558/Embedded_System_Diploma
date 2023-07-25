/*
 ============================================================================
 Name        : EX3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int r,c;
		printf("Enter rows and column of matrix: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d %d",&r,&c);
		int a[r][c] ;
		int b[c][r];
		printf("Enter elemnts of matrix: \n");
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				printf("\nEnter elemnts a%d%d: ",i+1,j+1);
				fflush(stdin);
				fflush(stdout);
				scanf("%d",&a[i][j]);
			}
		}
		printf("Entered Matrix: \n");
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				printf("%d\t",a[i][j]);
			}
			printf("\r\n");
		}
		printf("Transpose of Matrix: \n");
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<r;j++)
			{
				b[i][j]=a[j][i];
			}
		}
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<r;j++)
			{
				printf("%d\t",b[i][j]);
			}
			printf("\r\n");
		}
}
