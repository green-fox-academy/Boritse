#include <stdio.h>
#include <stdlib.h>

int oddOrEven(int _input)
{
    return _input%2==0;
}

int main()
{
    int input;
    printf("give me a bloody number");
    scanf("%d", &input);

    if(oddOrEven(input)){
        printf("this is an even number");
    }else{
        printf("you number is odd");
    }

    return 0;
}