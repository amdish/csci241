/******************************************************
FILE: NIUString.cpp
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 03.29.16
PURPOSE: Contains definitions for the NIUString class. Contains a default constructor, alternate constructor, copy constructor, and move constructor(extra credit). To either initialize an empty object or dynamically allocate the correct amount of memory to store a argument string along with its size. Includes a destructor which deletes the memory allocated by calling the clear method. Contains methods and functions to overload operators. To compare, copy string, and move or delete objects. 
Extra Credit:
******************************************************/
#include "NIUString.h"

//****************CLASS CONSTRUCTORS*******************
/******************************************************
Default Constructor: NIUString();
Use: Initializes an "empty" object
Parameters: None
******************************************************/
NIUString::NIUString()
{
	//Initialize data members to empty/default status
	strSize = 0;
	strCap = 0;	
	array = nullptr;
}

/*****************************************************
Alternate Constructor: NIUString(const char*);
Use: Initializes object to argument string
Parameters: Pointer to char constant, representing an array of characters 
******************************************************/
NIUString::NIUString(const char* other)
{
	//Counts number of charecters in argument
	int count = 0;	
	while(other[count] != 0)
	{
		count++;
	}
	
	//If argument has no charecters, sets string array pointer to null.
	if (count <= 0) 
	{
		array = nullptr;
	}
	
	else
	{
		strSize = count;		//Sets array size to size of argument
		strCap = strSize;		//Sets array capacity to string size
		array = new char[count];	//Dynamically allocates enough mem to hold string from arg

		//Loop to copy argument to object's string array	
		for (size_t i = 0; i < strSize; i++)
		{
			array[i] = other[i];	
		}
	}
}

/*****************************************************
Copy Constructor: NIUString(const NIUString&);
Use: Copys argument object to calling object
Parameters: A NIUString object
*****************************************************/
NIUString::NIUString(const NIUString& other)
{
	strSize = other.strSize;	//Copies argument objects size to calling objects size 
	strCap = other.strCap;		//Copies argument objects capacity to calling objects capacity

	array = new char[strSize];	//Dynamically allocates enough mem to hold string from argument object	

	//Loop to copy argument object's string array to calling object
	for (size_t i = 0; i < strSize; i++)
	{
		array[i] = other.array[i];
	}
}

//Class Deconstructor***********************
NIUString::~NIUString()
{
	clear();	//Calls clear method
}

//**********************Overloading [] operator********************************
/****************************************************
Method: const char& operator[](size_t) const; 
Use: 
Parameters: A size_t, representing a location in the array
Returns: Element at location specified by parameter
****************************************/
const char& NIUString::operator[](size_t pos) const
{
	return array[pos];
}

/****************************************************
Method: char& operator[](size_t);
Use:
Parameters: A size_t variable, representing 
Returns: Element at location specified by parameter
****************************************/
char& NIUString::operator[](size_t pos)
{
	return array[pos];
}

//***********************Overloading = operator*********************************
/****************************************************
Method: NIUString& operator=(const NIUString&);
Use: Assigns one NIUString object to another
Parameters: A constant reference to a NIUString object
Returns: 
****************************************/
NIUString& NIUString::operator=(const NIUString& other)
{
	delete[] this->array;			
	this->strSize = other.strSize;
	this->strCap = other.strCap;
	
	this->array = new char[this->strCap];	//Dynamically allocates enough memory for arg string

	for (size_t i = 0; i < other.strSize; i++)
	{
		this->array[i] = other.array[i];	
	}
	return *this;
}

/****************************************************
Method: NIUString& operator=(const char*);
Use: 
Parameters: 
Returns: A reference to a NIUString object
****************************************/
NIUString& NIUString::operator=(const char* other)
{
	int count = 0;
	delete[] this->array;
	while(other[count] != 0){count++;}
	this->strSize = count;
	this->strCap = this->strSize;
	this->array = new char[this->strSize];
	for (size_t i = 0; i < strSize; i++)
	{
		this->array[i] = other[i];
	}
	return *this;
}

/****************************************************
Method: bool empty() const;
Use: Checks if a string is empty
Parameters: None
Returns: True if string size is 0. Otherwise false
****************************************/
bool NIUString::empty() const
{
	if (strSize == 0)
	{
		return true;
	} 
	else 
	{
		return false;
	}
}

//**************************Friend Functions****************************
/****************************************************
Function: friend ostream& operator<<(ostream&, const NIUString&);
Use: 
Parameters:
(1): Reference to a ostream object, representing the left operand of the stream insertion expression. 
(2): Reference to a constant NIUString object, representing the right operand of the expression.
Returns: A reference to an ostream object
****************************************/
ostream& operator<<(ostream& lhs, const NIUString& rhs)
{
	for (size_t i = 0; i < rhs.strSize; i++)
	{
		lhs << rhs.array[i];
	}
	return lhs;
}

/****************************************************
Function: friend bool operator==(const char*, const NIUString&);
Use: Compares a string and string of object
Parameters:
(1): A pointer to constant char, representing a string
(2): Reference to a constant NIUString object, representing the right operand of the expression.
Returns: True if the strings are same or else false
****************************************/
bool operator==(const char* other, const NIUString& rhs)
{
	//Counts number of charecters in lhs parameter
	size_t count = 0;
	while(other[count] != 0)
	{
		count++;
	}

	//Compares string sizes of parameters
	if (rhs.strSize != count)
	{
		return false;
	}
	else
	{
		//Loop to compare each charecter of parameters and return false if different
		for (size_t i = 0; i < rhs.strSize; i++)
		{
			if (other[i] != rhs.array[i])
			{
				return false;
			}
		}
		return true;	//Passed decision statement, therefore both are same
	}
}

//***************************************Operator == overloading*****************
/****************************************************
Method: bool operator==(const NIUString&) const;  
Use: Compares the string of the calling object to that of the argument object
Parameters: NIUString object
Returns: True if the string are same and false if different
****************************************/
bool NIUString::operator==(const NIUString& rhs) const
{
	if(this->strSize != rhs.strSize){return false;}
	else
	{
		for (size_t i = 0; i < rhs.strSize; i++)
		{
			if (this->array[i] != rhs.array[i])
			{
				return false;
			}
		}
		return true;
	}
}

/****************************************************
Method: bool operator==(const char*) const; 
Use: Compares the string of calling object to that of argument
Parameters: Pointer to constant char, representing a string
Returns: True if both are same
****************************************/
bool NIUString::operator ==(const char* other) const
{
	
	size_t count = 0;
	while(other[count] != 0)
		{	
			count++;
		}
	
	if (strSize != count)
	{
		return false;
	}
	else
	{
		for (size_t i = 0; i < strSize; i++)
		{
			if (array[i] != other[i])
			{
				return false;
			}
		}
		return true;
	}
}

/****************************************************
Method: void clear();
Use: Brings the object to a default state
Parameters: None
Returns: Nothing
****************************************/
void NIUString::clear() 
{
	//Sets object members to "empty"/null
	strSize = 0;	
	strCap = 0;
	delete[] array;
	array = nullptr;
}

/****************************************************
Method: size_t capacity() const;
Use: To access the capacity of the array 
Parameters: None
Returns: A size_t representing the maximum capacity of the array 
****************************************/
size_t NIUString::capacity() const
{
	return strCap;
}

/****************************************************
Method: size_t size() const;
Use: To access the size of the array
Parameters: None
Returns: A size_t representing the number of occupied elements in the array
****************************************/
size_t NIUString::size() const
{
	return strSize;
}

/****************************************************
Method: void reserve(size_t);
Use: 
Parameters: A size_t
Returns: Nothing
****************************************/
void NIUString::reserve(size_t n)
{
	if (n <= strSize){}
	else
	{
		strCap = n;
		char* tempPtr;
		tempPtr = new char[n];

		for (size_t i = 0; i < strSize; i++)
		{
			tempPtr[i] = array[i];
		}
		delete[] array;
		array = tempPtr;
	}
}


//MOVE CONSTRUCTORS
NIUString::NIUString (NIUString&& other) : array(NULL), strCap(0), strSize(0)
{
	strSize = other.strSize;
	strCap = other.strCap;
	array = other.array;

	other.array = nullptr;
	other.strSize = 0;
	other.strCap = 0;	
}
NIUString& NIUString::operator=(NIUString&& other)
{
	strSize = other.strSize;
	strCap = other.strCap;
	
	array = other.array;
	other.array = nullptr;
	
	other.strSize = 0;
	other.strCap = 0;
	
	return *this;
}
