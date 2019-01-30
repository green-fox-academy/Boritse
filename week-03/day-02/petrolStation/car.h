//
// Created by Borbáls on 2019. 01. 30..
//

#ifndef PETROLSTATION_CAR_H
#define PETROLSTATION_CAR_H


class car {
public:
    car(int _gasAmount, int _capacity);
    bool isFull();
    void fill();
    int getGasAmount();

private:
    int gasAmount;
    int capacity;
};


#endif //PETROLSTATION_CAR_H
