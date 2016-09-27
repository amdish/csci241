/*Provider source code*/

#include <iostream>
#include "Provider.h"

using std::cout;
using std::endl;

//Default Constructor
Provider::Provider(){}

/*****************************
Method: void print
Use: Prints the contents of the data members of the object.
Parameters: None
Returns: Nothing
*/
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

const char* Provider::getProviderNumber()
{
	return number;
}

const char* Provider::getSpecialty()
{
	return specialty;
}

const char* Provider::getName()
{
	return name;
}
