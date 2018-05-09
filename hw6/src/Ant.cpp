//Author: Trong Van
//Student ID: x454v285
//Programming Number: 6
//filename: Ant.cpp
//Description: implementation of the ant class member functions

#include <iostream>
#include <string>
#include "Ant.hpp"

//---------------------Default Constructor------------------//
Ant::Ant()
    :Critter()
    ,stepsTillBreed(3)
{}

//---------------------Constructor with x,y------------------//
Ant::Ant(int x, int y)
    :Critter(x,y)
    ,stepsTillBreed(3)
{}

//---------------------move function------------------//
void Ant::move(){
    //set this object moveYet base class to true so it can't move this turn anymore (step)
    moveYet = true;

    //return available spot to move if any (false for not breeding)
    std::string direction = Critter::findNextAvailableSpot("ant", false);

    //reduce steps till breed
    stepsTillBreed--;

    //move in given direction (top, right, bottom, left, none)
    Critter::moveThis(direction);
}

//---------------------breed function------------------//
void Ant::breed(){

    //if stepsTillBreed haven't reach 0 get out of function
    if(stepsTillBreed != 0){
        return;
    }

    //reset the steps until breed
    stepsTillBreed = 3;

    //find location for new Ant breeded (true for find for breeding)
    std::string direction = Critter::findNextAvailableSpot("ant", true);

    //put another ant into the grid;
    Critter* temp;
    if(direction == "top"){
        temp =  new Ant(_x,_y-1);
    }
    else if(direction == "right"){
        temp =  new Ant(_x+1,_y);
    }
    else if(direction == "bottom"){
        temp =  new Ant(_x,_y+1);
    }
    else if(direction == "left"){
        temp = new Ant(_x-1,_y);
    }
    //no breeding occurs because no spot available 
    else {
        return;
    }

    //inc breed total for ants
    Critter::grid.antsBreedInc();
    
    //put in grid
    Critter::grid.addToGrid(temp);
}

//---------------------breed function------------------//
char Ant::getRepresent(){
    return represent;
}
