/*
* Filename: money.cpp
* Name: Trong Van
* WSUID: X454V285
* HW: extra credit 1
* Description: money class define memeber functions
*/
#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdlib.h> 
#include "money.hpp"

namespace MyAwesomeBusiness {
    //constructor with no parameter
    Money::Money(){
        dollars = 0;
        cents = 0;
    }
    //constructor with dollars and cents pass in
    Money::Money(int gDollars, int gCents){
        dollars = gDollars;
        cents = gCents;
    }
    //constuctor with just dollars pass in
    Money::Money(int gDollars){
        dollars = gDollars;
        cents = 0;
    }
    //constructor with money pass in 
    Money::Money(double money){
        double fractpart, wholepart;
        fractpart = modf(money , &wholepart);
        dollars = wholepart;
        cents = round(fractpart*100);
    }
    //return balance in pennies
    int Money::getPennies() const{
        return (dollars*100)+cents;
    }
    //return bool if balance is neg or not
    bool Money::isNegative() const{
        //if one these negative than we have negative balance
        if(dollars < 0 || cents < 0){
            return true;
        }
        return false;
    }
    //helper function use to turn (money) obj balance into double
    double moneyToDouble(Money m){
        double d = static_cast<double>(m.getPennies())/100;
        return d;
    }
    //member function operator overload
    //Unary minus (negative sign)
    Money Money::operator -(){
        return Money(-dollars, -cents);
    }
    //Unary post-increment
    Money& Money::operator ++(){
        dollars++;
        return *this;
    }
    //Unary pre-increment
    Money Money::operator ++(int){
        Money temp = *this;
        ++(*this);
        return temp;
    }
    //Unary post-decrement
    Money& Money::operator --(){
        dollars--;
        return *this;
    }
    //Unary pre-decrement
    Money Money::operator --(int){
        Money temp = *this;
        --(*this);
        return temp;
    }
    //friend function operator overload
    Money operator +(const Money &m, const Money &n){  
        return Money(moneyToDouble(m) + moneyToDouble(n));
    }
    // mult operator with int and money
    Money operator *(int v, const Money &m){
        return Money(moneyToDouble(m) * v);
    }
    //mult operator with money and int
    Money operator *(const Money &m, int v){
        return Money(moneyToDouble(m) * v);
    }
    //mult operator with double and money
    Money operator *(double v, const Money &m){
        return Money(moneyToDouble(m) * v);
    }
    //mult operator with money and double 
    Money operator *(const Money &m, double v){
        return Money(moneyToDouble(m) * v);
    }
    //less than operator
    bool operator > (const Money &m, const Money &n){
        return m.getPennies() > n.getPennies();
    }
    //less and equal operator
    bool operator >= (const Money &m, const Money &n){
        return m.getPennies() >= n.getPennies();
    }
    //greater than operator 
    bool operator < (const Money &m, const Money &n){
        return m.getPennies() < n.getPennies();
    }
    //greater and equal operator
    bool operator <= (const Money &m, const Money &n){
        return m.getPennies() <= n.getPennies();
    }
    //equality operator
    bool operator == (const Money &m, const Money &n){
        return m.getPennies() == n.getPennies();
    }
    //inequality operator
    bool operator != (const Money &m, const Money &n){
        return m.getPennies() != n.getPennies();
    }
    //insertion operator
    std::istream& operator >> (std::istream &input, Money &m){
        std::string priceFilter;
        input >> priceFilter;
         if(priceFilter[0] == '$'){
            priceFilter[0] = '0';
        }
        double price = atof(priceFilter.c_str());
        m = Money(price);
        return input;
    }
    //extraction operator
    std::ostream& operator << (std::ostream &output, const Money &m){
        double balance = moneyToDouble(m);
        //check if +/-
        output << std::fixed << std::setprecision(2);
        if(balance < 0){
            output << "($" << fabs(balance) << ")";
        }
        else {
            output << "$" << balance;
        }
        return output;
    }
    //non-memeber non-friend 
    Money operator - (const Money &m, const Money &n){
        double newBalance = static_cast<double>(m.getPennies()-n.getPennies())/100;
        return Money(newBalance);
    }
}
