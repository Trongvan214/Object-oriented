/*
* Filename: money.hpp
* Name: Trong Van
* WSUID: X454V285
* HW: 4
* Description: header file for the money class
*/
#ifndef __MONEY__
#define __MONEY__

#include <iostream>

namespace MyAwesomeBusiness {
    class Money {
        private:
            int dollars, cents;
        public:
            Money();
            Money(int gDollars, int gCents);
            Money(int gDollars);
            Money(double money);
            int getPennies() const;
            bool isNegative() const;
            double moneyToDouble(Money m);
            Money operator -();
            Money& operator ++();
            Money operator ++(int);
            Money& operator --();
            Money operator --(int);
            friend Money operator + (const Money &m, const Money &n);
            friend Money operator *(int v, const Money &m);
            friend Money operator *(const Money &m, int v);
            friend Money operator *(double v, const Money &m);
            friend Money operator *(const Money &m, double v);
            friend bool operator > (const Money &m, const Money &n);
            friend bool operator >= (const Money &m, const Money &n);
            friend bool operator < (const Money &m, const Money &n);
            friend bool operator <= (const Money &m, const Money &n);
            friend bool operator == (const Money &m, const Money &n);
            friend bool operator != (const Money &m, const Money &n);
            friend std::ostream& operator << (std::ostream& output, const Money &m);
            friend std::istream& operator >> (std::istream& input, Money &m);
    };
            //function prototype
            Money operator - (const Money &m, const Money &n);
}
#endif
