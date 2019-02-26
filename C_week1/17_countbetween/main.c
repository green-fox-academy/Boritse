#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_between_chars(char string[])
{
    char o='o';
    char *first=strchr(string, o);
    char *second=strrchr(string, o);
    return second-first-1;
}

int main()
{
    // Create a function which takes a string as a parameter and
    // returns the number of characters between two repeating characters
    // the repeating char can be a local variable in the function itself or
    // it can be passed to the function as parameter

    char *word = "bonbon";

    // the output should be: 6 (in this case the repeating char was 'g')
    printf("%d", count_between_chars(word));

    return 0;
}