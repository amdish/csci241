#
#PROGRAM: Assignment 1 (assign1)
#PROGRAMMER: Amol Shah 
#LOGON ID: z1723133
#DATE DUE: 02.09.16
#

#Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

#Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.o

#Rule to compile source code file to object code
assign1.o: assign1.cpp
	g++ $(CCFLAGS) -c assign1.cpp

#Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign1


