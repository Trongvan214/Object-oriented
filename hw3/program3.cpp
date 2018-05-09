/*
* Filename: program3.cpp
* Name: Trong Van
* WSUID: X454V285
* HW: 3
* Description: main program where the simulation of a selling hotdogs start
*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stdlib.h> 
#include "myawesomebusiness.hpp"

using namespace MyAwesomeBusiness;

int main(){
    //random lib didn't work for me so i use ctime for random num generator
    //random seed generate
    srand(time(0));
    std::vector<HotdogStand> franchises;
    //cin variables 
    int stands, fancyStands;
    double price ;
    //prompt users
    std::cout << "Welcome!" << std::endl;
    std::cout << "How many hotdog stands do you own?" << std::endl;
    std::cin >> stands;
    std::cout << "How many of those sell fancy hotdogs?" << std::endl;
    std::cin >> fancyStands;
    //if there is fancy stands
    if(fancyStands > 0){
        std::string priceFilter;
        std::cout << "How much does a fancy hotdog cost?" << std::endl;
        std::cin >> priceFilter;
        //figure out if users include '$' and filter it
        if(priceFilter[0] == '$'){
            priceFilter[0] = '0';
        }
        price = atof(priceFilter.c_str());
    }
    //inserting the type of stands into franchiese array 
    int numClassicStands = stands - fancyStands;
    for(int i=0;i<stands;i++){
        if(i < numClassicStands){
            franchises.push_back(HotdogStand());
        }
        else {
            franchises.push_back(HotdogStand(price));
        }
    }
    //start simulation for all franchieses
    for(int i=0;i<stands;i++){
        int salesOfDay;
        //classic stands
        if(i<numClassicStands){
            //generate num 20-60
            salesOfDay = (rand()%41)+20;
            for(int j=0;j<salesOfDay;j++){
                franchises[i].sellHotdog();
            }
        }
        //fancy stands
        else {
            //generate num 1-30
            salesOfDay = (rand()%30)+1;
            for(int j=0;j<salesOfDay;j++){
                franchises[i].sellHotdog();
            }
        }
    }
    //print the result
    printRundown(franchises, stands);
    return 0;
}
