#include "Cell.hpp"

Cell::Cell()
    :haveCritter(false)
    ,ptr(nullptr)
{}

void Cell::setCritter(Critter* c){
    ptr = c;
}
void Cell::setBool(bool v){
    haveCritter = v;
}
Critter* Cell::getCritter(){
    return ptr;
}
bool Cell::getBool(){
    return haveCritter;
}

void Cell::smartCheck(){
    if(ptr != nullptr){
        haveCritter = true;
    }
    else {
        haveCritter = false;
    }
}