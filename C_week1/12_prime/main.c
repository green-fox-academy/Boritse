
#include <stdio.h>
#include <stdlib.h>

int isPrime(int input)
{
    int i=input-1;
    while(i>1){
        if(input%i==0){
            return 0;
        }
        i--;
    }
    return 1;
}

int main()
{
    int inputNumber;
    printf("i need a number, mate");
    scanf("%d", &inputNumber);

    if(isPrime(inputNumber)){
        printf("your number is prime");
    }else{
        printf("your number is not prime");
    }
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    return 0;
}