#ifndef PROVIDERDB_H
#define PROVIDERDB_H

/**********************************
FILE: ProviderDB.h
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 02/16/2016
PURPOSE: Declaration for the ProviderDB class, which represents a database of provider information. 
******************************************/

#include "Provider.h"

const int MAX_SIZE = 40;

class ProviderDB
{
	private:
		Provider records[MAX_SIZE];
		int numProviders = 0;

	public:
		ProviderDB();
		ProviderDB(const char*);

		void sortByProviderNumber();	
		void sortBySpecialty();
		void sortByName();
		void print() const;
};

#endif
