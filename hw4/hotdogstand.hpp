/*
* Filename: hotdogstand.hpp
* Name: Trong Van
* WSUID: X454V285
* HW: 4
* Description: header file for hotdogstand class
*/
#ifndef __HOTDOGSTAND__
#define __HOTDOGSTAND__

#include "money.hpp"

namespace MyAwesomeBusiness {
    class HotdogStand {
        private:
            Money balance, hotdogPrice, hourlyWage, wholeSaleHotDogCost;
            int hotdogsSoldInOneDay, hotdogsSoldInTotal, hotDogSupply, maxHotdogSupply;
            const int totalWorkHours = 8;
            static int totalStands, totalSolds;
            static Money totalRevenue;
        public:
            HotdogStand();
            HotdogStand(double gHotdogPrice);
            HotdogStand(Money m);
            const Money getCash() const;
            const Money getPrice() const;
            int getDailyDogsSold() const;
            void replenishSupplies();
            void payWorker();
            void dailyReset();
            const Money getStandRevenue() const;
            const Money getTotalStandRevenue() const;
            void setPrice(double price);
            void sellHotdog();
            static int getNumStands();
            static int getTotalHotdogsSold();
            static const Money getTotalRevenue();
    };
}
#endif
