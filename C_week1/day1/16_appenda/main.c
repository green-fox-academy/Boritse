#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* appendA(char *string)
{
    strcat(string, "a");
    return string;
}

char* appendChar(char *string, char c) {
    int length=strlen(string);
    string[length]=c;
    string[length+1]='\0';
    return string;
}

int main()
{
    char inputString[20] = "aaaaaaaaaaaaaaaaaaa";
    printf("provide me with a string pls");
    scanf("%s", inputString);
    printf("your new string is: %s", appendChar(inputString, 'c'));

    return 0;
}
