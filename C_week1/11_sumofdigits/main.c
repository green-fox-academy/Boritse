#include <stdio.h>
#include <stdlib.h>

int sumDigitsEqual(int first, int second)
{
    int sum1=0;
    int sum2=0;
    while(first>0 && second>0){
        sum1+=first%10;
        first/=10;
        sum2+=second%10;
        second/=10;
    }
    return sum1==sum2;
}

int main()
{
    int firstInput;
    int secondInput;
    printf("please give me two multidigit integers");
    scanf("%d %d", &firstInput, &secondInput);

    if(sumDigitsEqual(firstInput, secondInput)){
        printf("the sum of the digits of your numbers are equal");
    }else{
        printf("the sum of the digits of your numbers are not equal");
    }
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0

    return 0;
}