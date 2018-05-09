//Author: Trong Van
//Student ID: x454v285
//Programming Number: 6
//filename: main.cpp
//Description: the main program to control the simulation 

#include <string>
#include <iostream>
#include "Critter.hpp"

int main(){
    Critter::init();
    std::cout << "Press 'Enter' to start" << std::endl;
    while(std::cin.get() == '\n'){
        Critter::nextStep();
        std::cout << "Press 'Enter' for next step" << std::endl;
    }
    return 0;
}
