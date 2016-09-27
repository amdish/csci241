/****************************************************
FILE: ProviderDB.cpp
AUTHOR: Amol Shah
LOGON ID: z1723133 
DUE DATE: 02.16.16
PURPOSE: Method definitions for ProviderDB class. Includes, constructor, alternate constructor that reads binary input, sort method using the insertion sort algorithum, and method to output all information in all objects of database.
EXTRA CREDIT: Removed redundant code of insertion sort algorithum and used a pointer to a compare function in the sort method. This uses non-class functions to arrange the the objects based on number(ascending), specialty(descending), and name(ascending). 
****************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include "ProviderDB.h"
#include <string>

//Using declarations
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::string;
using std::ws;

//**********************CLASS METHODS****************

ProviderDB::ProviderDB(){} 	//Default Constructor
ProviderDB::~ProviderDB(){}	//Destructor

void ProviderDB::processTransactions(const char* fileName)
{
        ifstream transactionsFile;
	string transType;        
	string transSpecialty;
	string transNumber;	

        //Open file 
        transactionsFile.open(fileName);

        //Display error if file not opened
        if(!transactionsFile)
        {       
                cout << "Error opening file" << endl;
                exit(1);
        }

	while(!transactionsFile.eof())
	{
		transactionsFile >> transType;
		cout << "Read in Trans Type: " << transType << endl;

		if (strcmp(transType.c_str(), "all")==0)
		{
			sort(&ascendingName);
			cout << "Sorted by name" << endl;		
		}	
		else if (strcmp(transType.c_str(), "specialty")==0)
		{
			transactionsFile >> ws;
			getline(transactionsFile, transSpecialty);
			sort(&descendingSpecialty);
			cout << "Sorted by specialty" << endl;
		}
		else if (strcmp(transType.c_str(), "number")==0)
		{
			transactionsFile >> transNumber;
			cout << "\nRead in trans#: " << transNumber;
			sort(&ascendingNumber);
			printDB();
			searchForProviderNumber(transNumber);
			cout << "Sorted by number" << endl;
		}
	}

        //Closes file stream
        transactionsFile.close();	
}

int ProviderDB::searchForProviderNumber(string inNumber)
{
	int low, mid, high;
	high = numProviders-1;
	low = 0;
	mid = high / 2;
	
	cout << "---INITIAL VALUES---" <<endl;
	cout <<"LOW: " <<low<<endl;
	cout<<"MID: " <<mid<<endl;
	cout<<"HIGH: " <<high<<endl;

	while (1){
        if(strcmp(inNumber.c_str(), records[mid].getProviderNumber()) == 0)
        {
                cout << "Found 1 at Record: " <<mid<<endl;
        	break;
	}	
	else if (strcmp(inNumber.c_str(), records[mid].getProviderNumber()) > 0)
	{

		cout << ">>IN NUMBER: " <<inNumber.c_str() << ">than " << records[mid].getProviderNumber()<<endl;	
		low = mid;
		mid = (high - low)/2+low;
		cout <<"LOW: " <<low<<endl;
		cout <<"MID: " <<mid<<endl;
		cout <<"HIGH:: " <<high<<endl;
	
		if ((high - mid)/2 ==0)
		{
			if(strcmp(inNumber.c_str(),records[high].getProviderNumber())==0)
			{
				cout<<"FFOUND AT RECORD: " <<high<<endl;
			}
			else cout <<"NOT FOUND"<<endl;
			break;
		}
	}	

	else if(strcmp(inNumber.c_str(),records[mid].getProviderNumber())<0)
	{
		cout <<"<<IN NUMBER: "<<inNumber.c_str()<<"<than " <<records[mid].getProviderNumber()<<endl;
		high = mid;
		mid = (high-low) / 2+low;
		cout <<"LOW: "<<low<<endl;
		cout <<"MID: "<<mid<<endl;
		cout <<"HIGH: " <<high<<endl;
		
		if((high-mid)==0)
		{
			cout<<"Number not found"<<endl;
			break;}
	}
	else
		cout<<"Provider Number not Found"<<endl;
	}
}

/****************************************
Method: ProviderDB(const char*);
Use: Alternate constructor to build provider database
Parameters: const char pointer, points to char array of file name
Returns: Nothing
****************************************/
ProviderDB::ProviderDB(const char* fileName)
{
	//Declare input stream variable 
       	ifstream inFile;

	//Display error if file not opened
        if(!inFile)
        {
                cout << "Error opening file" << endl;
                exit(1);
        }

	//Open file for input as binary data and read data
        inFile.open(fileName, ios::binary);
        inFile.read((char*) this, sizeof(ProviderDB));
	
	//Closes file stream
	inFile.close();
}

/****************************************
Method: printDB() const;
Use: Prints each valid object (Provider class) from provider database
Parameters: None
Returns: Nothing
****************************************/
void ProviderDB::printDB() const
{
        cout << "|||________Health Care Provider Listing________|||" << endl;

	//Loop to print provider objects from Provider database
	for (int count = 0; count < numProviders; count++)
        {
		cout << "Record #: " << count<<endl;  
              records[count].print();
        }
}

/****************************************
Method: void sort(bool(*compare)(const Provider&, const Provider&));
Use: Uses insertion sort algorithum use to organize data in Provider database. Has a pointer to a comparision function, which can be used to sort by a specific data member in ascending or descending order.
Parameters: Pointer to compare function
Returns: Nothing
****************************************/
void ProviderDB::sort(bool(*compare)(const Provider&, const Provider&))
{
 	//Declare variables
        int i, j;
        Provider bucket;

	//Standard insertion sort algorithum
        for (i = 1; i < numProviders; i++)
        {
                bucket = records[i];

		//Uses function pointer compare to sort based on call
                for (j = i; (j > 0) && (compare(records[j-1], bucket) > 0); j--)
                        records[j] = records[j-1];

                records[j] = bucket;
        }
}

//**********************EXTRA CREDIT*****************
//*******************NON-CLASS FUNCTIONS*************
/***************************************
Function: bool ascendingNumber(const Provider&, const Provider&);
Use: Used to sort objects in ascending order by number
Parameters: Two Provider objects
Returns: True: if parameter 1 > parameter 2. False: if parameter 1 < parameter 2
****************************************/
bool ascendingNumber(const Provider& s1, const Provider& s2)
{
	return (strcmp(s1.getProviderNumber(), s2.getProviderNumber()) > 0);
}

/****************************************
Function: bool descendingSpecialty(const Provider&, const Provider&);
Use: Used to sort objects in descending order by specialty
Parameters: Two Provider objects
Returns: True: if parameter 2 > parameter 1. False: if parameter 2 < parameter 1
****************************************/
bool descendingSpecialty(const Provider& s1, const Provider& s2)
{
        return (strcmp(s2.getSpecialty(), s1.getSpecialty()) > 0);
}

/****************************************
Function: bool ascendingName(const Provider&, const Provider&);
Use: Used to sort objects in ascending order by name
Parameters: Two Provider objects
Returns: True: if parameter 1 > parameter 2. False: if parameter 1 < parameter 2
****************************************/
bool ascendingName(const Provider& s1, const Provider& s2)
{
        return (strcmp(s1.getName(), s2.getName()) > 0);
}
