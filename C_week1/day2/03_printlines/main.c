#include <stdio.h>
#include <string.h>

int lineCounter(char *filename)
{
    FILE *working_file = fopen(filename, "r");
    char line[100];
    int line_counter=0;
    while (fgets(line, sizeof(line), working_file)){
        puts(line);
        line_counter++;
    }
    fclose(working_file);
    return line_counter;
}

int main ()
{
    FILE *new_file = fopen("gyakorolokkk.txt", "w");
    fprintf(new_file, "en annyira szeretem a strandot\nmert ott annyira szep es jo\nannyi vicceset latok hallok\nes meg bambi is kaphato\n");
    fclose(new_file);

    char file[]="gyakorolokkk.txt";
    printf("your file containes: %d lines", lineCounter(file));
    new_file = fopen("gyakorolokkk.txt", "r");
    char line[100];
    while (fgets(line, sizeof(line), new_file)){
        puts(line);
    }

    fclose(new_file);

    return 0;
}