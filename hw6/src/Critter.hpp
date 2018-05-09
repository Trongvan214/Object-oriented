//Author: Trong Van
//Student ID: x454v285
//Programming Number: 6
//filename: Critter.hpp
//Description: declaration of the critter class


#ifndef __CRITTER__
#define __CRITTER__

#include <string>
#include "Grid.hpp"

class Critter {
public:
    virtual void move() = 0;
    virtual void breed() = 0;
    virtual char getRepresent() = 0;
    const int getX() const;
    const int getY() const;
    void setMoveYet(bool value);
    bool getMoveYet() const;
    std::string findNextAvailableSpot(std::string type, bool isBreeding);
    void moveThis(std::string direction);
    static void init();
    static void nextStep();
private:
    //private helper function
    int randomGenValue(int from, int to);
    int findForAnt(int direction);
    int findForDB(int direction);
    int findForBreed(int direction);
protected:
    //prevent from creating critter objects outside 
    Critter();
    Critter(unsigned int x, unsigned int y);
    // //location in x coord, y coord
    int _x,_y;
    bool moveYet;
    static Grid grid;
};
#endif