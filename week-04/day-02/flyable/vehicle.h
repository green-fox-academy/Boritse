//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef FLYABLE_VEHICLE_H
#define FLYABLE_VEHICLE_H


class Vehicle {
public:
    Vehicle();
    virtual void move()=0;
protected:
    int weight;
    int speed;
    int amountOfPeopleCarried;
};


#endif //FLYABLE_VEHICLE_H
