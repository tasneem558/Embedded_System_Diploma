/*
 ============================================================================
 Name        : EX2_str.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char str[1000];
	int len=0;

	printf("Enter a string: ");
	fflush(stdin);
	fflush(stdout);
	gets(str);

	for(int i=0;str[i]!='\0';i++)
	{

		len++;

	}
	printf("Length of string: %d", len);
}
