/*
* Filename: hotdogstand.cpp
* Name: Trong Van
* WSUID: X454V285
* HW: 3
* Description: define member function of hotdogstand
*/
#include <math.h>
#include "hotdogstand.hpp"

namespace MyAwesomeBusiness {
    //init static variable
    int HotdogStand::totalStands = 0;
    int HotdogStand::totalSolds = 0;
    Money HotdogStand::totalRevenue = Money();
    
    HotdogStand::HotdogStand(){
        balance = Money();
        hotdogSolds = 0;
        hotdogPrice = Money(3.5);
        totalStands++;
    }
    HotdogStand::HotdogStand(double gHotdogPrice){
        balance = Money();
        hotdogSolds = 0;
        hotdogPrice = Money(gHotdogPrice);
        totalStands++;
    }
    const Money HotdogStand::getCash() const{
        return balance;
    }
    const Money HotdogStand::getPrice() const{
        return hotdogPrice;
    }
    const Money HotdogStand::getStandRevenue() const{
        double revenue = (hotdogPrice.getPennies()/100.0)*hotdogSolds;
        return Money(revenue);
    }
    void HotdogStand::setPrice(double price){
        hotdogPrice = price;
    }
    void HotdogStand::sellHotdog(){
        hotdogSolds+=1;
        balance.add(hotdogPrice);
        totalSolds+=1;
        totalRevenue.add(hotdogPrice);
    }
    int HotdogStand::getDogsSold() const{
        return hotdogSolds;
    }
    int HotdogStand::getNumStands(){
        return totalStands;
    }
    int HotdogStand::getTotalHotdogsSold(){
        return totalSolds;
    }
    const Money HotdogStand::getTotalRevenue(){
        return totalRevenue;
    }
}
