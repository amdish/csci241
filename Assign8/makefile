#
#PROGRAM: Assignment 8 (assign8)
#PROGRAMMER: Amol Shah
#LOGON ID: z1723133
#DATE DUE: 04.26.16
#

#Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

assign8: assign8.o
	g++ $(CCFLAGS) -o assign8 assign8.o

#Rules to compile source code file to object code
assign8.o: assign8.cpp sorts.h quicksort.h mergesort.h
	g++ $(CCFLAGS) -c assign8.cpp

#Pseudo-target to remove object code executable files
clean:
	-rm *.o assign8

