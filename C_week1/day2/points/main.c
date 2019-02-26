#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct{
  float x;
  float y;
} point_t;

point_t create_point(float _x, float _y){
    point_t createdpoint;
    createdpoint.x=_x;
    createdpoint.y=_y;
    return createdpoint;
}

float distance(point_t first, point_t second){
    float xthing = (first.x)-(second.x);
    float ything = (first.y)-(second.y);
    float distance = sqrt(xthing*xthing + ything*ything);
    return distance;
}

int main()
{
    point_t bigpoint;
    bigpoint = create_point(3, 12);
    point_t smallpoint;
    smallpoint = create_point(7.4, 11.2);

    printf("the distance between your points is: %.2f", distance(bigpoint, smallpoint));

    return 0;
}