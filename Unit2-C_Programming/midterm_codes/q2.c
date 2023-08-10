#include<stdio.h>
#include<stdlib.h>

float square_root(int n);

int main()
{
  int num;
  printf("Enter the number: ");
  scanf("%d",&num);
  printf("Square of number = %0.3f",square_root(num));
}

float square_root(int n)
{
  if (n==0)
    {
        return 0;
    }

    float x = n;
    float y = 0;
    while ((x - y) > 0) 
    {
        x = (x + y) / 2;
        y = n / x;
    }

    return x;
}
