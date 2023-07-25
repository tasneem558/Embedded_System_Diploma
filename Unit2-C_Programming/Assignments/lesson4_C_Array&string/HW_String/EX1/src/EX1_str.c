/*
 ============================================================================
 Name        : EX1_str.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	char str[1000];
	char ch;
	int freq=0;
	printf("Enter a string: ");
	fflush(stdin);
	fflush(stdout);
	gets(str);
	printf("Enter a character to find frequency \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&ch);
	for(int i=0;i<strlen(str);i++)
	{
		if(ch==str[i])
		{
			freq++;
		}
	}
	printf("Frequency of %c = %d", ch, freq);
}
