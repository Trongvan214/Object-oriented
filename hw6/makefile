#Author: Trong Van
#Student ID: x454v285
#Programming Number: 6
#filename: makefile
#Description:  compile files 

	#COMPILE FLAGS#
CXX = g++ 
CXXFLAGS = -Wall -std=c++11

	#PROJECT FILES#
SRCDIR = src
SRCS = Ant.cpp Doodlebug.cpp Critter.cpp Grid.cpp main.cpp
INCL = Ant.hpp Doodlebug.hpp Critter.hpp Grid.hpp
OBJS = $(SRCS:%.cpp=%.o)
INCL := $(addprefix $(SRCDIR)/, $(INCL))
EXE = hw06

	#DEBUG BUILD#
DBGDIR = dbg
DBGOBJS = $(addprefix $(DBGDIR)/, $(OBJS))
DBGFLAGS = -g -O0
DBGEXE = $(DBGDIR)/$(EXE)

	#RELEASE BUILD#
RELDIR = rel
RELOBJS = $(addprefix $(RELDIR)/, $(OBJS))
RELEXE = $(RELDIR)/$(EXE)

.PHONY: all clean debug release prep

#
# 	DEFAULT BUILD
#
all: prep release


#
#	RELEASE RULES
#
release: $(RELEXE) $(INCL)

$(RELEXE): $(RELOBJS) 
	$(CXX) $(CXXFLAGS) -o $(RELEXE) $^

$(RELDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#
#	DEBUG RULES
#
debug: $(DBGEXE) $(INCL)

$(DBGEXE): $(DBGOBJS)
	$(CXX) $(CXXFLAGS) $(DBGFLAGS) -o $(DBGEXE) $^

$(DBGDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $(DBGFLAGS) -o $@ $<

#
#	PREP RULES
#
prep:
	@mkdir $(DBGDIR) $(RELDIR) > /dev/null 2>&1; true

#
#	CLEAN RULES
#
clean:
	rm -f $(RELEXE) $(RELOBJS) $(DBGEXE) $(DBGOBJS)
