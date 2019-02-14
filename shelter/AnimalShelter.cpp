//
// Created by Borbáls on 2019. 02. 09..
//

#include "AnimalShelter.h"

AnimalShelter::AnimalShelter() {
    budget=50;
}
int AnimalShelter::rescue(Animal &newAnimal){
    animals.push_back(&newAnimal);
    return animals.size();
}
bool AnimalShelter::heal(){
    for(int i=0; i<animals.size(); i++){
        if((!animals[i]->isAdoptable()) && (animals[i]->getHealCost()<budget))
            animals[i]->heal();
        return 1;
    }
    return 0;
}
void AnimalShelter::addAdopter(std::string adopter){
    adopters.push_back(adopter);
}
void AnimalShelter::findNewOwner(){
    if(adopters.size()>0) {
        for (int i=0; i<animals.size(); i++){
            if(animals[i]->isAdoptable()){
                animals.erase(animals.begin()+i);
                adopters.erase(adopters.begin()+(rand()%adopters.size())+1);
                break;
            }
        }
    }
}
int AnimalShelter::earnDonation(int donation){
    budget+=donation;
    return budget;
}
std::string AnimalShelter::toString(){
    return "Budget: "+std::to_string(budget)+"euro, there are "+std::to_string(animals.size())+" animals and "+std::to_string(adopters.size())+" potential adopeters.";
}

// -  has a method named `findNewOwner()` this method pairs a random name with a random adoptable Animal if it is possible and remove both of them from the lists
// -  has a method named `earnDonation(int)` this method takes a whole number as parameter and increase the shelter's budget by the parameter's value and returns the current budget
// -  has a method named `toString()` that represents the shelter in the following format:
// Budget: <budget>€, There are <animals.size()> animal(s) and <potentionalAdopters.size()> potential adopter(s)
// <animal1 name> is not healthy (<heal cost>€), and not adoptable
// <animal2 name> is healthy, and adoptable
