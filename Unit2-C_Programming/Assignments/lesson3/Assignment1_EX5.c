/*
 ============================================================================
 Name        : Assignment1_EX5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char ch;
	printf("Enter a character: \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&ch);
	printf("ASCII value of %c",ch);
    printf(" = %d",(int)ch);
	return EXIT_SUCCESS;
}
