/*
* Filename: hotdogstand.hpp
* Name: Trong Van
* WSUID: X454V285
* HW: 3
* Description: header file for hotdogstand class
*/
#ifndef __HOTDOGSTAND__
#define __HOTDOGSTAND__

#include "money.hpp"

namespace MyAwesomeBusiness {
    class HotdogStand {
        Money balance, hotdogPrice;
        int hotdogSolds;
        static int totalStands, totalSolds;
        static Money totalRevenue;
        public:
            HotdogStand();
            HotdogStand(double gHotdogPrice);
            const Money getCash() const;
            const Money getPrice() const;
            const Money getStandRevenue() const;
            int getDogsSold() const;
            void setPrice(double price);
            void sellHotdog();
            static int getNumStands();
            static int getTotalHotdogsSold();
            static const Money getTotalRevenue();
    };
}
#endif
