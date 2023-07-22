/*
 ============================================================================
 Name        : Assignment1_EX6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a,b,temp;
	printf("Enter value of a:  \n ");
    scanf("%f",&a);
    printf("Enter value of b:  \n ");
    scanf("%f",&b);
	temp=a;
	a=b;
	b=temp;
	printf("After swapping, value of a: %f \nAfter swapping, value of b: %f",a,b);
	return EXIT_SUCCESS;
}
