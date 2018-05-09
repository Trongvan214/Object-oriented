//Author: Trong Van
//Student ID: x454v285
//Programming Number: 6
//filename: Grid.cpp
//Description: implementation of the Grid class member functions 

#include <iostream>
#include <string>
#include <iomanip>
#include "Grid.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

//---------------------Default Constructor------------------//
Grid::Grid()
    :_height(8)
    ,_width(8)
    ,totalAnts(0)
    ,totalDBs(0)
    ,antsEaten(0)
    ,antsBreed(0)
    ,dBsBreed(0)
    ,dBstarved(0)
    ,arr(new Critter**[_height])
{
    for(int i = 0; i < 8; i++){
        arr[i] = new Critter*[_width];
    }
    clearGrid();
}

//---------------------Constructor with height, and width------------------//
Grid::Grid(int height, int width)
    :_height(height)
    ,_width(width)
    ,totalAnts(0)
    ,totalDBs(0)
    ,antsEaten(0)
    ,antsBreed(0)
    ,dBsBreed(0)
    ,dBstarved(0)
    ,arr(new Critter**[_height])
{
    for(int i = 0; i < height; i++){
        arr[i] = new Critter*[_width];
    }
    clearGrid();
}

//---------------------at function------------------//
/* return the critter ptr at coords */
/* return the value at x , y in the grid */
Critter* Grid::at(int x, int y){
    return arr[y][x];
}

//---------------------clearCell function------------------//
/* set the cell at x, y to nullptr */
/* also smart enough to figure out if it's an critter and dec the right one */
void Grid::clearCell(int x, int y){
    Critter* temp = arr[y][x];
    if(temp == nullptr){
        return;
    }
    else if(temp->getRepresent() == 'O'){
        totalAnts--;
    }
    else {
        totalDBs--;
    }
    // delete arr[y][x];
    arr[y][x] = nullptr;
}

//---------------------clearGrid function------------------//
void Grid::clearGrid(){
    for(int y = 0; y < _height; y++){
        for(int x = 0; x < _width; x++){
            clearCell(x,y);
        }
    }
}

//---------------------clearGrid function------------------//
bool Grid::isSpotAvailable(int x, int y){
    //check to see if it's out of bound and if it's empty
    //-------------------------------------------------------------------------------------------------------------------------------------------
    // std::cout << "isSpotAvailable() \t";
    // std::cout << "spot at x: " << x << " y: " << y << " available?: ";
    //-------------------------------------------------------------------------------------------------------------------------------------------
    if(x < 0 || y < 0 || x >= _width || y >= _height){
        // std::cout << "false" << std::endl;
        return false;
    }
    else if(arr[y][x] == nullptr){
        // std::cout << "true" << std::endl;
        return true;
    }
    // std::cout << "false" << std::endl;
    return false;
}

//-------------------------addToGrid function----------------------------//
void Grid::addToGrid(Critter *c){
    int x = c->getX();
    int y = c->getY();
    if(isSpotAvailable(x,y)){
        arr[y][x] = c;
        //tracks total ants and doodlebugs
        if(c->getRepresent() == 'X'){
            totalDBs++;
        }
        else {
            totalAnts++;
        }
    }
    //if it's taking nothing happen
}

//-------------------------getHeightOfGrid function----------------------------//
/* return the height of the grid (variable) */
int Grid::getHeightOfGrid(){
    return _height;
}

//-------------------------getWidthOfGrid function----------------------------//
/* return the width of the grid (variable) */
int Grid::getWidthOfGrid(){
    return _width;
}

//-------------------------isAnt function----------------------------//
/* to check to if the given coords is an ant */
bool Grid::isAnt(int x, int y){
    // std::cout << "in isAnt() looking at x:" << x << " y: " << y << " return: ";
    //boundary check
    if(x < 0 || y < 0 || x >= _width || y >= _height){
        // std::cout << "false" << std::endl;
        return false;
    }
    Critter* temp = at(x,y);
    if(temp == nullptr){
        // std::cout << " false" << std::endl;
        return false;
    }
    else {
        bool a = temp->getRepresent() == (char)'O';
        // std::cout << a << std::endl;
        return a;
    }
}

//-------------------------antsBreedInc function----------------------------//
/* increment the antsBreed private variable */
void Grid::antsBreedInc(){
    antsBreed++;
}

//-------------------------dbsBreedInc function----------------------------//
/* increment the dBsBreed private variable */
void Grid::dbsBreedInc(){
    dBsBreed++;
}

//-------------------------dbsStarvedInc function----------------------------//
/* increment the dBstarved private variable */
void Grid::dbsStarvedInc(){
    dBstarved++;
}

//-------------------------eatAnt function----------------------------//
/* clear out given cell and inc antsEaten */
void Grid::eatAnt(int x, int  y){
    clearCell(x,y);
    antsEaten++;
}

//-------------------Init setup-------------------//
/* generate all the ants and dbs and add to grid*/
void Grid::init(){

    int initTotalAnts = (_width*_height)/4; //100 but do this just in case grid less 
    int initTotalDBs = 5;                  
    Critter* t;

    //loop until 100 added 
    while(totalAnts != initTotalAnts){ 
        t = new Ant();
        addToGrid(t);
    }
    //loop until 5 added
    while(totalDBs != initTotalDBs){
        t = new Doodlebug();
        addToGrid(t);
    }
    std::cout << "=================================================================================" << std::endl;
    std::cout << "=================================Starting Grid===================================" << std::endl;
    std::cout << "=================================================================================" << std::endl;
    showGrid();
    printScores();
}

//-------------------nextStep setup-------------------//
/* a move step of the grid */
void Grid::nextStep(){
    int y, x;

    //let all the doodlebugs go first
    Critter* temp;
    for(y = 0; y < _height; y++){
        for(x = 0; x < _width; x++){
            temp = arr[y][x];
            if(temp != nullptr){
                if(temp->getRepresent() == 'X' && temp->getMoveYet() == false){
                    // std::cout << "call db move()";
                    // std::cout << "x: " << x << " y: " << y << std::endl;
                    temp->move();
                }
            }
        }
    }
    
    //show doodlebug movements
    std::cout << "=================================================================================" << std::endl;
    std::cout << "============================Doodlebugs Movement Grid=============================" << std::endl;
    std::cout << "=================================================================================" << std::endl;
    showGrid();

    //let the ants go
    for(y = 0; y < _height; y++){
        for(x = 0; x < _width; x++){
            temp = arr[y][x];
            if(temp != nullptr){
                if(temp->getRepresent() == 'O' && temp->getMoveYet() == false){
                    // std::cout << "call ant move() at ";
                    // std::cout << "x: " << x << " y: " << y << std::endl;
                    temp->move();
                }
            }
        }
    }

    //show ants movements
    std::cout << "=================================================================================" << std::endl;
    std::cout << "================================Ants Movement Grid===============================" << std::endl;
    std::cout << "=================================================================================" << std::endl;
    showGrid();

    //call breed on doodlebugs first
    for(y = 0; y < _height; y++){
        for(x = 0; x < _width; x++){
            temp = arr[y][x];
            if(temp != nullptr){
                if(temp->getRepresent() == 'X'){
                    temp->breed();
                }
            }
        }
    }

    //call breed on ant after
    for(y = 0; y < _height; y++){
        for(x = 0; x < _width; x++){
            temp = arr[y][x];
            if(temp != nullptr){
                if(temp->getRepresent() == 'O'){
                    temp->breed();
                }
            }
        }
    }

    //show breed and starved movement
    std::cout << "=================================================================================" << std::endl;
    std::cout << "=============================Breed and Starved Grid==============================" << std::endl;
    std::cout << "=================================================================================" << std::endl;
    showGrid();

    //prepare for nextStep set all critter moveYet to false
    for(int y = 0; y < _height; y++){
        for(int x = 0; x < _width; x++){
            temp = arr[y][x];
            if(temp != nullptr){
                    temp->setMoveYet(false);
            }
        }
    }
    //print out info about this step
    printScores();

    //reset the steps scores
    stepScoresReset();
}

//---------------------stepScoresReset function------------------//
/* reset the scores that last only for one step */
void Grid::stepScoresReset(){
    //reset score
    antsEaten = 0;
    antsBreed = 0;
    dBsBreed = 0;
    dBstarved = 0;
}

//---------------------print function------------------//
/* print out the scores of each steps */
void Grid::printScores(){
    std::cout <<  "Ants eaten: " << antsEaten << std::endl;
    std::cout << "Ants breed: " << antsBreed  << std::endl;
    std::cout << "DB breed: " <<  dBsBreed << std::endl;
    std::cout << "DB starved: " << dBstarved << std::endl;
    std::cout << "Total ants: " << totalAnts << std::endl;
    std::cout << "Total DBs: " << totalDBs << std::endl;
}

void Grid::showGrid(){
    Critter* temp;
    for(int y = 0; y < _height; y++){
        for(int x = 0; x < _width; x++){
            temp = arr[y][x];
            if(temp != nullptr){
                std::cout << "|" << std::setw(2) << temp->getRepresent() << std::setw(2);
            }
            else {
                    std::cout << "|" << std::setw(2) << " " << std::setw(2);
            }
        }
        std::cout << "|" << std::endl;
    }
}