//
// Created by Borbáls on 2019. 02. 05..
//

#ifndef AIRCRAFTCARRIER_AIRCRAFTS_H
#define AIRCRAFTCARRIER_AIRCRAFTS_H


enum AircraftType{
    F16,
    F35
};

std::string getType(AircraftType _type);

class Aircrafts{
public:
    Aircrafts(AircraftType _type);
    int fight();
    int refill(int fill);
    std::string getType();
    std::string getStatus();
    bool isPriority();
    int getNeededAmmo();
private:
    int maxAmmo;
    int currentAmmo;
    int baseDamage;
    int allDamage;
    bool priority;
    AircraftType type;
};


#endif //AIRCRAFTCARRIER_AIRCRAFTS_H
