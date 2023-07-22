/*
 ============================================================================
 Name        : Assignment1_EX7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float a ,b;
	printf("Enter value of a:  \n ");
	scanf("%f",&a);
	printf("Enter value of b:  \n ");
	scanf("%f",&b);
	a= (int)a^ (int)b;
	b=(int)b^(int)a;
	a=(int)a^(int)b;
	printf("After swapping, value of a: %f \nAfter swapping, value of b: %f",a,b);

}
