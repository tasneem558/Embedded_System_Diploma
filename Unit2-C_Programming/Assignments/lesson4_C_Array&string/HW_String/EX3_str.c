/*
 ============================================================================
 Name        : EX3_str.c
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
  char str[1000];
  printf("Enter the string: ");
  fflush(stdin);
  fflush(stdout);
  gets(str);

  printf("\nReverse string is : ");
  for(int i=strlen(str)-1;i>=0;i--)
  {
    printf("%c", str[i]);
  }

}

