#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSubString(char *first, char *second)
{
    if(strlen(first)<=strlen(second)){
        return -1;
    }else if(strstr(first, second)){
        return 1;
        }else{
        return 0;
    }
}

int main()
{
    char firstString[20];
    char secondString[20];

    printf("please enter two words");
    scanf("%s %s", firstString, secondString);

    printf("%d", isSubString(firstString, secondString));
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the shorter string is a substring of the longer one and
    // returns 0 otherwise
    // If the two strings has the same lenght than the function should return -1

    return 0;
}