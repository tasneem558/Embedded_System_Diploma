/*
 ============================================================================
 Name        : EX1_less8.c
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
	 int m =29;
	  printf("Address of m : 0x%x\n Value of m : %d\n\n",&m,m);
	  int* ab=&m;
	  printf("Address of pointer ab : 0x%x\nContent of pointer ab : %d\n\n",ab,*ab);
	  m=34;
	  printf("Address of pointer ab : 0x%x\nContent of pointer ab : %d\n\n",ab,*ab);
	  *ab=7;
	  printf("Address of m : 0x%x\nValue of m : %d",&m,m);
}
