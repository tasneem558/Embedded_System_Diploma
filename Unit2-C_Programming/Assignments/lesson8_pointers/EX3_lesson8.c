/*
 ============================================================================
 Name        : EX3_lesson8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char arr[100];
	char* ptr =arr;
	printf("Input a string : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s",ptr);

	printf("\nReverse of the string is : ");
	for(int i=(strlen(ptr))-1;i>=0;i--)
	{
		printf("%c",*(ptr+i));
	}
}
