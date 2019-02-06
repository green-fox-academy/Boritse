//
// Created by Borbáls on 2019. 02. 06..
//

#ifndef FLYABLE_FLYABLE_H
#define FLYABLE_FLYABLE_H


class Flyable {
public:
    Flyable();
    virtual void land()=0;
    virtual void fly()=0;
    virtual void takeoff()=0;
private:

};


#endif //FLYABLE_FLYABLE_H
