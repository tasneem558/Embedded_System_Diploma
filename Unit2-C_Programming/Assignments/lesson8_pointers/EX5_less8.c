/*
 ============================================================================
 Name        : EX5_less8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Semployee
{
  char Name[20];
  int ID ;
};

int main(void)
{
  static struct Semployee emp1 ={"max",1003},emp2 ={"Alex",1002},emp3 ={"john",1004};
  struct Semployee (*arr[])={&emp1,&emp2,&emp3};
  struct Semployee (*(*ptr)[3])=&arr;
  printf("Exmployee Name : %s\nEmployee ID : %d",(**(*ptr+1)).Name,(**(*ptr+1)).ID);
}
