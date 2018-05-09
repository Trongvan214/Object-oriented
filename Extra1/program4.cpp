/*
* Filename: program3.cpp
* Name: Trong Van
* WSUID: X454V285
* HW: extra credit 1
* Description: main program where the simulation of a selling hotdogs start
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <cstring>
#include <fstream>
#include "businessfunctions.hpp"


void printError();

int main(int argc, char* argv[])
{
	namespace MAB = MyAwesomeBusiness;    
	std::vector<MAB::HotdogStand> franchises;
	int stands;
	int fancyStands;
	MAB::Money fancyPrice;
	int days;


	if(argc > 2){
		days = atoi(argv[1]);
		stands = atoi(argv[2]);
		if(argc == 4){
			printError();
		}
		else if(argc > 3){
			fancyStands = atoi(argv[3]);
		}
		else {
			fancyStands = 0;
		}
		if(argc == 5){
			printError();
		}
		else if(argc == 6){
			if(strcmp(argv[4], "-c") == 0 || 
				strcmp(argv[4], "--cost") == 0)
				{
					std::string priceFilter = argv[5];
					float price = atof(priceFilter.c_str());
					fancyPrice = MAB::Money(price);
				}
			else {
				printError();
			}
		}
		else if(argc > 6){
			printError();
		}
		//after command line argument checks
		// Create vector
		for (int i = 0; i < stands; i++) {
			if (i < stands - fancyStands) {
				franchises.emplace_back();
			} else {
				franchises.emplace_back(fancyPrice);
			}
		}

		std::ofstream outputFile("sim.txt");
		MAB::runSimulation(franchises, days, outputFile);
    }
	else {
		printError();
	}
	return 0;
}

void printError(){
	std::stringstream errMsg;
	errMsg << "\n\nPlease enter command line aurgments\n";
	errMsg << "Instructions:\n";
	errMsg << "First argument (not the exe file) # of simulated days **required**\n";
	errMsg << "Second argument is # of stands **required**\n";
	errMsg << "Third argument # of fancy stand (default value = 0) **not required**\n";
	errMsg << "If # of fancy stands is provided then you MUST put the cost after -c OR --cost flags\n\n";
	errMsg << "Exp:\n";
	errMsg << "./xc1 3 3 1 -c 8.99\n";
	errMsg << "./xc1 3 3 1 --cost 8.99\n";
	errMsg << "./xc1 3 4\n";
	throw std::invalid_argument(errMsg.str().c_str());
}