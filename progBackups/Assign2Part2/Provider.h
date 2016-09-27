#ifndef PROVIDER_H
#define PROVIDER_H

/**************************************************************
FILE:	Provider.h
AUTHOR:	Amol Shah
LOGON ID: z1723133
DUE DATE: 02/16/2016
PURPOSE: Declaration for the Provider class, which represents information about a health care provider.
*************************************************/

class Provider
{
	private:
		char number[7] = {'\0'};
		char specialty[41] = {'\0'};
		char name[41] = {'\0'};
		char address1[41] = {'\0'};
		char address2[31] = {'\0'};
		char city[21] = {'\0'};
		char state[3] = {'\0'};
		char zipCode[6] = {'\0'};
		char phoneNumber[15] = {'\0'};
	public:
		Provider();	//Constructor function
//		~Provider();	//Destructor function

			//Public get methods 				
		const char* getProviderNumber();
		const char* getSpecialty();
		const char* getName();

			//Public set methods to assign to data members
		void setNumber(const char*);
		void setSpecialty(const char*);
		void setName(const char*);
		void setAddress1(const char*);
		void setAddress2(const char*);
		void setCity(const char*);
		void setState(const char*);
		void setZipCode(const char*);
		void setPhoneNumber(const char*);
		void print() const; //Print method to output data members of class
};

#endif



