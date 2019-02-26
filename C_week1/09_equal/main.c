#include <stdio.h>
#include <stdlib.h>

int areEqual(int first, int second)
{
    return first==second;
}

int main()
{
    int a, b;
    printf("please enter two numbers separated by a space");
    scanf("%d %d", &a, &b);

    if(areEqual(a, b)){
        printf("congrats, your numbers are equal");
    }else{
        printf("your numbers are faaaar from being the same");
    }

    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    return 0;
}