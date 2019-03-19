#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct{
  int count;
  char single_word[15];
}words_count_t;

int main()
{
    FILE * input_file = fopen("file.txt", "r");

    int already_in_array_bool = 0;
    char *word_collector;
    char line_collector[150];
    int word_count = 0;
    words_count_t *every_word = (words_count_t*)malloc(word_count*sizeof(words_count_t));

    if(input_file != NULL){
        while(!feof(input_file)){
            fgets(line_collector, 150, input_file);
            word_collector = strtok(line_collector, " .,:?;!");
            while(word_collector != NULL){
                for(int i=0; i<word_count; i++) {
                    if (strcmp(word_collector, every_word[i].single_word) == 0) {
                        every_word[i].count++;
                        already_in_array_bool = 1;
                        printf("%s %d\n", every_word[i].single_word, every_word[i].count);
                    }
                }
                if(!already_in_array_bool){
                        word_count++;
                        every_word = realloc(every_word, word_count*sizeof(words_count_t));
                        every_word[word_count-1].count = 0;
                        strncpy(every_word[word_count-1].single_word, word_collector, sizeof(every_word[word_count-1].single_word));
                }
                word_collector = strtok(NULL, " .,:?;!\n\t\r");
                already_in_array_bool = 0;
            }
        }
    }

    fclose(input_file);

    int most_common_word_count = 0;
    int most_common_word_index = 0;
    for(int i= 0; i<word_count; i++){
        if(every_word[i].count > most_common_word_count){
            most_common_word_count = every_word[i].count;
            most_common_word_index = i;
        }
    }

    printf("the most common word in the file is: %s\n", every_word[most_common_word_index].single_word);
    free(every_word);

    return 0;
}