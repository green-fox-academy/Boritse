#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create a program which asks for full name and age
// and stores it in a char array
// parse that array to first_name, last_name, age (use tokenizing)
// print out the the stored variables
// example:
//   printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);

int main ()
{
    char all_the_data_in_one_string[90];
    char first_name[40];
    char last_name[50];
    int age;
    puts("please enter you full name and age");
    gets(all_the_data_in_one_string);
    strcpy(first_name, strtok(all_the_data_in_one_string, " ,\n"));
    strcpy(last_name, strtok(NULL, " ,\n"));
    age = atoi(strtok(NULL, " ,"));
    printf("%s %s is %d years old.", first_name, last_name, age);

    return 0;
}