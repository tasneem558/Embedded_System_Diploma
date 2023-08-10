#include<stdio.h>
#include<stdlib.h>

void take_array(int a[],int s);
int find_unique_number(int arr[], int size);

int main() 
{
    int size;
    printf("enter number of elemnts \n");
    scanf("%d",&size);

    int arr[size];
    printf("Enter elemnts of array\n");
    take_array(arr,size);

    printf("The unique number is: %d\n", find_unique_number(arr, size));
    return 0;
}

void take_array(int a[],int s)
{
    for (int i=0;i<s;i++)
    {
        scanf("%d",&a[i]);
    }
}


int find_unique_number(int arr[], int size) 
{
    int uniqueNumber = 0;

    for (int i = 0; i < size; i++) 
    {
        uniqueNumber ^= arr[i];
    }

    return uniqueNumber;
}