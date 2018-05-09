#Filename: makefile
#Name: Trong Van
#WSUID: X454V285
#HW: extra credit 1
#Description: makefile to compile each piece and put them together

CXX = g++
CXXFLAGS = -Wall -c -std=c++11
SRCS = money.cpp businessfunctions.cpp hotdogstand.cpp program4.cpp
INCL = money.hpp businessfunctions.hpp hotdogstand.hpp 
OBJS = $(SRCS:%.cpp=%.o)
EXE = xc1

.PHONY: clean all

all: $(EXE)

$(EXE): $(OBJS) $(INCL)
	$(CXX) $(OBJS) -o $@

#all .cpp to .o
.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJS) core $(EXE) sim.txt 
