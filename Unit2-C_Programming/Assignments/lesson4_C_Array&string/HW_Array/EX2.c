/*
 ============================================================================
 Name        : EX2.c
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
	int n;
    printf("Enter the numbers of data: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d",&n);
    float arr[n] ,sum=0,avg;
    for(int i=0;i<n;i++)
    {
        printf("\nEnter number: ");
        fflush(stdin);
        fflush(stdout);
        scanf("%f",&arr[i]);
        sum+=arr[i];
    }
    avg=sum/n;
    printf("Average = %0.2f",avg);


}
