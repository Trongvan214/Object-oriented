//Author: Trong Van
//Student ID: x454v285
//Programming Number: 6
//filename: Doodblebug.cpp
//Description: implementation of the doodlebug class member functions

#include <iostream>
#include <string>
#include "Doodlebug.hpp"

//---------------------Default Constructor------------------//
Doodlebug::Doodlebug()
    :Critter()
    ,stepsTillBreed(8)
    ,stepsTillStarved(3)
{}

//---------------------Constructor with x,y------------------//
Doodlebug::Doodlebug(int x, int y)
    :Critter(x,y)
    ,stepsTillBreed(8)
    ,stepsTillStarved(3)
{}

//---------------------move function------------------//
/* helps move the db around */
void Doodlebug::move(){

   //set this object moveYet base class to true so it can't move this turn anymore (step)
    moveYet = true;

    //find a location for db to move
    std::string direction = Critter::findNextAvailableSpot("doodlebug", false);

    //reduce steps needed to breed
    stepsTillBreed--;

    //helps figure out if db gonna eat an ant
    bool gonnaEatAnt = false;
    if(direction == "top"){
        gonnaEatAnt = Critter::grid.isAnt(_x,_y-1);
    }
    else if(direction == "right"){
        gonnaEatAnt = Critter::grid.isAnt(_x+1,_y);
    }
    else if(direction == "bottom"){
        gonnaEatAnt = Critter::grid.isAnt(_x,_y+1);
    }
    else if(direction == "left"){
        gonnaEatAnt = Critter::grid.isAnt(_x-1,_y);
    }

    //if eat ant reset starve steps
    if(gonnaEatAnt){
        stepsTillStarved = 3;
    }
    //else reduce steps till starve
    stepsTillStarved--;
    
    //add to grid 
    Critter::moveThis(direction);
}

//---------------------breed function------------------//
/* helps create new db */
void Doodlebug::breed(){

    //checking for starved
    if(stepsTillStarved == 0){
        //remove itself from the grid;
        Critter::grid.clearCell(_x,_y);

        //inc starved db
        Critter::grid.dbsStarvedInc();

        //get out of function
        return;
    }

    //check for breed else get out of function 
    if(stepsTillBreed != 0){
        return;
    }

    //find spot to breed if any, and it's breeding
    std::string direction = Critter::findNextAvailableSpot("doodlebug", true);
    Critter* temp;
    if(direction == "top"){
        temp = new Doodlebug(_x,_y-1);
    }
    else if(direction == "right"){
        temp = new Doodlebug(_x+1,_y);
    }
    else if(direction == "bottom"){
        temp = new Doodlebug(_x,_y+1);
    }
    else if(direction == "left"){
        temp = new Doodlebug(_x-1,_y);
    }
    //no breeding occurs because no spot available
    else {
        return;
    }

    //reset the steps until breed
    stepsTillBreed = 8;
    
    //inc breed total for db
    Critter::grid.dbsBreedInc();

    //add to grid
    Critter::grid.addToGrid(temp);
}

//---------------------getRepresent function------------------//
/* get the value of representation of this object ( 'X' ) */
char Doodlebug::getRepresent(){
    return represent;
}