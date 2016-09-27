/********************************************
FILE: Provider.cpp
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 02.23.2016
PURPOSE: Contains method definitions of Provider class, include the constructor, accessor methods for private data members and a print method to output all the data of a Provider class. 
*********************************************/
#include <iostream>
#include "Provider.h"

//Using declarations
using std::cout;
using std::endl;

Provider::Provider(){}	//Default Constructor
Provider::~Provider(){}	//Destructor

/***************************
Method: void print() const;
Use: Prints the data members of the class (Provider information) 
Parameters: None
Returns: Nothing
****************************/
void Provider::print() const
{
        cout << "#" << number << endl
        << name << endl 
        << specialty << endl
        << address1 << endl
        << address2 << endl
        << city << ", " << state << " " << zipCode << endl
        << phoneNumber << endl << endl;
}

/***************************
Method: const char* getProviderNumber() const;
Use: Accessor method for provider number
Parameters: None
Returns: const char pointer to provider number data member 
****************************/
const char* Provider::getProviderNumber() const
{
	return number;
}

/***************************
Method: const char* getSpecialty() const;
Use: Accessor method for provider specialty
Parameters: None
Returns: const char pointer to provider specialty data member
****************************/
const char* Provider::getSpecialty() const
{
	return specialty;
}

/***************************
Method: const char* getName() const;
Use: Accessor method for provider name 
Parameters: None
Returns: const char pointer to provider name data member
****************************/
const char* Provider::getName() const
{
	return name;
}
