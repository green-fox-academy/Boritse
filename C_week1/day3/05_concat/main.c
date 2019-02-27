#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char* concatenate(char* first_word, char* second_word)
{
    char *result = malloc(strlen(first_word) + strlen(second_word) + 1);
    for(int i=0; i<strlen(first_word); i++){
        result[i]=first_word[i];
    }
    for(int i=0; i<strlen(second_word); i++){
        result[(strlen(first_word))+i]=second_word[i];
    }
    return result;
}

int main()
{
    char first_input[20];
    char second_input[20];

    printf("please enter two words, may them be long or short, you decide");
    scanf("%s %s", first_input, second_input);

    char* concatenated_string = concatenate(first_input,second_input);

    printf("%s", concatenated_string);

    free(concatenated_string);

    return 0;
}