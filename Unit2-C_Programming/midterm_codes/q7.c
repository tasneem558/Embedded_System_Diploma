#include<stdio.h>
#include<stdlib.h>

int sum_numbers(int n1,int n2);

int main()
{
    printf("sum numbers from 1 to 100 is : %d" ,sum_numbers( 1,100) );
}

int sum_numbers(int n1,int n2)
{
   int sum =n1;
   if(n1<n2)
   {
     sum +=sum_numbers(n1+1, n2);
   }
   return sum;

}