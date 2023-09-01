/*
 ============================================================================
 Name        : EX2_less8.c
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
	char arr[26];
	char ch=65;
	char* ptr =arr;
	for(int i=0;i<26;i++,ch++)
	{
		*(ptr+i)=ch;
	}
	printf("The Alphabets are :\n");
	for(int i=0;i<26;i++)
	{
		printf("%c  ",*ptr++);
	}
}
