#include<stdio.h>
#include<stdlib.h>

int count_ones(int n);

int main()
{
    int num;
    printf("Enter number: ");
    scanf("%d",&num);
    printf("Number of ones in the binary number: %d\n",count_ones(num) );
}

int count_ones(int n)
{
    int count = 0;

    while (n > 0) 
    {
        if (n % 2 == 1) 
        {
            count++;
        }
        n = n / 2;
    }

    return count;
}
