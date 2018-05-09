#Author: Trong Van
#Student ID: x454v285
#Programming Number: 5
#filename: makefile
#Description:  compile files 

CXX = g++ 
CXXFLAGS = -Wall -std=c++11 -g
EXE = hw05
SRCDIR = src
SRCS = PFAString.cpp main.cpp
INCL = PFAString.hpp testFuncs.hpp test_interface.hpp
INCL := $(addprefix $(SRCDIR)/, $(INCL))
OBJS = $(SRCS:%.cpp=%.o)
OBJS := $(addprefix $(SRCDIR)/, $(OBJS))

.PHONY : all clean
all : $(EXE) $(INCL)

$(EXE) : $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(EXE) $^

$(SRCDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS) core $(EXE)
