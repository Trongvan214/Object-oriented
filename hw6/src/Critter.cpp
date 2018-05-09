//Author: Trong Van
//Student ID: x454v285
//Programming Number: 6
//filename: Critter.cpp
//Description: implementation of the critter class member functions

#include <iostream>
#include <random>
#include <string>
#include "Critter.hpp"

//init the static grid variable to a 20x20 grid
Grid Critter::grid = Grid(20,20);

//---------------------Default constructor------------------//
Critter::Critter()
    :_x ( randomGenValue(0,grid.getWidthOfGrid()-1) ) 
    ,_y ( randomGenValue(0,grid.getHeightOfGrid()-1) )
    ,moveYet(false)
{}

//---------------------Constructor with x, y------------------//
Critter::Critter(unsigned int x, unsigned int y)
    :_x(x)
    ,_y(y)
    ,moveYet(false)
{}

//---------------------getX function------------------//
const int Critter::getX() const{
    return _x;
}

//---------------------getY function------------------//
const int Critter::getY() const{
    return _y;
}

//---------------------setMoveYet function------------------//
void Critter::setMoveYet(bool value){
    moveYet = value;
}

//---------------------getMoveYet function------------------//
bool Critter::getMoveYet() const{
    return moveYet;
}

//---------------------moveThis function------------------//
/*  move this object in giving direction */
void Critter::moveThis(std::string direction){

    //copy current object
    Critter* temp = grid.at(_x,_y);

    //clear current object 
    grid.clearCell(_x,_y);

    //modify copy object
    if(direction == "top"){
        temp->_y-=1;
    }
    else if(direction == "right"){
        temp->_x+=1;
    }
    else if(direction == "bottom"){
        temp->_y+=1;
    }
    else if(direction == "left"){
        temp->_x-=1;
    }
    //else stay at same spot

    //checking to see it's an ant is at that move
    if(grid.isAnt(temp->_x, temp->_y)){
        grid.eatAnt(temp->_x,temp->_y);
    }
    
    //add new modify object to the grid
    grid.addToGrid(temp);
}

//---------------------findNextAvailableSpot function------------------//
/* This function find the next available spot 
    using a gen value to find the direction to start looking for that spot
    "giving fairness" 
*/
std::string Critter::findNextAvailableSpot(std::string type, bool isBreeding){
    int randomValue = randomGenValue(1,3);
    int location;
    //find spot around the object for breeding
    if(isBreeding){
        location = findForBreed(randomValue);
    }
    else {
        if(type == "ant"){
            location = findForAnt(randomValue);
        }
        else {
            location = findForDB(randomValue);
        }
    }
    switch(location){
        case 0:
            return "top";
            break;
        case 1:
            return "right";
            break;
        case 2:
            return "bottom";
            break;
        case 3:
            return "left";
            break;
        default:
            return "none";
    }
}

//---------------------findForAnt function------------------//
/*  This function does the logic of findNextAvailableSpot for ant movement */
int Critter::findForAnt(int direction){
    //look for a spot in the (direction)  
    int c[4][2] = {{0,-1}, {1,0}, {0,1}, {-1, 0}}; //help with figuring out the location
    int x = c[direction][0];
    int y = c[direction][1];
    if(grid.isSpotAvailable(_x+x, _y+y)){
        return direction;   
    }
    //that spot is taken 
    return -1;
}

int Critter::findForDB(int direction){
    //the clockwise search for spots 
    int c[4][2] = {{0,-1}, {1,0}, {0,1}, {-1, 0}};
    int x, y;
    //starting direction then start clockwise search 
    int j = direction;
    //4 directions to look max
    for(int i = 0; i < 4; i++){
        x = c[j][0];
        y = c[j][1];
        if(grid.isAnt(_x+x, _y+y)){
            return j;   
        }
        //circular value before 0-3 including 3
        j = (j+1)%4;
    }
    //when can't find any spot use ant method
    return findForAnt(direction);
}

int Critter::findForBreed(int direction){

    //the clockwise search for spots 
    int c[4][2] = {{0,-1}, {1,0}, {0,1}, {-1, 0}};

    int x, y;

    //starting direction then start clockwise search 
    int j = direction;

    //4 directions to look max
    for(int i = 0; i < 4; i++){
        x = c[j][0];
        y = c[j][1];
        if(grid.isSpotAvailable(_x+x, _y+y)){
            return j;   
        }
        //circular value before 0-3 including 3
        j = (j+1)%4;
    }

    //when can't find any spot 
    return -1;
}
//---------------------randomGenValue function------------------//
/*  Generate a random number */
int Critter::randomGenValue(int from, int to){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> randomPos(from, to);
    int random = randomPos(generator);
    return random;
}
void Critter::nextStep(){
    grid.nextStep();
}
void Critter::init(){
    grid.init();
}