/*
 ============================================================================
 Name        : Assignment1_EX3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a,b,s;
	printf("Enter two numbers: \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&a,&b);
	s=a+b;
	printf("Sum: %d",s);
	return EXIT_SUCCESS;
}
