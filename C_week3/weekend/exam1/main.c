#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct{
  char single_char[9];
} single_char_t;

char binary_to_ascii(char* binary_char)
{
    int sum = 0;
    char c;
    int j = 7;
    for(int i=0; i<8; i++){
            sum += (binary_char[i]-'0')*(1 << j-i);
    }
    c = sum;
    return c;
}

int main()
{
    FILE * input_file = fopen("input.txt", "r");

    char single_char_collector[9];
    int char_count = 0;
    single_char_t* every_char = (single_char_t*)malloc(char_count*sizeof(single_char_t));

    if(input_file != NULL){
        while(!feof(input_file)){
            char_count++;
            every_char = realloc(every_char, char_count*sizeof(single_char_t));
            fscanf(input_file, "%s", single_char_collector);
            printf("%s\n", single_char_collector);
            strcpy(every_char[char_count-1].single_char, single_char_collector);
        }
    }else{
        printf("Could not open the file.\n");
    }

    fclose(input_file);

    char* message = (char*)calloc((char_count+1), sizeof(char));

    for(int i=0; i<char_count; i++){
        message[i] = binary_to_ascii(every_char[i].single_char);
        printf("%c", message[i]);
    }

    input_file = fopen("output.txt", "w");
    fprintf(input_file, message);
    fclose(input_file);

    free(message);
    free(every_char);

    return 0;
}