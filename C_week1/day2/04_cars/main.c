#include <string.h>
#include <stdio.h>

typedef enum{
  manual, automatic, CVT, semi_automatic, dual_clutch
} transmission_t;

typedef struct{
  char name[256];
  float price_in_euros;
  int manufactured_in;
  transmission_t transmission;
} car_t;

int get_older_cars_than(car_t *cars, int length, int age);
int get_transmission_count(car_t *cars, int length, transmission_t trnsm);

int main()
{
    car_t snocc;
    snocc.transmission=automatic;
    snocc.manufactured_in=2012;
    car_t gyuri;
    gyuri.transmission=semi_automatic;
    gyuri.manufactured_in=2014;
    car_t adam;
    adam.transmission=manual;
    adam.manufactured_in=1997;
    car_t boro;
    boro.transmission=automatic;
    boro.manufactured_in=2017;

    car_t cars[4];
    cars[0]=gyuri;
    cars[1]=adam;
    cars[2]=boro;
    cars[3]=snocc;

    int agelimit=2000;
    printf("%d cars are older than %d\n", get_older_cars_than(cars, 4, agelimit), agelimit);

    printf("%d cars have the right transmission\n", get_transmission_count(cars, 4, automatic));

    return 0;
}

int get_older_cars_than(car_t *cars, int length, int age)
{
    int counter=0;
    for(int i=0; i<length; i++){
        if(cars[i].manufactured_in<age){
            printf("the %d. car is older than %d\n", i+1, age);
            counter++;
        }
    }
    return counter;
}

int get_transmission_count(car_t *cars, int length, transmission_t trnsm)
{
    int counter=0;
    for(int i=0; i<length; i++){
        if(cars[i].transmission==trnsm){
            counter++;
            printf("the %d. car has the right transmission\n", i+1);
        }
    }
    return counter;
}