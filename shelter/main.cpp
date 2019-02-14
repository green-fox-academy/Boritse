#include <iostream>
#include <ctime>
#include "AnimalShelter.h"
#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"

int main()
{
    srand(time(0));

    AnimalShelter animalShelter;

    Cat cat;
    Dog dog("Furkesz");
    Parrot parrot;

    animalShelter.rescue(cat);
    animalShelter.rescue(dog);
    animalShelter.rescue(parrot);

    std::cout << animalShelter.toString() << std::endl;
    // Budget: 50€, There are 3 animal(s) and 0 potential adopter(s)
    // Cat is not healthy (3€) and not adoptable
    // Furkesz is not healthy (1€) and not adoptable
    // Parrot is not healthy (7€) and not adoptable

    animalShelter.heal();

    std::cout << animalShelter.toString() << std::endl;
    // Budget: 47€, There are 3 animal(s) and 0 potential adopter(s)
    // Cat is healthy and adoptable
    // Furkesz is not healthy (1€) and not adoptable
    // Parrot is not healthy (7€) and not adoptable

    animalShelter.addAdopter("Kond");

    std::cout << animalShelter.toString() << std::endl;
    // Budget: 47€, There are 3 animal(s) and 1 potential adopter(s)
    // Cat is healthy and adoptable
    // Furkesz is not healthy (1€) and not adoptable
    // Parrot is not healthy (7€) and not adoptable

    animalShelter.findNewOwner();
    animalShelter.earnDonation(30);

    std::cout << animalShelter.toString() << std::endl;
    // Budget: 77€, There are 2 animal(s) and 0 potential adopter(s)
    // Furkesz is not healthy (1€) and not adoptable
    // Parrot is not healthy (7€) and not adoptable

    return 0;
}