#include <stdio.h>
#include <stdlib.h>

int oldEnough(int _age)
{
    return _age >= 18;
}

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    int ageOfUser;
    printf("how old are you");
    scanf("%d", &ageOfUser);

    if(oldEnough(ageOfUser)){
        printf("User is old enough to buy alcohol");
    }else{
        printf("RED ALERT, User is not old enough to purchase!!");
    }

    return 0;
}