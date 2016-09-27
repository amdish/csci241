/*****************************************************
FILE: Queue.cpp
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 04/12/2016
PURPOSE: Contains definitions for the queue class, which represents a queue ADT. Contains a default constructor, copy constructor, copy assignment, and destructor. Includes a destructor which deletes the memory allocated. The definitions represent an int array as a queue ADT and follow the existing rules of manipulating such a data type. These methods allow to add or remove an item from the queue, increase the queue capacity, return the front and rear data as well data members representing properties of the queue array. 
*****************************************************/
#include <stdexcept>
#include "Queue.h"

//****************Class Constructors*******************
/******************************************************
Default Constructor: Queue();
Use: Initializes an "empty" object.
Parameters: None
******************************************************/
Queue::Queue()
{
	//Sets array property data members to empty state
	qSize = 0;
	qCap = 0;
	qArray = nullptr;
	qFront = 0;
	qBack = qCap - 1;
}

/******************************************************
Copy Constructor: Queue(const Queue&);
Use: Copys argument object to calling object
Parameters: A reference to a constant Queue object
******************************************************/
Queue::Queue(const Queue& other)
{
	//Copy non-dynamic data members
	qCap = other.qCap;
	qSize = other.qSize;
	qFront = other.qFront;
	qBack = other.qBack;

	//Dynamically allocate enough memory to copy parameter array
	if (qCap == 0)
		qArray = nullptr;
	else
		qArray = new int[qCap];

	//Copy data of all elements from queue array
	for (size_t i = 0; i < qCap - 1; ++i)
		qArray[i] = other.qArray[i];
}

//*********************Class Deconstructor*************
/******************************************************
Queue Class Deconstructor: ~Queue();
Use: Deallocates dynamic memory used for storing array
******************************************************/
Queue::~Queue()
{
	delete [] qArray;	//Deletes dynamically allocated int array
}

//*******************Copy Assignment Operator*********
/*****************************************************
Method: Queue& operator=(const Queue&);
Use: Assigns one Queue object to another
Parameters: A reference to a constant Queue object
Returns: A reference to a Queue object
*****************************************************/
Queue& Queue::operator=(const Queue& other)
{
	//Checks for self assignment
	if (this != &other)
	{
		//Copy non-dynamic data members
		qCap = other.qCap;
		qSize = other.qSize;
		qFront = other.qFront;
		qBack = other.qBack;

		//Dynamically allocate enough memory to copy parameter array
		if (qCap == 0)
			qArray = nullptr;
		else
			qArray = new int[qCap];

		//Copy data of all elements from queue array
		for (size_t i = 0; i < qCap - 1; ++i)
			qArray[i] = other.qArray[i];
	}
	return *this;	//Return pointer to object
}

/*****************************************************
Method: void clear(); 
Use: Sets queue back to empty state
Parameters: None
Returns: Nothing
*****************************************************/
void Queue::clear()
{
	//Set queue property data members to empty state
	qSize = 0;
	qFront = 0;
	qBack = qCap - 1;
}

/*****************************************************
Method: size_t size() const;
Use: Accessor method to queue size
Parameters: None
Returns: A size_t, representing the queue size
*****************************************************/
size_t Queue::size() const
{
	return qSize;
}

/*****************************************************
Method: size_t capacity() const;
Use: Accessor method to queue capacity 
Parameters: None
Returns: A size_t, representing the queue capacity
*****************************************************/
size_t Queue::capacity() const
{
	return qCap;
}

/*****************************************************
Method: bool empty() const;
Use: Check if object's queue array is empty
Parameters: None
Returns: A boolean, representing true if queue size is 0. Otherwise, false.
*****************************************************/
bool Queue::empty() const
{
	//Checks if queue is empty
	if (qSize == 0)
		return true;
	else 
		return false;
}

/*****************************************************
Method: int front() const;
Use: Access to front item in queue
Parameters: None
Returns: An integer, representing the front element of the queue array
*****************************************************/
int Queue::front() const
{
	//Throw exception if queue is empty or returns data in front element
	if (qSize == 0)
		throw std::underflow_error("queue underflow on front()");
	else
		return qArray[qFront];
}

/*****************************************************
Method: int back() const;
Use: Access to back item in queue 
Parameters: None
Returns: An integer, representing the back element of the queue array
*****************************************************/
int Queue::back() const
{
	//Throw exception if queue is empty or returns data in back element
	if (qSize == 0)
		throw std::underflow_error("queue underflow on back()");
	else
		return qArray[qBack];
}

/*****************************************************
Method: void push(int);
Use: Inserts data to back of queue, if the queue is full appropriately increases its size by calling the reserve method.
Parameters: An integer, representing the data to insert into the queue
Returns: Nothing
*****************************************************/
void Queue::push(int newItem)
{
	//Increases array capacity if neccessary
	if (qSize == qCap)
	{
		if (qCap == 0)
			reserve(1);
		else
			reserve(qCap * 2);
	}

	qBack = (qBack + 1) % qCap;	//Moves back subscript clockwise one element
	qArray[qBack] = newItem;	//Assigns argument data to back of queue
	++qSize;			//Increases queue size data member	
}

/*****************************************************
Method: void pop();
Use: Removes front item in the queue
Parameters: None
Returns: Nothing
*****************************************************/
void Queue::pop()
{
	//Throw exception if queue is empty, otherwise remove front item
	if (qSize == 0)
		throw std::underflow_error("queue underflow on pop()");	
	else
	{	
		qFront = (qFront + 1) % qCap;	//Moves front subscript counter-clockwise one element
		--qSize;			//Decreases queue size data member
	}
}

/*****************************************************
Method: void reserve(size_t);
Use: To increase the capacity of the int array without changing its size
Parameters: An unsigned int, representing the increased array capacity
Returns: Nothing
*****************************************************/
void Queue::reserve(size_t n)
{
	//Increases capacity if argument is greater than queue capacity
	if (n > qCap)
	{	
		int* tempQ = new int[n];	//Dynamically allocates memory for  larger array
		
		//Copies entire queue array
		int current = qFront;
		for (size_t i = 0; i < qSize; i++)
		{
			tempQ[i] = qArray[current];
			current = (current + 1) % qCap;
		}

		qCap = n;		//Sets queue capacity to argument value
		qFront = 0;		//Sets front subscript
		qBack = qSize -1;	//Sets back subscript
		delete[] qArray;	//Delete dynamically allocated memory of old array
		qArray = tempQ;		//Assigns temp pointer to object data member pointer
	}
}

//**************************Friend Functions****************
/***********************************************************
Function: friend ostream& operator<<(ostream&, const Queue&);
Use: Prints data from elements of rhs parameter, object's int array
Parameters:
(1): Reference to a ostream object, representing the left operand of the stream insertion expression.
(2): Reference to a constant Queue object, representing the right operand of the expression.
Returns: A reference to an ostream object
***********************************************************/
ostream& operator<<(ostream& lhs, const Queue& rhs)
{	
	size_t current, i;

	//Loops through data of queue array	
	for (current = rhs.qFront, i = 0; i < rhs.qSize; ++i)
	{	
		//Prints queue element at subscript i
		lhs << rhs.qArray[current] << ' ';
		
		//Increment i, wrapping around to front of queue array is necessary
		current = (current + 1) % rhs.qCap;
	}
	return lhs;
}
