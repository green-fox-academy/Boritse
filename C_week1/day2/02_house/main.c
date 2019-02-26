#include <stdio.h>

typedef struct {
  char address[100];
  int price_euro;
  int rooms;
  int square_meters;
} house_t;

int worth_buying(house_t *some_house);

void worth_buying_array(house_t houses[], int length)
{
    for(int i=0; i<length; i++){
        if(worth_buying(&houses[i])){
            printf("the %d. house is worth buying!!\n", i+1);
        }
    }
}

int main()
{
    house_t my_house;
    my_house.price_euro=85000;
    my_house.square_meters=120;
    house_t gyuris_house;
    gyuris_house.price_euro=6500;
    gyuris_house.square_meters=110;
    house_t snoccs_house;
    snoccs_house.square_meters=130;
    snoccs_house.price_euro=70000;

    house_t houses[3];
    houses[0]=my_house;
    houses[1]=gyuris_house;
    houses[2]=snoccs_house;

    (worth_buying(&snoccs_house)) ? printf("oh my goodness, buy this house NOW\n") : printf("DO NOT BUY\n");
    (worth_buying(&my_house)) ? printf("oh my goodness, buy this house NOW\n") : printf("DO NOT BUY\n");
    (worth_buying(&gyuris_house)) ? printf("oh my goodness, buy this house NOW\n") : printf("DO NOT BUY\n");

    worth_buying_array(houses, 3);

    return 0;
}

int worth_buying(house_t *some_house)
{
    return some_house->price_euro < some_house->square_meters*400;
}

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/
