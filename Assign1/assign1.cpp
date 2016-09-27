/*****************************************************************************************
CSCI 241 | Assignment 1 | (Spring 2016)
Programmer: Amol Shah
Z-ID: z1723133
Section: 1
TA: Ashish Kharde
Date Due: 02.09.16
Purpose: The goal of this program is to read a file of records into an array of objects, then loop through the array and print the objects.Takes a comma separated values file with provider information as input and using class methods stores fields of each line into appropriate data member then uses class method to print the array of objects. 
Input: A file "providers.csv" that contains information about a provider on each line.
Output: The entire array of objects, which is data from each provider class, includes: provider number, specialty, name, address information(title,street,city,state,zipcode) and phone number.
******************************************************************************************/
	//Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

	//Using declarations
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::strcpy;
using std::strlen;

	//Provider class, data from one record (HMO provider)
class Provider 
{
	//Private class data members for provider information
	private:
		char number[7]={'\0'};
		char specialty[41]={'\0'};
		char name[41] = {'\0'};
		char address1[41] = {'\0'} ;
		char address2[31] = {'\0'};
		char city[21] = {'\0'};
		char state[3] = {'\0'};
		char zipCode[6] = {'\0'};
		char phoneNumber[15] = {'\0'};
	
	//Public methods
	public:
		Provider();	//Constructor function
		~Provider();	//Destructor function
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
		void print();	//Print method to output data members of class
};

const int MAX_SIZE = 40; //Symbolic constant for maximum array size

//Function prototype, returns int, #elements used in array. Reads in fields of provider information from input file and calls set methods to assign data to data members in elements of Provider array
int read(Provider[]);

//Function prototype, cycles through array and prints data stored in valid elements of array
void cycleArray(int, Provider[]);

int main()
{
	Provider records[MAX_SIZE];	//Declares and initializes array of Provider objects
	int size;			//Variable to store number of valid elements used in array

	size = read(records);		//Read input file and assign size of array
	cycleArray(size, records);    

	return 0;
}

Provider::Provider(){}	//Default Constructor Method
Provider::~Provider(){}	//Class Destructor

/*****************************CLASS METHODS************/
/*****************************
Method: void setNumber;
Use: Copies char pointer parameter to class data member using strcpy function. To store field from input file into appropriate data member
Parameters: One argument: a pointer to a char array that represents a field of provider information from the input stream of file
Returns: Nothing
*/
void Provider::setNumber(const char* newNumber)
{
	strcpy(number,newNumber);
}

/*****************************
Method: void setSpecialty
Use: Copies char pointer parameter to class data member using strcpy function. To store field from input file into appropriate data member
Parameters: One argument: a pointer to a char array that represents a field of provider information from the input stream of file
Returns: Nothing 
*/
void Provider::setSpecialty(const char* newSpecialty)
{
	strcpy(specialty,newSpecialty);
}

/*****************************
Method: void setName
Use: Copies char pointer parameter to class data member using strcpy function. To store field from input file into appropriate data member
Parameters: One argument: a pointer to a char array that represents a field of provider information from the input stream of file
Returns: Nothing
*/
void Provider::setName(const char* newName)
{
	strcpy(name,newName);
}

/*****************************
Method: void setAddress1
Use: Copies char pointer parameter to class data member using strcpy function. To store field from input file into appropriate data member
Parameters: One argument: a pointer to a char array that represents a field of provider information from the input stream of file
Returns: Nothing
*/
void Provider::setAddress1(const char* newAddress1)
{
	strcpy(address1,newAddress1);
}

/*****************************
Method: void setAddress2
Use: Copies char pointer parameter to class data member using strcpy function. To store field from input file into appropriate data member
Parameters: One argument: a pointer to a char array that represents a field of provider information from the input stream of file
Returns: Nothing
*/
void Provider::setAddress2(const char*newAddress2)
{
	strcpy(address2,newAddress2);
}

/*****************************
Method: void setCity
Use: Copies char pointer parameter to class data member using strcpy function. To store field from input file into appropriate data member
Parameters: One argument: a pointer to a char array that represents a field of provider information from the input stream of file
Returns: Nothing
*/
void Provider::setCity(const char* newCity)
{
	strcpy(city,newCity);
}

/*****************************
Method: void setState
Use: Copies char pointer parameter to class data member using strcpy function. To store field from input file into appropriate data member
Parameters: One argument: a pointer to a char array that represents a field of provider information from the input stream of file
Returns: Nothing
*/
void Provider::setState(const char* newState)
{
	strcpy(state,newState);
}

/*****************************
Method: void setZipCode
Use: Copies char pointer parameter to class data member using strcpy function. To store field from input file into appropriate data member
Parameters: One argument: a pointer to a char array that represents a field of provider information from the input stream of file
Returns: Nothing
*/
void Provider::setZipCode(const char* newZipCode)
{
	strcpy(zipCode,newZipCode);
}

/*****************************
Method: void setPhoneNumber
Use: Copies char pointer parameter to class data member using strcpy function. To store field from input file into appropriate data member
Parameters: One argument: a pointer to a char array that represents a field of provider information from the input stream of file
Returns: Nothing
*/
void Provider::setPhoneNumber(const char* newPhoneNumber)
{
	strcpy(phoneNumber,newPhoneNumber);
}

/*****************************
Method: void print
Use: Prints the contents of the data members of the object.
Parameters: None
Returns: Nothing
*/
void Provider::print()
{
	cout << "#" << number << endl
	<< name << endl
	<< specialty << endl
	<< address1 << endl
	<< address2 << endl
	<< city << ", " << state << " " << zipCode << endl
	<< phoneNumber << endl << endl;
}

/**************************FUNCTIONS*********************
Function: int read
Use: Reads in the input file and calls set methods to assign field from input stream to appropriate data members
Parameters: Array of objects(Provider class)
Returns: Number of elements utilized in array
*/
int read(Provider records[])
{
	//Declare string variables
	string
	providerNumber,
	specialty,
	lastName,
	firstName,
	middle,
	title,
	address1,
	address2,
	city,
	state,
	zipCode,
	phoneNumber,
	fullName;
	int count = 0;		//Variable to keep count of records
	ifstream inFile;	//Declares input file variable

	//Opens the file
	inFile.open("providers.csv");
	
	//Decision statement to display error if not opened
	if(!inFile)
	{			
		cout <<"Error: Unable to open input file\n";
		exit(1);
	}
	
	//While loop to read in lines of file using getline function until end of file is reached
	//Loop contains getline functions for each field of provider information
	//Concatenates parts of name into one string
	//It passes the string as a cstring to the set method for the data member of class Provider
	while(getline(inFile, providerNumber, ','))
	{
		//Getline functions to assign fields from input to string
		getline(inFile, specialty, ',');
		getline(inFile, lastName, ',');
		getline(inFile, firstName, ',');
		getline(inFile,middle,',');
		getline(inFile,title,',');

		//Concotanates and formats full name
		//Decision statement to check if middle initial should be concatanated 
		if (strlen(middle.c_str()) == 0)
			fullName = lastName + ", " + firstName + ", " + title;
		else
			fullName = lastName + ", " + firstName + " " + middle + ", " + title;

		getline(inFile,address1,',');
		getline(inFile,address2,',');
		getline(inFile,city,',');
		getline(inFile,state,',');
		getline(inFile,zipCode,',');
		getline(inFile,phoneNumber);

		//Calls to set methods to assign data to class data members
		records[count].setNumber(providerNumber.c_str());
		records[count].setSpecialty(specialty.c_str());
		records[count].setName(fullName.c_str());
		records[count].setAddress1(address1.c_str());
		records[count].setAddress2(address2.c_str());
		records[count].setCity(city.c_str());
		records[count].setState(state.c_str());
		records[count].setZipCode(zipCode.c_str());
		records[count].setPhoneNumber(phoneNumber.c_str());

		count++;	//Increments record count
	}
	inFile.close();	//Closes file

	return count;	//Return total number of records read in from input file
}

/*****************************
Function: void cycleArray
Use: Cycles through valid elements of array of objects and prints the contents of the data members of each object.
Parameters: 2 arguments; an int representing the number of valid elements, and an array of class Provider
Returns: Nothing
*/
void cycleArray(int arraySize, Provider records[])
{
        for (int i = 0; i < arraySize; i++)
        {
                records[i].print();
        }
}
