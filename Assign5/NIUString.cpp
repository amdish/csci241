/**********************************************************************
FILE: NIUString.cpp
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 03.29.16
PURPOSE: Contains definitions for the NIUString class. Contains a default constructor, alternate constructor, copy constructor, and move constructor(extra credit). To either initialize an empty object or dynamically allocate the enough memory to hold the parameter string along with its size. Includes a destructor which deletes the memory allocated by calling the clear method. Contains methods and functions to overload operators. To compare, copy string, and move or delete objects. 
Extra Credit: Implements move semantics using a move constructor and move assignment operator. The purpose of this is to write more efficient programs that don't waste resources creating temp copies. 
************************************************************************/
#include "NIUString.h"

//****************Class Constructors*******************
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
Use: Initializes object to parameter string
Parameters: Pointer to char constant, representing an array of characters 
******************************************************/
NIUString::NIUString(const char* other)
{
	//Counts number of characters in parameter string
	int count = 0;	
	while(other[count] != 0)
		count++;
	
	strSize = count;	//Sets string size data member to number of charecters in parameter string 
	strCap = strSize;	//Sets string capacity data member to string size

	//If parameter string has no charecters, sets object's string array pointer to null.
	if (strCap == 0) 
		array = nullptr;

	//Otherwise, dynamically allocates enough mem to hold parameter string
	else
		array = new char[strCap];	
	
	//Loop to copy each element of parameter string to object's string array	
	for (size_t i = 0; i < strSize; i++)
	{
		array[i] = other[i];	
	}
}

/******************************************************
Copy Constructor: NIUString(const NIUString&);
Use: Copys argument object to calling object
Parameters: A reference to a constant NIUString object
******************************************************/
NIUString::NIUString(const NIUString& other)
{
	strSize = other.strSize;	//Copies parameter object's size to calling object's size data member
	strCap = other.strCap;		//Copies parameter object's capacity to calling object's capacity data member

	//If parameter object's string has no charecters, sets calling object's string array pointer to null.
	if (strCap == 0)
		array = nullptr;

	//Otherwise, Dynamically allocates enough mem to hold parameter object's string array
	else
		array = new char[strCap];		

	//Loop to copy parameter object's string array to calling object's string array
	for (size_t i = 0; i < strSize; i++)
	{
		array[i] = other.array[i];
	}
}

//*********************Class Deconstructor*************
/******************************************************
NIUString Deconstructor: ~NIUString();
Use: Deallocates dynamic memory used for storing string array
******************************************************/
NIUString::~NIUString()
{
	clear();	//Calls clear method
}

//********************************Overloading = operator***********************
/*****************************************************
Method: NIUString& operator=(const NIUString&);
Use: Assigns one NIUString object to another
Parameters: A reference to a constant NIUString object
Returns: A reference to a NIUString object
*****************************************************/
NIUString& NIUString::operator=(const NIUString& other)
{
	//Checks for self assignment
	if(this != &other)
	{
		delete[] this->array;		//Deallocates memory pointed to by string array of calling object		
		this->strSize = other.strSize;	//Sets calling objects size data member to parameter's value
		this->strCap = other.strCap;	//Sets calling objects size data member to parameter's value
	
		//Sets calling object's string array pointer to null for empty string
		if (this->strCap == 0)
			array = nullptr;
		
		//Otherwise, Dynamically allocates enough mem to hold parameter object's string array
		else
			this->array = new char[this->strCap];	

		//Loop to copy parameter object's string array to calling object
		for (size_t i = 0; i < this->strSize; i++)
		{
			this->array[i] = other.array[i];	
		}
	}
	return *this;
}

/*****************************************************
Method: NIUString& operator=(const char*);
Use: Assigns the string in the parameter to the calling object's string array
Parameters: Pointer to a char constant, representing a array of chars
Returns: A reference to a NIUString object
******************************************************/
NIUString& NIUString::operator=(const char* other)
{
	delete[] this->array;	//Deallocates memory pointed to by string array of calling object	
	
	//Counts number of charecters in parameter string
	int count = 0;
	while(other[count] != 0)
		count++;

	this->strSize = count;		//Assigns calling objects size to size of parameter string
	this->strCap = this->strSize; 	//String cap is same as string size

	//Sets array to nullptr if parameter string is empty
	if (this->strCap == 0)
		this->array = nullptr;

	//Otherwise, dynamically allocates enough mem to hold number of charecters in  parameter string 
	else
		this->array = new char[this->strCap];	

	//Loop to copy parameter string array to calling object's string array
	for (size_t i = 0; i < this->strSize; i++)
	{
		this->array[i] = other[i];
	}
	return *this;
}

/*****************************************************
Method: size_t capacity() const;
Use: To access the string capacity data member of the object
Parameters: None
Returns: A size_t representing the capacity of the array
******************************************************/
size_t NIUString::capacity() const
{
     return strCap;
}

/*****************************************************
Method: size_t size() const;
Use: To access the string size datamember of the object
Parameters: None
Returns: A size_t, representing the number of occupied elements in the array
******************************************************/
size_t NIUString::size() const
{
     return strSize;
}

/*****************************************************
Method: bool empty() const;
Use: Checks if a objects string array is empty
Parameters: None
Returns: True if string array is empty. Otherwise false
******************************************************/
bool NIUString::empty() const
{
	//Checks size of string to determine if empty
	if (strSize == 0)
		return true;
	else 
		return false;
}

/*****************************************************
Method: void clear();
Use: Brings the object to a default state
Parameters: None
Returns: Nothing
******************************************************/
void NIUString::clear()
{
     //Sets object members to "empty"/null
     strSize = 0;
     strCap = 0;
     delete[] array;	//Deallocates dynamic memory used for string array
     array = nullptr;	//Sets char pointer to nullptr/0
}

/*****************************************************
Method: void reserve(size_t);
Use: Modifies an objects string capacity without changing its size or contents of string array
Parameters: A size_t
Returns: Nothing
******************************************************/
void NIUString::reserve(size_t n)
{
     //Does nothing if n is less than/equal to string size or equal to string cap
     //Otherwise changes string capacity
     if (n > strSize && n != strCap)
     {
          strCap = n;		//Sets string capacity to parameter n
          char* tempPtr;	//Temporary pointer to a char

          //Sets tempPtr to nullptr if parameter n is zero
          if (strCap == 0)
          	tempPtr = nullptr;

          //Otherwise, dynamically allocates enough memory to hold n characters
          else
               tempPtr = new char[strCap];   

          //Loop to copy string array of calling object to temp array
          for (size_t i = 0; i < strSize; i++)
          {
               tempPtr[i] = array[i];
          }

          delete[] array;	//Deallocates dynamic memory used for string array
          array = tempPtr;	//Sets string array pointer to temporary array pointer
     }
}

//********************************Operator == overloading**********************
/******************************************************
Method: bool operator==(const NIUString&) const;
Use: Compares the string of the calling object to that of the parameter object
Parameters: A reference to a constant NIUString object
Returns: True if strings are same and false if different
******************************************************/
bool NIUString::operator==(const NIUString& rhs) const
{
     //Checks if strings are different sizes
     if(strSize != rhs.strSize) 
          return false;

     //Otherwise, compares each respective element of the parameters string arrays
     else
     {
          //Loop to compare each charecter of string in parameter object and calling object
          //Returns false if a charecter is found to be different
          for (size_t i = 0; i < strSize; i++)
          {
               if (array[i] != rhs.array[i])
               {
                    return false;
               }
          }
          return true;   //Passed compare loop, therefore both are same
     }
}

/*****************************************************
Method: bool operator==(const char*) const;
Use: Compares the string of calling object to that of argument
Parameters: Pointer to constant char, representing a string
Returns: True if both are same
******************************************************/
bool NIUString::operator==(const char* other) const
{
     //Counts number of characters in parameter string
     size_t count = 0;
     while(other[count] != 0)
               count++;

     //Checks if strings are different sizes
     if (strSize != count)
          return false;

     //Otherwise, compares each respective element of the string arrays
     else
     {
          //Loop to compare each charecter in parameter string and calling object
          //Returns false if a charecter is found to be different
          for (size_t i = 0; i < strSize; i++)
          {
               if (array[i] != other[i])
               {
                    return false;
               }
          }
          return true;	//Passed compare loop, therefore both are same
     }
}

//**********************Overloading [] operator********************************
/*****************************************************
Method: const char& operator[](size_t) const;
Use: Overloads subscript operator for reading purposes
Parameters: A size_t, representing a location in the string array
Returns: Element in location specified by parameter
*******************************************************/
const char& NIUString::operator[](size_t pos) const
{
     return array[pos];
}

/******************************************************
Method: char& operator[](size_t);
Use: Overloads subscript operator for writing purposes
Parameters: A size_t variable, representing a location in the string array
Returns: Element in location specified by parameter
******************************************************/
char& NIUString::operator[](size_t pos)
{
     return array[pos];
}

//***********************************Friend Functions**************************
/***********************************************************
Function: friend ostream& operator<<(ostream&, const NIUString&);
Use: Prints each charecter of rhs parameter, object's string array
Parameters:
(1): Reference to a ostream object, representing the left operand of the stream insertion expression. 
(2): Reference to a constant NIUString object, representing the right operand of the expression.
Returns: A reference to an ostream object
***********************************************************/
ostream& operator<<(ostream& lhs, const NIUString& rhs)
{
	//Loops through each element of array
	for (size_t i = 0; i < rhs.strSize; i++)
	{
		lhs << rhs.array[i];	//Cascades output to stream object
	}
	return lhs;		//Returns output stream object
}

/*****************************************************
Function: friend bool operator==(const char*, const NIUString&);
Use: Compares a string and string of object
Parameters:
(1): A pointer to constant char, representing a string
(2): Reference to a constant NIUString object, representing the right operand of the expression.
Returns: True if the strings are same or else false
*******************************************************/
bool operator==(const char* lhs, const NIUString& rhs)
{
	//Counts number of charecters in lhs parameter
	size_t count = 0;
	while(lhs[count] != 0)
		count++;

	//Compares string sizes of lhs and rhs parameters, false if different
	if (rhs.strSize != count)
		return false;

	//Otherwise, compares each respective element of the parameters string array
	else
	{
		//Loop to compare each charecter of parameters string array
		//Returns false if different
		for (size_t i = 0; i < rhs.strSize; i++)
		{
			if (lhs[i] != rhs.array[i])
			{
				return false;
			}
		}
		return true;	//Passed compare loop, therefore both are same
	}
}

//********************************Extra Credit: Move Semantics******************
/*****************************************************
Move Constructor: NIUString(NIUString&&);
Use: Moves data of source object to new object 
Parameters: rvalue reference to NIUString class
Returns: Nothing
******************************************************/
NIUString::NIUString (NIUString&& other) : array(NULL), strCap(0), strSize(0)
{
	//Assigns class data members from source object to the one being constructed
	strSize = other.strSize;
	strCap = other.strCap;
	array = other.array;

	//Sets source object to default status
	other.strSize = 0;
	other.strCap = 0;	
	other.array = nullptr;
}

/*****************************************************
Move Assignment Operator: NIUString& operator=(NIUString&&);
Use: Overloaded assignment operator to move objects without creating temp copies
Parameters: rvalue refernce to NIUString class
Returns: A reference to a NIUString class
******************************************************/
NIUString& NIUString::operator=(NIUString&& other)
{
	//Checks for self assignment
	if (this != &other)
	{
		delete[] array;		//Delete existing dyanmic memory of calling objects string array

		//Assigns class data members from source object to calling object
		strSize = other.strSize;
		strCap = other.strCap;
		array = other.array;

		//Sets source object to default status
		other.strSize = 0;
		other.strCap = 0;
		other.array = nullptr;
	}
	return *this;
}
