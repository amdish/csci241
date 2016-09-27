#ifndef SORTS_H
#define SORTS_H
/**********************************************************************
FILE: sorts.h 
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 04.26.16
PURPOSE: Declaration and definition of a pair of template functions to read a series of items from an input file, and then print the items.
************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;
using std::cout;
using std::setw;
using std::ifstream;

//*********************Function Prototypes**********
template <class T> void buildList(vector<T>&, const char*);

template <class T> void printList(const vector<T>&, int, int);

template <class T> bool lessThan (const T& item1, const T& item2);

template <class T> bool greaterThan (const T& item1, const T& item2);

/************************************************
Function: template <class T> void buildList(vector<T>&, const char*);
Use: Stores data from an input file to a vector
Parameters:
(1) A reference to a vector object
(2) A pointer to char array, representing the filename 
Returns: Nothing
*************************************************/
template <class T> void buildList(vector<T>& set, const char* fileName)
{
	T item;			//Declare variable of data type T
	ifstream inFile;	//Declare input stream variable

	inFile.open(fileName);	//Open file for input

	//Displays error if file not opened
	if (!inFile)
	{
		cout << "Error: Unable to open input file\n";
		exit(1);
	}

	//Reads in data until end of file
	while (inFile >> item)
	{
		set.push_back(item);
	}
	inFile.close();	//Close file stream 
}

/************************************************
Function: template <class T> void printList(const vector<T>&, int, int); 
Use: Prints the contents of the vector created from the input file
Parameters:
(1) A reference to a vector object
(2) An int, representing # of spaces to allocate in output for single data item
(3) An int, representing the number of fields per row
Returns: Nothing
*************************************************/		
template <class T> void printList (const vector<T>& set, int itemWidth, int numPerLine)
{
	int count = 0;	//Declare and initilize to keep count of num printed

	//Loop to keep printing until end of vector
	while (count < (int) set.size())
	{
		//Cycles through each row
		for (int i = 0; i < (int)set.size(); i+=numPerLine)
		{
			//Prints fields of each row
			for (int i = 0; i < numPerLine && count < (int)set.size(); i++)
			{
				//Output formatted, based on arguments
				cout << setw(itemWidth) << set[count];	
				count++;
			}
			cout << endl;
		}
	}
}

/************************************************
Function: template <class T> bool lessThan (const T& item1, const T& item2);
Use: Compares arg1 vs arg2
Parameters:
(1) A reference to an item of data type T
(2) A reference to an item of data type T
Returns: True if arg1 is less than arg2, otherwise false
*************************************************/
template <class T> bool lessThan (const T& item1, const T& item2)
{
	return (item1 < item2);
}

/************************************************
Function: template <class T> bool greaterThan (const T& item1, const T& item2);
Use: Compares arg1 vs arg2
Parameters:
(1) A reference to an item of data type T
(2) A reference to an item of data type T
Returns: True if arg1 is greater than arg2, otherwise false 
*************************************************/
template <class T> bool greaterThan (const T& item1, const T& item2)
{
	return (item1 > item2);
}
#endif
