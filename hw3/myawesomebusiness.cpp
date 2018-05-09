/*
* Filename: myawesomebusiness.cpp
* Name: Trong Van
* WSUID: X454V285
* HW: 3
* Description: namespace with non-member function define
*/

#include <iostream>
#include "myawesomebusiness.hpp"
#include <iomanip>

namespace MyAwesomeBusiness {
    //function that print data of each stands
    void printRundown(const std::vector<HotdogStand> &franchises, int num){
        std::cout << "Stand\t" << "Sales\t" << "Price\t" << "Revenue\t" << std::endl;
        std::cout << "=====\t=====\t===== \t=======" << std::endl;
        double price, revenue, standNum;
        for(int i = 0;i < num; i++){    
            standNum = i+1;
            price = ((franchises[i].getPrice()).getPennies())/100.0;
            revenue = ((franchises[i].getStandRevenue()).getPennies())/100.0;
            std::cout << std::fixed << std::setprecision(0);
            std::cout << standNum << "\t" << franchises[i].getDogsSold() << "\t";
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "$" << price << "\t";
            std::cout << "$" << revenue << std::endl;
        }
        double totalRevenue = HotdogStand::getTotalRevenue().getPennies()/100.0;
        std::cout << "TOTALS\t" << HotdogStand::getTotalHotdogsSold() << "\t\t$" << totalRevenue << std::endl; 
        std::cout << "# of Stands: " << HotdogStand::getNumStands() << std::endl;
    }
}
