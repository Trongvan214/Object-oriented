#Filename: makefile
#Name: Trong Van
#WSUID: X454V285
#HW: 3
#Description: makefile to compile each piece and put them together

#compile the final code and run it 
hw03: hotdogstand.o money.o myawesomebusiness.o program3.o 
	g++ -Wall hotdogstand.o money.o myawesomebusiness.o program3.o -o hw03
	./hw03
#compile the program 
program3.o: myawesomebusiness.o program3.cpp 
	g++ -Wall -c program3.cpp -o program3.o
#compile the namespace 
myawesomebusiness.o: myawesomebusiness.hpp myawesomebusiness.cpp hotdogstand.hpp
	g++ -Wall -c myawesomebusiness.cpp -o myawesomebusiness.o
#compile the hotdogstand class
hotdogstand.o: hotdogstand.cpp hotdogstand.hpp money.o
	g++ -Wall -c hotdogstand.cpp -o hotdogstand.o
#compile the money class
money.o: money.cpp money.hpp
	g++ -Wall -c money.cpp -o money.o
#clean up all .exe or .o files 
clean:
	rm  -f *.o *.exe
