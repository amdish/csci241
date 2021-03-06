/****************************************************
FILE: ProviderDB.cpp
AUTHOR: Amol Shah
LOGON ID: z1723133 
DUE DATE: 02.23.16
PURPOSE: This assignment builds upon assignment 2. It adds methods to process a transactions file and other methods that are called based on the contents of the input file. The methods added include those for various transaction types (all, specialty, and number), a method utilizing the binary search algorthum, and a method to search, print, keep count of a specific specialty found in the provider database. 
****************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include "ProviderDB.h"

//Using declarations
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::string;
using std::ws;
using std::setw;
using std::setfill;
using std::right;

//**********************CLASS METHODS****************
//******************ASSIGNMENT 3 METHODS*************
/****************************************************
Method: void processTransactions(const char*);
Use: Process transaction information in input file
Parameters: const char pointer, points to char array of file name containing transaction records
Returns: Nothing
****************************************/
void ProviderDB::processTransactions(const char* fileName)
{
	//Declare input stream variable for transactions file
        ifstream transactionsFile;	
	
	//Declare variable to hold info about a transaction 
	string transType;        
	string transSpecialty;
	string transNumber;	

        //Open file 
        transactionsFile.open(fileName);

        //Display error if file does not open
        if(!transactionsFile)
        {       
                cout << "Error opening file" << endl;
                exit(1);
        }

	//Loop to read contents until end of file
	while(transactionsFile >> transType && !transactionsFile.eof())
	{
		//Output the transaction type read in from input file
		cout << setw(70) << setfill('*') << "" << endl;
		cout << setw(50) << setfill('>') << right << "TRANSACTION TYPE: " << transType << endl;
		cout << setw(70) << setfill('*') << "" << endl;

		//Decision statements for transaction type and calls appropriate method
		if (strcmp(transType.c_str(), "all") == 0)
		{
			transactionAll();				//Call method for "all" transaction type
		}	
		else if (strcmp(transType.c_str(), "specialty") == 0)
		{
			transactionsFile >> ws;				//Remove white space
			getline(transactionsFile, transSpecialty);	//Read and assign specialty type
			transactionSpecialty(transSpecialty.c_str());	//Call method for "specialty" transaction
		}	
		else if (strcmp(transType.c_str(), "number") == 0)
		{
			transactionsFile >> transNumber;		//Read number from transaction record
			transactionNumber(transNumber.c_str());		//Call method for "number" transaction
		}
		else
			cout << "Invalid transactions type" << endl;

		cout << endl << endl;
	}
        //Closes file stream
        transactionsFile.close();	
}

/****************************************************
Method: void transactionAll(const char*);
Use: Calls methods to sort the database ascending by name and prints sorted database
Parameters: None
Returns: Nothing
****************************************/
void ProviderDB::transactionAll() 
{
	cout << "~~~~Sorting Provider Database (ascending by name)" << endl;

	sort(&ascendingName);	//Calls insertion sort method
	printDB();		//Prints sorted database
}

/****************************************************
Method: void transactionSpecialty(const char*);
Use: Calls methods to sort records database (descending by specialty) and search for a specific specialty
Parameters: const char pointer, points to char array of specialty to search for
Returns: Nothing
****************************************/
void ProviderDB::transactionSpecialty(const char* inSpecialty)
{
	int numResults;		//Variable to hold total found returned from search method

	cout << "~~~~Providers that specialize in " << inSpecialty << ":" << endl << endl;		
	
	sort(&descendingSpecialty);			//Call to insertion sort algorithum
	numResults = searchForSpecialty(inSpecialty);	//Searches and prints specialties that match argument
	
	//Decision statement to output total found or none
	if (numResults > 0)
		cout << "~~~~Total number of providers that specialize in " << inSpecialty << ": " << numResults << endl; 
	else
		cout << "****Found no results of providers specializing in " << inSpecialty << endl;
}

/****************************************************
Method: void transactionNumber(const char*);
Use: Calls methods to sort records database(ascending by #) and search for number in database
Parameters: const char pointer, points to char array of number to search for
Returns: Nothing
****************************************/
void ProviderDB::transactionNumber(const char* inNumber)
{
	int recordNumber;	//Variable to store location of matching number

	sort(&ascendingNumber);	//Calls insertion sort algorithum

	cout << "~~~~Result for provider number: " << inNumber << endl << endl;

	//Searches for provider number and stores location of matching object
	recordNumber = searchForProviderNumber(inNumber);

	//Decision statement to print matching provider or no results
	if (recordNumber != -1)
		records[recordNumber].print();
	else
		cout << "****Provider Number " << inNumber << " not found in provider database" << endl;
}

/****************************************************
Method: void searchForProviderNumber(const char*) const;
Use: Implements the binary search algorithum to search database for a matching provider number
Parameters: const char pointer, points to char array of number to search for
Returns: An interger, the element of array(provider object)  where number was found. Or -1 if no results
****************************************/
int ProviderDB::searchForProviderNumber(const char* searchNumber) const
{
	//Binary Search Algorithum Variables
	int low = 0;
	int high = numProviders - 1;
	int mid;

	//Standard Binary Search Algorithum
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (strcmp(searchNumber, records[mid].getProviderNumber()) == 0)
		{	
			return mid;
		}
		else if (strcmp(searchNumber, records[mid].getProviderNumber()) < 0)
		{
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return -1;
}

/****************************************************
Method: void searchForSpecialty(const char*) const;
Use: Search records database for a specific specialty, prints object and keeps count
Parameters: const char pointer, points to char array of specialty to search for
Returns: An interger, total number of providers with specialty found.
****************************************/
int ProviderDB::searchForSpecialty(const char* searchSpecialty) const
{
	int count = 0;		//Variable to keep total number found

	//Loop to cycle through array of providers and print objects that match the argument
	for (int i = 0; i < numProviders; i++)
	{
		if (strcmp(searchSpecialty,records[i].getSpecialty())==0)
		{
			records[i].print();
			count++;
		}
	}
	return count;		//Returns total number of providers with matching specialty
}


//***************************************************
//****************ASSIGNMENT 2 METHODS***************
ProviderDB::ProviderDB(){} 	//Default Constructor
ProviderDB::~ProviderDB(){}	//Destructor

/****************************************************
Method: ProviderDB(const char*);
Use: Alternate constructor to build provider database
Parameters: const char pointer, points to char array of file name
Returns: Nothing
****************************************/
ProviderDB::ProviderDB(const char* fileName)
{
	//Declare input stream variable 
       	ifstream inFile;

	//Open file for input as binary data and read data
        inFile.open(fileName, ios::binary);
	
	//Display error if file not opened
        if(!inFile)
        {
                cout << "Error opening file" << endl;
                exit(1);
        }

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
        cout << "__________________Health Care Provider Listing___________________" << endl;

	//Loop to print provider objects from Provider database
	for (int count = 0; count < numProviders; count++)
        {
              records[count].print();
        }
	cout << "|||---------------------END OF PROVIDER DATABASE--------------------|||" << endl;
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
