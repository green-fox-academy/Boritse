#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isSame(char *first, char *second)
{
    if(strlen(first)!=strlen(second)){
        return 1;
    }else {
        int i = 0;
        while (first[i]) {
            tolower(first[i]);
            tolower(second[i]);
            i++;
        }
        strcmp(first, second);
    }
}

main()
{
    char firstString[30];
    char secondString[30];
    printf("please enter two words");
    scanf("%s %s", firstString, secondString);

    printf("your strings are %sthe same", (isSame(firstString, secondString)) ? "not " : "");
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    return 0;
}