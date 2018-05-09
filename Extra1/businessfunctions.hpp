/*
* Filename: businessfunctions.hpp
* Name: Trong Van
* WSUID: X454V285
* HW: extra credit 1
* Description: namespace with non-member function declare
*/

#ifndef BUSINESSFUNCTIONS
#define BUSINESSFUNCTIONS

#include <vector>
#include <fstream>
#include "hotdogstand.hpp"

namespace MyAwesomeBusiness {
    void printRundown(const std::vector<HotdogStand> &franchises, std::ostream &out);
    void runSimulation(std::vector<HotdogStand> &franchises, int days, std::ostream &out);
}

#endif

