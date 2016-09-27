/***************************************************
CSCI 241 | Assignment 3 | (Spring 2016)
Programmer: Amol Shah
Z-ID: z1723133
Section: 1
TA: Ashish Kharde
LOGON ID: z1723133
DUE DATE: 02.23.16
PURPOSE: Main function utilized to call class constructors and various sort methods with a pointer function indicating the way to sort the provider information based on one data member. Organizes output in three ways; Ascending by number, descending by specialty, and ascending by name
INPUT: A file in binary format with Provider information and a file of transaction records
OUTPUT: Depends on the input file of transaction records, but in general will print; database sorted in ascending order by name, the result of a provider number query, or a total count and list of matching specialities. 
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
	//Declare and initialize string for file names
	string fileName = "providerdb";
	string transactionsFile = "transactions.txt";

	//Call alternate constructor, builds Provider database from binary input file 
	ProviderDB providerDatabase = ProviderDB(fileName.c_str());

	//Call to process transactions in transaction records input file
	providerDatabase.processTransactions(transactionsFile.c_str());

	return 0;
}
