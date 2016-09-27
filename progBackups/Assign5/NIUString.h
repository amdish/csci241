#ifndef NIUSTRING_H
#define NIUSTRING_H

/**********************************
FILE: NIUString.h
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 03/29/2016
PURPOSE: Declaration for the NIUString class, which contains private data members to dynamically allocate a char array and store the size and capacity of this allocated area. Contains prototypes for a default constructor, alternate constructor, copy constructor, and destructor. Class method prototypes to return the value of data members and to overload operators. Friend function prototypes are included for operators where the left operand is not a NIUString object. 
******************************************/

#include <cstdlib>
#include <iostream>

using namespace std;

class NIUString {

	//Friend declaration for overloaded operators(<< and ==)
	friend ostream& operator<<(ostream&, const NIUString&);		//Prints contents of object's char array
	friend bool operator==(const char*, const NIUString&);		//Compares a string and string of an object

	public:

		NIUString();			//Default Constructor
		NIUString(const char*);		//Alternate Constructor
		NIUString(const NIUString&);	//Copy Constructor

		NIUString(NIUString&&);			//Move Constructor
		NIUString& operator=(NIUString&&);	//Move assignment overload
		
		~NIUString();			//Class Destructor

		//Accessor methods		
		size_t capacity() const;	//Returns capacity of string array
		size_t size() const;		//Returns size of string array
		

		bool empty() const;		//Checks if string is empty
		void clear() ;			//Clears array
		void reserve(size_t);				

		//Operator overloading methods 
		bool operator==(const NIUString&) const;	//Overload == operator
		bool operator==(const char*) const;		//Overload == operator
		const char& operator[](size_t) const;		//Overload subscript operator 
		char& operator[](size_t);			//Overload subscript operator 
		NIUString& operator=(const NIUString&);		//Overload assignment operator
		NIUString& operator=(const char*);		//Overload assignment operator
	
	private:
		char* array;		//Dynamically allocated string array
		size_t strCap;		//String capacity
		size_t strSize;		//String size
};
#endif
