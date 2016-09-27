#
#PROGRAM: Assignment 9 (assign9)
#PROGRAMMER: Amol Shah
#LOGON ID: z1723133
#DATE DUE: 05.02.16
#

#Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

assign9: assign9.o
	g++ $(CCFLAGS) -o assign9 assign9.o

#Rules to compile source code file to object code
assign9.o: assign9.cpp shape.h circle.h rectangle.h triangle.h 
	g++ $(CCFLAGS) -c assign9.cpp

#Pseudo-target to remove object code executable files
clean:
	-rm *.o assign9

