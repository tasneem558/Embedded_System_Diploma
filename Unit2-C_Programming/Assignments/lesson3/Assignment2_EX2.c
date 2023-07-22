/*
 ============================================================================
 Name        : Assignment2_EX2.c
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
	printf("Enter an alphabet: \n ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&ch);
	if((ch=='a')||(ch=='A')||(ch=='i')||(ch=='I')||(ch=='e')||(ch=='E')||(ch=='o')||(ch=='O')||(ch=='u')||(ch=='U'))
	{
		printf("%c",ch);
		printf(" is a vowel \n");
	}
	else
	{
		printf("%c",ch);
		printf(" is a consonant \n");
	}
	return EXIT_SUCCESS;
}
