//
// Created by Borbáls on 2019. 02. 06..
//
#include <iostream>
#include "Bird.h"

Bird::Bird() : Flyable(), Animals() {
}
void Bird::fly(){
    std::cout << "Im a flying bird, surprise!" << std::endl;
}
void Bird::takeoff(){
    std::cout << "Im just trying to take off from the land, dunno if Im gonna succeed" << std::endl;
}
void Bird::land(){
    std::cout << "Im laaaandiiiing" << std::endl;
}
