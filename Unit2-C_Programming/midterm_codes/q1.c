//q1: function to take a number and sum all digits 

#include<stdio.h>
#include<stdlib.h>

int sum_digits(int n);

int main()
{
  int num;
  printf("Enter the number: ");
  scanf("%d",&num);
  printf("Sum of number digits = %d",sum_digits(num));
}

int sum_digits(int n)
{
  int sum=0;
  while((n%10)!=0)
  {
    sum +=n%10;
    n/=10;
  }
  return sum;
}