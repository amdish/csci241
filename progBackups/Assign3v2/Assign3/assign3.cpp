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
	
	//Declare and initialize string for file name
	string fileName = "providerdb";
	string transactionsFile = "transactions.txt";

	//Call alternate constructor, builds Provider database from binary input file 
	ProviderDB providerDatabase = ProviderDB(fileName.c_str());

	//Call to process transactions method with file name passed as C string
	providerDatabase.processTransactions(transactionsFile.c_str());


/*	providerDatabase.sort(&ascendingNumber);
	string searchFor;
	cout << "ENTER PROVIDER NUMBER TO SEARCH FOR: ";
	cin>>searchFor;
	inRecord = providerDatabase.searchForProviderNumber(searchFor);
	if (inRecord==-1)
		cout <<"Provider Number Not Found"<<endl;
	else
		cout << "FOUND AAAT RECORD " <<inRecord<<endl; */

	return 0;
}
