#include <iostream>
#include <fstream>
#include <cstring>
#include "ProviderDB.h"


using std::cout;
using std::endl;
using std::ifstream;
using std::ios;

ProviderDB::ProviderDB(){}

ProviderDB::ProviderDB(const char* fileName)
{
	ifstream inFile;
	
	if(!inFile)
	{
		cout << "Error opening file" << endl;	
		exit(1);
	}
	
	inFile.open(fileName, ios::binary);
	inFile.read((char*) this, sizeof(ProviderDB));
}

void ProviderDB::print() const 
{
	cout << "----------Health Care Provider Information----------" << endl;
	for (int count = 0; count < numProviders; count++)
	{
		records[count].print();
	}
}

void ProviderDB::sortByProviderNumber(){
	
	int i, j;
	Provider bucket;

	for (i = 1; i < numProviders; i++)
	{
		bucket = records[i];

		for (j = i; (j > 0) && (strcmp(records[j-1].getProviderNumber(), bucket.getProviderNumber()) > 0); j--)
			records[j] = records[j-1];

		records[j] = bucket;
	}}

void ProviderDB::sortBySpecialty()
{
	int i, j;
	Provider bucket;
	
	for (i = numProviders - 1; i >= 0; i--)
	{
		bucket = records[i];
		
		for (j = i; (j < numProviders) && (strcmp(records[j+1].getSpecialty(), bucket.getSpecialty()) > 0); j++)
			records[j] = records[j+1];

		records[j] = bucket;
	}	
}		

void ProviderDB::sortByName()
{
	cout << "--------SORTING BY NAME---------" << endl;	
	
	int i, j;
	Provider bucket;
	
	for (i = 1; i < numProviders; i++)
	{
		bucket = records[i];

		for (j = i; (j > 0) && (strcmp(records[j-1].getName(), bucket.getName()) > 0); j--)
			records[j] = records[j-1];

		records[j] = bucket;
	}	
}
