#ifndef QUICKSORT_H
#define QUICKSORT_H
/**********************************************************************
FILE: quicksort.h
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 04.26.16
PURPOSE: Includes declarations and definitions of functions to implement the standard quick sort algorithum through utlizing recursive calls and partitioning of the vector. 
************************************************************************/

//******************Function Prototypes*********************************
//**********************************************************************
template <class T> void quickSort (vector<T>& set, bool (*compare)(const T&, const T&));

template <class T> void quickSort (vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

template <class T> int partition (vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

/************************************************
Function: template <class T> void quickSort (vector<T>& set, bool (*compare)(const T&, const T&));
Use: Sorts the items in the vector using quick sort algo
Parameters:
(1) A reference to a vector object 
(2) Pointer to comparision function
Returns: Nothing
*************************************************/
template <class T> void quickSort (vector<T>& set, bool (*compare)(const T&, const T&))
{
	quickSort(set, 0, set.size()-1, compare);	//Recursive fx call
}

/************************************************
Function: template <class T> void quickSort (vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));
Use: Performs the recursive calls to implement the quick sort algo
Parameters:
(1) A reference to a vector object
(2) Subscript of first vector element
(3) Subscript of last vector element
(4) Pointer to comparision function
Returns: Nothing
*************************************************/
template <class T> void quickSort (vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
//Standard calls to implement quick sort algo

	int pivotPoint;		//Declare var to hold pivot point

	if (start < end)
	{
		pivotPoint = partition(set, start, end, compare);     // Get the pivot point
		quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
		quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
	}
}

/************************************************
Function: template <class T> int partition (vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));
Use: Partitions vector around the pivot.
Parameters:
(1) A reference to a vector object
(2) Subscript of first vector element
(3) Subscript of last vector element
(4) Pointer to comparision function
Returns: Nothing
*************************************************/
template <class T> int partition (vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
//Standard Partition Algorithum*******

	int pivotIndex, mid;
	T pivotValue;
   
	mid = (start + end) / 2;

	//Swap elements start and mid of the vector
	T tempVal;
	tempVal = set[mid];
	set[mid] = set[start];
	set[start] = tempVal;
 
	pivotIndex = start;
	pivotValue = set[start];
 
	for (int scan = start + 1; scan <= end; scan++)
	{
		if (compare(set[scan], pivotValue))
		{
			pivotIndex++;
			//Swap elements pivotIndex and scan of the vector
			T tempVal;
			tempVal = set[pivotIndex];
			set[pivotIndex] = set[scan];
			set[scan] = tempVal;
		}
	}
	
	//Swap elements start and pivotIndex of the vector
	tempVal = set[start];
	set[start] = set[pivotIndex];
	set[pivotIndex] = tempVal; 

	return pivotIndex; 
}
#endif
