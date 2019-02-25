#include<stdio.h>
#include <string.h>

int main()
{
    char classmates[]="Gyuri Snocc Adam";
    char *classmate = strtok(classmates, " ");
    while (classmate!=NULL){
        printf("Hello, %s!\n", classmate);
        classmate=strtok(NULL, " ");
    }

    return 0;
}