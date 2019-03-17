#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int whereIsIt(char *longishString, char singleChar)
{
    char *fuck=strchr(longishString, singleChar);
    if(!fuck){
        return -1;
    }else{
        return fuck-longishString;
    }
}

int main()
{
    char string[10];
    char character;

    printf("give me a longish word and a character please");
    scanf("%s %c", string, &character);

    printf("the index of the %c is %d", character, whereIsIt(string, character));
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    return 0;
}