/*
 ============================================================================
 Name        : EX2_less6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct  SDistance
{
  int feet;
  float inch;
};

int main()
{
  struct SDistance d1 ,d2,sum;

  printf("Enter information for 1st distance: \n\n");

  printf("Enter feet: ");
  fflush(stdin);
  fflush(stdout);
  scanf("%d",&d1.feet);
  printf("Enter inch: ");
  fflush(stdin);
  fflush(stdout);
  scanf("%f",&d1.inch);

  printf("Enter information for 2nd distance: \n\n");

  printf("Enter feet: ");
  fflush(stdin);
  fflush(stdout);
  scanf("%d",&d2.feet);
  printf("Enter inch: ");
  fflush(stdin);
  fflush(stdout);
  scanf("%f",&d2.inch);

  sum.feet =d1.feet+d2.feet;
  sum.inch=d1.inch+d2.inch;

  if(sum.inch>12.0)
  {
    sum.inch =sum.inch-12.0;
    ++sum.feet;
  }
  printf("\nSum of distances=%d\'-%0.1f\"",sum.feet,sum.inch);

}
