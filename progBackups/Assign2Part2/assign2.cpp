/**/
#include <string>
#include "ProviderDB.h"
#include <iostream>
//#include "Provider.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
	string fileName = "providerdb";
	
	ProviderDB pDatabase = ProviderDB(fileName.c_str());

	pDatabase.print();
	
	pDatabase.sortByProviderNumber();
	pDatabase.print();

	pDatabase.sortBySpecialty();
	pDatabase.print();

	pDatabase.sortByName();
	pDatabase.print();
	
	return 0;
}
