/*
* Filename: hotdogstand.cpp
* Name: Trong Van
* WSUID: X454V285
* HW: extra credit 1
* Description: define member function of hotdogstand
*/
#include <math.h>
#include "hotdogstand.hpp"

namespace MyAwesomeBusiness {
    //init static variable
    int HotdogStand::totalStands = 0;
    int HotdogStand::totalSolds = 0;
    Money HotdogStand::totalRevenue = Money();
    
    //constructor with no parameter
    HotdogStand::HotdogStand(){
        hotdogPrice = Money(3.5);
        hotdogsSoldInOneDay = 0;
        hotdogsSoldInTotal = 0;
        hourlyWage = Money(7.25);
        hotDogSupply = 60;
        maxHotdogSupply = 60;
        wholeSaleHotDogCost = Money(0.15);
        balance = -wholeSaleHotDogCost * maxHotdogSupply;
        totalStands++;
    }
    //constructor with double pass in
    HotdogStand::HotdogStand(double gHotdogPrice){
        hotdogPrice = Money(gHotdogPrice);
        hotdogsSoldInOneDay = 0;
        hotdogsSoldInTotal = 0;
        if(hotdogPrice > 3.50){
            hourlyWage = Money(8);
            hotDogSupply = 30;
            wholeSaleHotDogCost = Money(0.50);
        } 
        else {
            hourlyWage = Money(7.25);
            hotDogSupply = 60;
            wholeSaleHotDogCost = Money(0.15);
            

        }
        maxHotdogSupply = hotDogSupply;
        balance = -wholeSaleHotDogCost * maxHotdogSupply;
        totalStands++;
    }
    //constructor with money pass in
    HotdogStand::HotdogStand(Money m){
        hotdogPrice = m;
        hotdogsSoldInOneDay = 0;
        hotdogsSoldInTotal = 0;
        if(hotdogPrice > 3.50){
            hourlyWage = Money(8);
            hotDogSupply = 30;
            wholeSaleHotDogCost = Money(0.50);
        } 
        else {
            hourlyWage = Money(7.25);
            hotDogSupply = 60;
            wholeSaleHotDogCost = Money(0.15);
            

        }
        maxHotdogSupply = hotDogSupply;
        balance = -wholeSaleHotDogCost * maxHotdogSupply;
        totalStands++;
    }
    //get the cash amount (balance of the this hotdogstand)
    const Money HotdogStand::getCash() const{
        return balance;
    }
    //get price of the hotdog
    const Money HotdogStand::getPrice() const{
        return hotdogPrice;
    }
    //get total sells of hotdog of one day
    int HotdogStand::getDailyDogsSold() const{
        return hotdogsSoldInOneDay;
    }
    //use this hotdogstand balance to buy max supply of hotdog for this stand
    void HotdogStand::replenishSupplies(){
        int hotdogAmountToBuy = maxHotdogSupply - hotDogSupply;
        balance = balance - hotdogAmountToBuy * wholeSaleHotDogCost;
        hotDogSupply = maxHotdogSupply;
    }
    //pay the worker for the day
    void HotdogStand::payWorker(){
        balance = balance - totalWorkHours * hourlyWage;
    }
    //reset the stand back the it's init values
    void HotdogStand::dailyReset(){
        hotdogsSoldInOneDay = 0;
        if(hotdogPrice > 3.50){
            hourlyWage = Money(8);
            hotDogSupply = 30;
            wholeSaleHotDogCost = Money(0.50);
        } 
        else {
            hourlyWage = Money(7.25);
            hotDogSupply = 60;
            wholeSaleHotDogCost = Money(0.15);
        }
        maxHotdogSupply = hotDogSupply;
    }
    //get the amount of money this stand in ONE DAY
    const Money HotdogStand::getStandRevenue() const{
        return hotdogPrice * hotdogsSoldInOneDay;
    }
    //get the amount of money this stand in TOTAL
    const Money HotdogStand::getTotalStandRevenue() const{
        return hotdogPrice * hotdogsSoldInTotal;
    }
    //change the price of the hotdog
    void HotdogStand::setPrice(double price){
        hotdogPrice = Money(price);
    }
    //sell a hotdog
    void HotdogStand::sellHotdog(){
        hotdogsSoldInOneDay++;
        hotdogsSoldInTotal++;
        hotDogSupply--;
        totalSolds++;
        balance = balance + hotdogPrice;
        totalRevenue = totalRevenue + hotdogPrice;
    }
    //static function get total number of hotdog stand in class
    int HotdogStand::getNumStands(){
        return totalStands;
    }
    //static function get total number of hotdogs sold in class
    int HotdogStand::getTotalHotdogsSold(){
        return totalSolds;
    }
    //static function get total number of hotdog revenue in class
    const Money HotdogStand::getTotalRevenue(){
        return totalRevenue;
    }
}
