#ifndef QUEUE_H
#define QUEUE_H
/**********************************************************************
FILE: Queue.h
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 04.19.16
PURPOSE: Declaration and definition for the Queue class, representing a queue ADT using a singly-linked list. The class utilizes templates in order to provide versatility in the data types used. The class contains private data members to dynamically allocate a int array and store the size and capacity of this allocated array and the location of its front and back. Contains prototypes for a default constructor, copy constructor, destructor, and copy assignment operator. Class method prototypes to return the value of data members and manipulate the int array to behave as a queue ADT represented as a singly-linked list. 
************************************************************************/
#include <iostream>
#include <stdexcept>

//Node struct, representing items/nodes of the singly linked list
template <class T>
struct Node {
	T data;		//Item to be inserted
	Node<T> *next;	//Pointer to the next node
	Node(const T& = T(), Node<T>* next = nullptr);
};

//Node Constructor
template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext)
{
	data = newData;	//Assigns data 
	next = newNext;	//Assigns pointer of next node. 
}

//Forward declaration of the Queue template class
template <class T>
class Queue;

//Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

//Queue class
template <class T>
class Queue {

	//Overloading stream << operator
	friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);

	public:
		Queue();		//Default Constructor
		~Queue();		//Destructor
		Queue(const Queue<T>&);	//Copy Constructor
		Queue<T>& operator=(const Queue<T>&);	//Copy Assignment Operator

		size_t size() const;	//Access to queue size
		bool empty() const;	//Checks if empty
		void clear();		//Resets to empty state
		T front() const;	//Access to front element
		T back() const;		//Access to back element
		void push(const T&);	//Inserts item
		void pop();		//Removes item
		void copyList(const Queue&);	//Copies list
	private:
		Node<T> * qFront;	//Front of list
		Node<T> * qBack;	//Back of list
		size_t qSize;		//Size of list
		T *qList;		//Dynamically allocated memory to array
};

//****************Class Constructors*******************
/******************************************************
Default Constructor: Queue();
Use: Initializes an "empty" object.
Parameters: None
******************************************************/
template <class T>
Queue<T>::Queue()
{
	//Set memebers to default state
	qFront = qBack = nullptr;	
	qSize = 0;				
}

/******************************************************
Copy Constructor: Queue(const Queue<T>&);
Use: Copys argument object to calling object
Parameters: A reference to a constant Queue object
******************************************************/
template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
	//Sets new queue to default state
	qFront = qBack = nullptr;
	qSize = 0;
	copyList(other);	//Call copy method
}

//*********************Class Destructor*************
/******************************************************
Queue Class Deconstructor: ~Queue();
Use: Deallocates dynamic memory used for storing array
******************************************************/
template <class T>
Queue<T>::~Queue()
{
	clear();
}
//*******************Copy Assignment Operator*********
/*****************************************************
Method: Queue& operator=(const Queue&);
Use: Assigns one Queue object to another
Parameters: A reference to a constant Queue object
Returns: A reference to a Queue object
*****************************************************/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	//Checks for self-assignment
	if (this != &other)
	{	
		clear();		//Delete existing associated memory
		copyList(other);	//Copies argument to calling object
	}
	return *this;	//Returns object
}

/*****************************************************
Method: void clear();
Use: Sets queue back to empty state
Parameters: None
Returns: Nothing
*****************************************************/
template <class T>
void Queue<T>::clear()
{ 
	//Set members back to default state
	qFront = qBack = nullptr;	
	qSize = 0;      		
}

/*****************************************************
Method: size_t size() const;
Use: Accessor method to queue size
Parameters: None
Returns: A size_t, representing the queue size
*****************************************************/
template <class T>
size_t Queue<T>::size() const
{
        return qSize;
}

/*****************************************************
Method: bool empty() const;
Use: Check if object's queue array is empty
Parameters: None
Returns: A boolean, representing true if queue size is 0. Otherwise, false.
*****************************************************/
template <class T>
bool Queue<T>::empty() const
{
        //Returns true if queue is empty otherwise returns false
        if (qSize == 0)
                return true;
        else
                return false;
}

/*****************************************************
Method: T front() const;
Use: Stores location of item at front of list
Parameters: None
Returns: A Queue object/node, representing the first item in the linked list
*****************************************************/
template <class T>
T Queue<T>::front() const
{
	//Exception handling, throw exception if empty
	//Otherwise, returns data at front of list
	if (qSize == 0)
		throw std::underflow_error("queue underflow on front()");
	else
		return qFront->data;
}

/*****************************************************
Method: T back() const;
Use: Stores location of item at back/end of list
Parameters: None
Returns: A Queue object/node, representing the last item in the linked list
*****************************************************/
template <class T>
T Queue<T>::back() const
{
	//Exception handling, throw except if empty
	//Otherwise, returns data at end of list
	if (qSize == 0)
		throw std::underflow_error("queue underflow on back()");
	else
		return qBack->data;
}

/*****************************************************
Method: void push(const T&);
Use: To insert the parameter item at end of list and incr qsize
Parameters: A reference to a constant item of the template parameter type
Returns: Nothing
*****************************************************/
template <class T>
void Queue<T>::push(const T& item)
{
	Node<T>* newNode = new Node<T>(item);	//Assign argument to new node

	//Inserts new node appropriatley based on current list size
	if (qSize == 0)
		qFront = newNode;
	else
		qBack->next = newNode;

	qBack = newNode;	//Assigns newnode to qBack	
	qSize++;		//Increment queue size 
}

/*****************************************************
Method: void pop();
Use: To insert the parameter item at end of list and incr qsize
Parameters: None 
Returns: Nothing
*****************************************************/
template <class T>
void Queue<T>::pop()
{
	//Throw exception if empty
	//Otherwise remove item at front of list
	if (qSize == 0)
		throw std::underflow_error("queue underflow on pop()");
	Node<T>* delNode = qFront;
	qFront = qFront->next;		//Changes front of list identifier

	//If list becomes empty sets pointers to default state
	if (qFront == nullptr)
		qBack = nullptr;
	
	delete delNode;		//Delete memory associated with first node
	qSize--;		//Decrement list size by 1
}

/*****************************************************
Method: friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);
Use: Prints the entire queue
Parameters:
(1): Reference to a ostream object, representing the left operand of the stream insertion expression.
(2): Reference to the queue, representing the right operand of the expression.
Returns: A reference to an ostream object
*****************************************************/
template <class T>
std::ostream& operator<< (std::ostream& lhs, const Queue<T>& rhs)
{
	Node<T>* ptr;	//Pointer to keep track of nodes

	//Loops through list until the end is reached
	//Cascades output into lhs
	for (ptr = rhs.qFront; ptr != nullptr; ptr = ptr->next)
		lhs << ptr->data << ' ';
	return lhs;
}

/*****************************************************
Method: void copyList(const Queue&); 
Use: Copy queue linked list from one to the other
Parameters:
(1): Queue object representing the left operand using this.
(2): Reference to the queue, representing the right operand of the expression.
Returns: Nothing
*****************************************************/
template <class T>
void Queue<T>::copyList(const Queue<T>& other)
{
	Node<T>* ptr;	//Create new node pointer
	for (ptr = other.qFront; ptr != nullptr; ptr = ptr->next)
		push(ptr->data);	//Use push to copy data
}
#endif

