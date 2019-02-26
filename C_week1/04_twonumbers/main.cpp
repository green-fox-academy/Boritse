#include<stdio.h>

int main()
{
    int a=22;
    int b=13;

    int sum=a+b;
    int sub=a-b;
    int multi=a*b;
    float div=(float)a/(float)b;
    int rem=a%b;

    printf("%s=%d\n%s=%d\n%s=%d\n%s=%.2f\n%s=%d", "sum", sum, "sub", sub, "multi", multi, "div", div, "rem", rem);

    return 0;
}