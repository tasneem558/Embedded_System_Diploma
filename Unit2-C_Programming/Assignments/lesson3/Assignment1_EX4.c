/*
 ============================================================================
 Name        : Assignment1_EX4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a,b,p;
	printf("Enter two numbers: \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f",&a,&b);
	p=a*b;
	printf("Product: %f",p);
	return EXIT_SUCCESS;
}
