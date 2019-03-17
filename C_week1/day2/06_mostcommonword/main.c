#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <ctype.h>

typedef struct{
  char word[20];
  int frequency;
} words_t;

int words_t_size(words_t *words){
    int counter=0;
    for(int i=0; i<300; i++){
        if(words[i].frequency){
            counter++;
        }else{
            return counter;
        }
    }
    return counter;
}

void words_t_fill_frequency(words_t *words){
    for(int i=0; i<300; i++){
        words[i].frequency=0;
    }
}

int most_common_word_index(words_t *words){
    int tracker=0;
    int index=0;
    for(int i=0; i<words_t_size(words); i++){
        if(words[i].frequency>tracker){
            tracker=words[i].frequency;
            index=i;
        }
    }
    return index;
}

int main()
{
    FILE * working_file = fopen("file.txt", "r");

    fseek(working_file, 0, SEEK_END);
    long length = ftell(working_file);
    fseek(working_file, 0, SEEK_SET);


    char whole_file_in_string[length+1];

    fread(whole_file_in_string, 1, (size_t)length, working_file);

    fclose(working_file);

    words_t all_words[300];
    int word_counter=1;
    words_t_fill_frequency(all_words);
    char *single_word = strtok(whole_file_in_string, " ,.;:?!-");
    strcpy(all_words[0].word, single_word);
    all_words[0].frequency++;
    while(single_word != NULL){
        single_word = strtok(NULL, " ,.;:?!-");
        for(int i=0; i<words_t_size(all_words)+1; i++){
            if(0==strcmp(single_word, all_words[i].word)){
                all_words[i].frequency++;
                printf("%s %d\n%d\n", all_words[i].word, all_words[i].frequency, word_counter);
                break;
            }else if(i==words_t_size(all_words)){
                strcpy(all_words[i].word, single_word);
                all_words[i].frequency++;
                word_counter++;
                break;
            }
        }
    }

    printf("the most common word is %s, it is present in the text %d times", all_words[most_common_word_index(all_words)].word, all_words[most_common_word_index(all_words)].frequency);

    return 0;
}
