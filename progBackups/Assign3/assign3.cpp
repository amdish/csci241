/***************************************************
CSCI 241 | Assignment 3 | (Spring 2016)
Programmer: Amol Shah
Z-ID: z1723133
Section: 1
TA: Ashish Kharde
LOGON ID: z1723133
DUE DATE: 02.23.16
PURPOSE: Main function utilized to call class constructors and various sort methods with a pointer function indicating the way to sort the provider information based on one data member. Organizes output in three ways; Ascending by number, descending by specialty, and ascending by name
Input: A file in binary format with Provider information
Output: Prints the data members of each provider from provider database in unsorted, ascending by number, descending by specialty, and ascending by name order.  
EXTRA CREDIT: The extra credit portion uses function pointers and eliminates redundant code for the insertion sort algorithum. The appropriate compare function is called using reference.
****************************************************/
#include <iostream>
#include <string>
#include "ProviderDB.h"

//Using delclarations
using std::cout;
using std::endl;
using std::string;
using std::cin;

int main()
{
	string searchFor;
	
	//Declare and initialize string for file name
	string fileName = "providerdb";
	string transactionsFile = "transactions.txt";

	//Call alternate constructor, builds Provider database from binary input file 
	ProviderDB providerDatabase = ProviderDB(fileName.c_str());

	cout << "________________________UNSORTED_____________________" << endl;
//	providerDatabase.printDB();
	providerDatabase.sort(&ascendingNumber);
	providerDatabase.printDB();

	cout << "ENTER PROVIDER NUMBER TO SEARCH FOR: ";
	cin>>searchFor;

	providerDatabase.searchForProviderNumber(searchFor);

//	providerDatabase.processTransactions(transactionsFile.c_str());
/*
	//Call to sort method using function pointer to sort objects in ascending order by name
	cout << "-----------Ascending By Provider Number________" << endl;
        providerDatabase.sort(&ascendingNumber);
        providerDatabase.printDB();

	//Call to sort method using function pointer to sort objects in descending order by specialty
	cout << "___________Descending By Provider Specialty________" << endl;
        providerDatabase.sort(&descendingSpecialty);
        providerDatabase.printDB();

	//Call to sort method using function pointer to sort objects in ascending order by name
	cout << "___________Ascending By Provider Name________" << endl;
        providerDatabase.sort(&ascendingName);
        providerDatabase.printDB();
*/
	return 0;
}
