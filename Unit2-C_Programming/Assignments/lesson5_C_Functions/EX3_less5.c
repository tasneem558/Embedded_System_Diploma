/*
 ============================================================================
 Name        : EX3_less5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void revers_text(char s[],int n);
int main()
{
	char sent[100];
	printf("Enter a sentence: ");
	fflush(stdin);
	fflush(stdout);
	gets(sent);
	int x =strlen(sent);
	revers_text(sent,x);
}

void revers_text(char s[],int n)
{
	if(n <0)
	{
		return;
	}
	else
	{

		printf("%c",s[n]);
	}

	revers_text( s,n-1);
}



