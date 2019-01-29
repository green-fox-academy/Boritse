//
// Created by Borbáls on 2019. 01. 29..
//

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class counter {
public:
    counter();

    void add();
    void ADD(int x);
    int get();
    void reset();

private:
    int count=0;
};


#endif //COUNTER_COUNTER_H
