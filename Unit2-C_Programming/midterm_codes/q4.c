#include<stdio.h>
#include<stdlib.h>
void revers_digits(int n);
int main()
{
    int num;
    printf("Enter number: ");
    scanf("%d",&num);
    revers_digits(num);

}
void revers_digits(int n)
{
    for(int i=n;i>0;i/=10)
    {
        printf("%d",i%10);
    }
}
