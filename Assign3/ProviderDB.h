#ifndef PROVIDERDB_H
#define PROVIDERDB_H
/**********************************
FILE: ProviderDB.h
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 02/23/2016
PURPOSE: Declaration for the ProviderDB class, which represents a database of provider objects. Method prototypes for insertion sort, and prototypes for non-class comparision functions. This is the same as assignment 2, except includes method declarations for additional methods, used to process a input transactions file, process different types of transactions, and search for various transactions. 
******************************************/
#include "Provider.h"
#include <string>

using std::string;

const int MAX_SIZE = 40;	//Maximum Number of Providers

//ProviderDB class declaration
class ProviderDB
{
	//Private data members
	private:
		Provider records[MAX_SIZE];
		int numProviders = 0;

	public:
		ProviderDB();		  //Constructor
		~ProviderDB();		  //Destructor
		ProviderDB(const char*);  //Alternate Constructer

		void printDB() const;	  //Prints Provider database
	
		//Assignment 3 Method declarations for processing and searching
		void processTransactions(const char*);			
		int searchForProviderNumber(const char*) const;	
		int searchForSpecialty(const char*) const;

		//Assignment 3 Method declarations for transaction types
		void transactionAll();			
		void transactionSpecialty(const char*);
		void transactionNumber(const char*);
	
		//Insertion Sort method prototype with function pointer declaration
		void sort(bool(*compare)(const Provider&, const Provider&));		
};
		//Compare function prototypes
		bool ascendingNumber(const Provider&, const Provider&);
		bool descendingSpecialty(const Provider&, const Provider&);
		bool ascendingName(const Provider&, const Provider&);

#endif
