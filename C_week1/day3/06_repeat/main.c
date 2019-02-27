#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

char* string_multiplier(char* string, int multiplier)
{
    char* multiplied_string=malloc(multiplier*strlen(string)+1);
    strcpy(multiplied_string,string);
    for(int i=1; i<multiplier; i++){
        strcat(multiplied_string,string);
    }
    return multiplied_string;
}

int main()
{
    char bebino[]="Michele";
    char* bebino_the_bestest=string_multiplier(bebino, 4);
    printf("%s", bebino_the_bestest);
    free(bebino_the_bestest);
    return 0;
}