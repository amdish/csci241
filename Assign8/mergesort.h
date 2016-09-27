#ifndef MERGESORT_H
#define MERGESORT_H
/**********************************************************************
FILE: mergesort.h
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 04.26.16
PURPOSE: Declarations and definitions for various template functions to sort a list of items using the recursive merge sort algorithm. 
************************************************************************/

//*******************Function Prototypes********************************
//**********************************************************************
template <class T> void mergeSort (vector<T>& set, bool (*compare)(const T&, const T&));

template <class T> void mergeSort (vector<T>& set, int low, int high, bool (*compare)(const T&, const T&));

template <class T> void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&));

/************************************************
Function: template <class T> void mergeSort (vector<T>& set, bool (*compare)(const T&, const T&));
Use: Sorts items in the vector by making recursive calls to the merge sort fx
Parameters: 
(1) A reference to a vector object
(2) Subscript of the first vector element
(3) Subscript of the last vector element
Returns: Nothing
*************************************************/
template <class T> void mergeSort (vector<T>& set, bool (*compare)(const T&, const T&))
{
	mergeSort (set, 0, set.size()-1, compare);	//Recursive fx call
}

/************************************************
Function: template <class T> void mergeSort (vector<T>& set, int low, int high, bool (*compare)(const T&, const T&));
Use: A recursive fx that divides a vector into two subvectors, sorts them, and then merges the two sorted subvectors
Parameters:
(1) A reference to a vector object
(2) Start of left sorted subvector
(3) Start of right sorted subvector
(4) Pointer to a compare function
Returns: Nothing
*************************************************/
template <class T> void mergeSort (vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{
//Standard Algo to divide vector into two subvectors*******

	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		//Divide and conquer

		mergeSort (set, low, mid, compare);
		mergeSort (set, mid+1, high, compare);

		//Combine
		merge (set, low, mid, high, compare);
	}
}

/************************************************
Function: template <class T> void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&)); 
Use: Merges two sorted subvectors
Parameters:
(1) A reference to a vector object
(2) Start of left sorted subvector
(3) Start of right sorted subvector
(4) Pointer to a compare function
Returns: Nothing
*************************************************/
template <class T> void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{
//Standard Merge Sort Algo

	// Create temporary vector to hold merged subvectors
	vector<T> temp(high - low + 1);

	int i = low;      // Subscript for start of left sorted subvector
	int j = mid+1;    // Subscript for start of right sorted subvector
	int k = 0;        // Subscript for start of merged vector

	// While not at the end of either subvector
	while (i <= mid && j <= high)
	{
		if (compare(set[j], set[i]))
		{
			temp[k] = set[j];
			j++;
			k++;
		}
		else
		{
			temp[k] = set[i];
			i++;
			k++;
		}
	}

	// Copy over any remaining elements of left subvector
	while (i <= mid)
	{
		temp[k] = set[i];
		i++;
		k++;
	}

	// Copy over any remaining elements of right subvector
	while (j <= high)
	{
		temp[k] = set[j];
		j++;
		k++;
	}

	// Copy merged elements back into original vector
	for (i = 0, j = low; j <= high; i++, j++)
		set[j] = temp[i];
}
#endif
