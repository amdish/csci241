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
	for (int count = 0; count < numRecords; count++)
	{
		records[count].print();
	}
}
