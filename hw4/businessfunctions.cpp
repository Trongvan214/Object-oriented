/*
* Filename: businessfunctions.cpp
* Name: Trong Van
* WSUID: X454V285
* HW: 4
* Description: define non-member function 
*/

#include <iostream>
#include <iomanip>
#include <random>
#include "businessfunctions.hpp"

namespace MyAwesomeBusiness {
    //function that print data of each stands
    void printRundown(const std::vector<HotdogStand> &franchises){
        //header part
        std::cout << std::right << std::setw(5) << "Stand";
        std::cout << "  " << std::right << std::setw(5) << "Sales";
        std::cout << "  " << std::right << std::setw(7) << "Price";
        std::cout << "  " << std::right << std::setw(9) << "Revenue";
        std::cout << "  " << std::right << std::setw(14)<< "Remaining Cash" << std::endl;
        //underline part
        std::cout << std::right << std::setw(5) << "=====";
        std::cout << "  " << std::right << std::setw(5) << "=====";
        std::cout << "  " << std::right << std::setw(7) << "=======";
        std::cout << "  " << std::right << std::setw(9) << "=========";
        std::cout << "  " << std::right << std::setw(14)<< "==============" << std::endl;
        //data part
        for(unsigned int i = 0;i < franchises.size(); i++){
            
            std::cout << std::right << std::setw(5) << i+1;
            std::cout << "  " << std::right << std::setw(5) << franchises[i].getDailyDogsSold();
            std::cout << "  " << std::right << std::setw(3) << franchises[i].getPrice();
            std::cout << "  " << std::right << std::setw(3) << franchises[i].getStandRevenue();
            std::cout << "  " << std::right << std::setw(8) << franchises[i].getCash() << std::endl;
        } 
    }
    void runSimulation(std::vector<HotdogStand> &franchises, int days){
        //random generator
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> fancyStand(1, 30);
        std::uniform_int_distribution<int> classicStand(20, 60);
        //holder for random generator
        int salesOfDay;
        Money endBalance;
        //start simulation for all franchieses
        while(days != 0){
            for(unsigned int i=0;i<franchises.size();i++){
                double price = ((franchises[i].getPrice()).getPennies())/100.0;
                //classic stands
                if(price <= 3.50){
                    //generate num 20-60
                    salesOfDay = classicStand(generator);
                    for(int j=0;j<salesOfDay;j++){
                        franchises[i].sellHotdog();
                    }
                }
                //fancy stands
                else {
                    //generate num 1-30
                    salesOfDay = fancyStand(generator);
                    for(int j=0;j<salesOfDay;j++){
                        franchises[i].sellHotdog();
                    }
                }
                //days done pay and resupply
                franchises[i].payWorker();
                franchises[i].replenishSupplies();
            }
            //print info
            printRundown(franchises);
            //reset for the next day
            for(unsigned int i=0;i<franchises.size();i++){
                franchises[i].dailyReset();
            } 
            //next day
            days--; 
        }
        //total of all end balance of the stands 
        for(unsigned int i=0;i<franchises.size();i++){
            endBalance = endBalance + franchises[i].getCash();
        }
        std::cout << std::endl;
        std::cout << std::setw(5) << std::right << "TOTALS";
        std::cout << " " << std::setw(5) << std::right << HotdogStand::getTotalHotdogsSold();
        std::cout << " " << std::setw(12) << std::right << HotdogStand::getTotalRevenue();
        std::cout << " " << std::setw(7) << std::right << endBalance << std::endl;
        std::cout << "Stands: " << HotdogStand::getNumStands() << std::endl;
    }
}
