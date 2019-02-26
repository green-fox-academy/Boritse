#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nameLength(char first[], char last[])
{
    return strlen(first)+strlen(last);
}

int main()
{
    char firstname[100];
    char lastname[100];
    printf("whats your name");
    scanf("%s %s", firstname, lastname);

    printf("%d", nameLength(firstname, lastname));
    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    return 0;
}