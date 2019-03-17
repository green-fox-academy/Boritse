
#include <stdio.h>
#include <stdlib.h>
#include "separate.h"

double area(double _radius)
{
    double area=_radius*_radius*PI;
    return area;
}

int main()
{
    double radius=4;
    printf("%.4lf", area(radius));

    return 0;
}