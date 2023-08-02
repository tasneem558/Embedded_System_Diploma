/*
 ============================================================================
 Name        : EX2_less5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int factorial_num(int n);
int main()
{
   int num;
   printf("Enter an positive integer: ");
   fflush(stdin);
   fflush(stdout);
   scanf("%d",&num);
   printf("Factorial of %d = %d",num,factorial_num(num));
}

int factorial_num(int n)
{
   if(n==0 || n==1)
   {
      return 1;
   }
   else
   {
     return n*factorial_num(n-1);
   }
}

