#include <stdio.h>

int countMaxOnes_BetweenZeros(int arr[], int size);

int main() {
    int arr[] = {0,1,1,1,0};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxOnes = countMaxOnes_BetweenZeros(arr, size);

    printf("The maximum number of ones between two zeros is: %d\n", maxOnes);

    return 0;
}

int countMaxOnes_BetweenZeros(int arr[], int size) 
{
    int maxOnes = 0;
    int onesCount = 0;
    int zerosCount = 0;

    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == 1) 
        {
            onesCount++;
            if (zerosCount > 0 && onesCount > maxOnes) 
            {
                maxOnes = onesCount;
            }
        } else if (arr[i] == 0) 
        {
            onesCount = 0;
            zerosCount++;
        }
    }

    return maxOnes;
}