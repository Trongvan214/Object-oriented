/*
* Filename: businessfunctions.hpp
* Name: Trong Van
* WSUID: X454V285
* HW: 4
* Description: namespace with non-member function declare
*/

#ifndef BUSINESSFUNCTIONS
#define BUSINESSFUNCTIONS

#include <vector>
#include "hotdogstand.hpp"

namespace MyAwesomeBusiness {
    void printRundown(const std::vector<HotdogStand> &franchises);
    void runSimulation(std::vector<HotdogStand> &franchises, int days);
}

#endif

