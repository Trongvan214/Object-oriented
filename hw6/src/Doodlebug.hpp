//Author: Trong Van
//Student ID: x454v285
//Programming Number: 6
//filename: Doodlebug.hpp
//Description: declaration of the doodlebug class 

#ifndef __DOODLEBUG__
#define __DOODLEBUG__

#include "Critter.hpp"

class Doodlebug:public Critter {
public:
    Doodlebug();
    Doodlebug(int x, int y);
    void move() override;
    void breed() override;
    char getRepresent() override;
private:
    int stepsTillBreed, stepsTillStarved;
    const char represent = 'X';
};

#endif