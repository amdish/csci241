#
#PROGRAM: Assignment 2 (assign2)
#PROGRAMMER: Amol Shah 
#LOGON ID: z1723133
#DATE DUE: 02.16.16
#

#Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

#Rule to link object code files to create executable file
assign2: assign2.o Provider.o ProviderDB.o
	g++ $(CCFLAGS) -o assign2 assign2.o Provider.o ProviderDB.o

#Rule to compile source code file to object code
assign2.o: assign2.cpp ProviderDB.h
	g++ $(CCFLAGS) -c assign2.cpp

#Rule to compile source code file to object code
Provider.o: Provider.cpp Provider.h
	g++ $(CCFLAGS) -c Provider.cpp

#Rule to compile source code file to object code
ProviderDB.o: ProviderDB.cpp ProviderDB.h
	g++ $(CCFLAGS) -c ProviderDB.cpp

#Header file dependency
ProviderDB.h: Provider.h

#Pseudo-target to remove object code executable files
clean:
	-rm *.o assign2





