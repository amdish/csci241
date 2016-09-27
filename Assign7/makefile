#
#PROGRAM: Assignment 7 (assign7)
#PROGRAMMER: Amol Shah
#LOGON ID: z1723133
#DATE DUE: 04.19.16
#

#Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

assign7: assign7.o
	g++ $(CCFLAGS) -o assign7 assign7.o

#Rules to compile source code file to object code
assign7.o: assign7.cpp Queue.h
	g++ $(CCFLAGS) -c assign7.cpp

#Pseudo-target to remove object code executable files
clean:
	-rm *.o assign7

