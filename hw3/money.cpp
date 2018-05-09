/*
* Filename: money.cpp
* Name: Trong Van
* WSUID: X454V285
* HW: 3
* Description: money class define memeber functions
*/
#include <iostream>
#include <math.h>
#include <iomanip>

#include "money.hpp"

namespace MyAwesomeBusiness {
    Money::Money(){
        dollars = 0;
        cents = 0;
    }
    Money::Money(int gDollars, int gCents){
        dollars = gDollars;
        cents = gCents;
    }
    Money::Money(int gDollars){
        dollars = gDollars;
        cents = 0;
    }
    Money::Money(double money){
        double fractpart, wholepart;
        fractpart = modf(money , &wholepart);
        dollars = wholepart;
        cents = round(fractpart*100);
    }
    int Money::getPennies() const{
        return (dollars*100)+cents;
    }
    bool Money::isNegative() const{
        //if one these negative than we have negative balance
        if(dollars < 0 || cents < 0){
            return true;
        }
        return false;
    }
    void Money::add(const Money &m){
        double balance = m.getPennies()+ getPennies();
        double newBalance = balance/100;
        //split whole and fraction out
        double fractpart, wholepart;
        fractpart = modf(newBalance, &wholepart);
        dollars = wholepart;
        cents = round(fractpart*100);
    }   
    void Money::subtract(const Money &m){
        double balance = getPennies() - m.getPennies();
        double newBalance = balance/100;
        //split whole and fraction out
        double fractpart, wholepart;
        fractpart = modf(newBalance, &wholepart);
        dollars = wholepart;
        cents = round(fractpart*100);
    }
    bool Money::isEqual(const Money &m) const{
        if(getPennies() == m.getPennies()){
            return true;
        }
        return false;
    }
    void Money::print() const {
        double balance = dollars + (cents/100.0);
        //check if +/-
        std::cout << std::fixed << std::setprecision(2);
        if(balance < 0){
            std::cout << "($" << fabs(balance) << ")\n";
        }
        else {
            std::cout << "$" << balance << "\n";
        }
    }
}
