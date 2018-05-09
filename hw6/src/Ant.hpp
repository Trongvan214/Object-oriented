//Author: Trong Van
//Student ID: x454v285
//Programming Number: 6
//filename: Ant.hpp
//Description: declaration of the Ant class

#ifndef __ANT__
#define __ANT__

#include "Critter.hpp"

class Ant: public Critter{
public:
    Ant();
    Ant(int x, int y);
    void breed() override;
    void move() override;
    char getRepresent() override;
private:
    int stepsTillBreed;
    const char represent = 'O';
};

#endif 