#ifndef QUEUE_H
#define QUEUE_H
/**********************************************************************
FILE: Queue.h
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 04.12.16
PURPOSE: Declaration for the Queue class, representing a queue ADT. The class contains private data members to dynamically allocate a int array and store the size and capacity of this allocated array and the location of its front and back. Contains prototypes for a default constructor, copy constructor, destructor, and copy assignment operator. Class method prototypes to return the value of data members and manipulate the int array to behave as a queue ADT.  
************************************************************************/
#include <iostream>

using std::ostream;	//Using declaration for ostream

class Queue 
{			
	friend ostream& operator<<(ostream&, const Queue&);

	public:
		Queue();		//Default constructor
		Queue(const Queue&);	//Copy constructor 
		
		Queue& operator=(const Queue&);	//Copy assignment operator
	
		~Queue();		//Destructor

		size_t size() const;		//Access to queue size
		size_t capacity() const;	//Access to queue capacity
		int front() const;		//Access to front element	
		int back() const;		//Access to back element

		void clear();		//Resets to empty state
		bool empty() const;	//Checks if empty
		void push(int);		//Inserts item
		void pop();		//Removes item
		void reserve(size_t);	//Increases capacity

	private:
		int* qArray;	//Pointer to dynamically allocated array of integers
		size_t qSize;	//Number data items currently in the vector
		size_t qCap;	//Maximum number of elements in array
		int qFront;	//Location of front item in queue
		int qBack;	//Location of back item in queue
};

#endif
