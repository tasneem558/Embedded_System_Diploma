#include <stdio.h>
#include <string.h>

void reverse_words(char* str);

int main() 
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    int length = strlen(str);
    if (str[length - 1] == '\n') 
    {
        str[length - 1] = '\0';
    }
    
    reverse_words(str);
    printf("Reversed string: %s\n", str);
    return 0;
}


void reverse_words(char* str) 
{
    int length = strlen(str);
    int start = 0;
    
    // Reverse the entire string
    for (int i = 0; i < length / 2; i++) 
    {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
    
    // Reverse each word
    for (int i = 0; i <= length; i++) 
    {
        if (str[i] == ' ' || str[i] == '\0') 
        {
            int end = i - 1;
            
            // Reverse the word
            while (start < end) 
            {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
            
            start = i + 1;
        }
    }
}