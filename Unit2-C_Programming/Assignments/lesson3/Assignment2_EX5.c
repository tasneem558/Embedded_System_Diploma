/*
 ============================================================================
 Name        : Assignment2_EX5.c
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
	  if(((ch>=65) && (ch<=90)) || ((ch>=97) && (ch<=122)))
	  {
		printf("%c",ch);
	    printf(" is an alphapet");
	  }
	  else
	  {
		printf("%c",ch);
		printf(" is not an alphapet");
	  }


}
