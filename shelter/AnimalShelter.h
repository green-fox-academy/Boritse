//
// Created by Borbáls on 2019. 02. 09..
//

#ifndef SHELTER_ANIMALSHELTER_H
#define SHELTER_ANIMALSHELTER_H

#include <vector>
#include "Animal.h"

class AnimalShelter : public Animal {
public:
    AnimalShelter();
    int rescue(Animal &newAnimal);
    bool heal();
    void addAdopter(std::string adopter);
    void findNewOwner();
    int earnDonation(int donation);
    std::string toString();
private:
    int budget;
    std::vector<Animal*> animals;
    std::vector<std::string> adopters;
};


#endif //SHELTER_ANIMALSHELTER_H

