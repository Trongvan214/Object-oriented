/*
* Filename: money.hpp
* Name: Trong Van
* WSUID: X454V285
* HW: 3
* Description: header file for the money class
*/
#ifndef __MONEY__
#define __MONEY__

namespace MyAwesomeBusiness {
    class Money {
        int dollars, cents;
        public:
            Money();
            Money(int gDollars, int gCents);
            Money(int gDollars);
            Money(double money);
            int getPennies() const;
            bool isNegative() const;
            void add(const Money &m);
            void subtract(const Money &m);
            bool isEqual(const Money &m) const;
            void print() const;
    };
}

#endif
