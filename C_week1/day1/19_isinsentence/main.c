#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isInSentence(char *word, char *sentence)
{
    if(strstr(sentence, word)){
        return 1;
    }else{
        return 0;
    }
}

int indexOfIt(char *word, char *sentence)
{
        char *index=strstr(sentence, word);
        if(index){
            return index-sentence;
        }
        return -1;
}

int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return 1 if the given sentence contains the given word
    // and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char *word = "doctor";
    char *sentence = "An apple a day keeps the doctor away.";

    // the output should be: 1
    (isInSentence(word, sentence)==1) ? printf("It's in the sentence, and it's at index %d", indexOfIt(word, sentence)) : printf("It is not present in the sentence");

    return 0;
}