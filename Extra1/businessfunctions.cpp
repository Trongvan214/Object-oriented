/*
* Filename: businessfunctions.cpp
* Name: Trong Van
* WSUID: X454V285
* HW: extra credit 1
* Description: define non-member function 
*/

#include <iostream>
#include <iomanip>
#include <random>
#include "businessfunctions.hpp"

namespace MyAwesomeBusiness {
    //function that print data of each stands
    void printRundown(const std::vector<HotdogStand> &franchises, std::ostream &out){
        //header part
        out << std::right << std::setw(5) << "Stand";
        out << "  " << std::right << std::setw(5) << "Sales";
        out << "  " << std::right << std::setw(7) << "Price";
        out << "  " << std::right << std::setw(9) << "Revenue";
        out << "  " << std::right << std::setw(14)<< "Remaining Cash" << std::endl;
        //underline part
        out << std::right << std::setw(5) << "=====";
        out << "  " << std::right << std::setw(5) << "=====";
        out << "  " << std::right << std::setw(7) << "=======";
        out << "  " << std::right << std::setw(9) << "=========";
        out << "  " << std::right << std::setw(14)<< "==============" << std::endl;
        //data part
        for(unsigned int i = 0;i < franchises.size(); i++){
            
            out << std::right << std::setw(5) << i+1;
            out << "  " << std::right << std::setw(5) << franchises[i].getDailyDogsSold();
            out << "  " << std::right << std::setw(3) << franchises[i].getPrice();
            out << "  " << std::right << std::setw(3) << franchises[i].getStandRevenue();
            out << "  " << std::right << std::setw(8) << franchises[i].getCash() << std::endl;
        } 
    }
    void runSimulation(std::vector<HotdogStand> &franchises, int days, std::ostream &out){
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
            printRundown(franchises, out);
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
        out << std::endl;
        out << std::setw(5) << std::right << "TOTALS";
        out << " " << std::setw(5) << std::right << HotdogStand::getTotalHotdogsSold();
        out << " " << std::setw(12) << std::right << HotdogStand::getTotalRevenue();
        out << " " << std::setw(7) << std::right << endBalance << std::endl;
        out << "Stands: " << HotdogStand::getNumStands() << std::endl;
    }
}
