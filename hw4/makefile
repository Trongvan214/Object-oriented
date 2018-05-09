#Filename: makefile
#Name: Trong Van
#WSUID: X454V285
#HW: 4
#Description: makefile to compile each piece and put them together

CXX = g++
CXXFLAGS = -Wall
COMPILEONLY = -c
MONEYOBJ = money.o
BUSINESSFUNCTIONSOBJ = businessfunctions.o
PROGRAMOBJ = program4.o
HOTDOGSTANDOBJ = hotdogstand.o

SRC = $(PROGRAMOBJ) $(MONEYOBJ) $(BUSINESSFUNCTIONSOBJ) $(HOTDOGSTANDOBJ) 
EXE = hw04

#compile the final code and run it 
$(EXE): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(SRC)
#compile the program 
$(PROGRAMOBJ): program4.cpp $(BUSINESSFUNCTIONSOBJ) test_interface.hpp
	$(CXX) $(CXXFLAGS) $(COMPILEONLY) program4.cpp $(BUSINESSFUNCTIONSOBJ) -o $(PROGRAMOBJ)
#compile the non member functions
$(BUSINESSFUNCTIONSOBJ): businessfunctions.hpp businessfunctions.cpp $(HOTDOGSTANDOBJ)
	$(CXX) $(CXXFLAGS) $(COMPILEONLY) businessfunctions.cpp $(HOTDOGSTANDOBJ) -o $(BUSINESSFUNCTIONSOBJ)
#compile the hotdogstand class
$(HOTDOGSTANDOBJ): hotdogstand.cpp hotdogstand.hpp $(MONEYOBJ)
	$(CXX) $(CXXFLAGS) $(COMPILEONLY) $(MONEYOBJ) hotdogstand.cpp -o $(HOTDOGSTANDOBJ)
#compile the money class
$(MONEYOBJ): money.hpp money.cpp
	$(CXX) $(CXXFLAGS) $(COMPILEONLY) money.cpp -o $(MONEYOBJ)
.PHONY: clean
#clean up all .exe or .o files 
clean:
	rm  -f *.o *.exe hw04
