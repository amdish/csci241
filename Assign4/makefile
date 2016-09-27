#
#PROGRAM: Assignment 4 (assign4)
#PROGRAMMER: Amol Shah 
#LOGON ID: z1723133
#DATE DUE: 03.10.16
#

#Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

#Rule to link object code files to create executable file
assign4: assign4.o Matrix.o 
	g++ $(CCFLAGS) -o assign4 assign4.o Matrix.o 

#Rules to compile source code file to object code
assign4.o: assign4.cpp Matrix.h 
	g++ $(CCFLAGS) -c assign4.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ $(CCFLAGS) -c Matrix.cpp

#Pseudo-target to remove object code executable files
clean:
	-rm *.o assign4
