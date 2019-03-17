#include <stdio.h>

int main()
{
    double a, b, c;
    printf("give me three numbers, hit enters inbetween");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    double area=2*a*b+2*a*c+2*c*b;
    double volume=a*b*c;

    printf("Surface Area: %lf\nVolume: %lf", area, volume);
    return 0;
}

// Write a program that stores 3 sides of a cuboid as variables (doubles)
// You should get these variables via console input
// The program should write the surface area and volume of the cuboid like:
//
// Surface Area: 600
// Volume: 1000