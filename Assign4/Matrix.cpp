/****************************************************
FILE: Matrix.cpp
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 03.10.16
PURPOSE: Contains definitions for the Matrix class. Constructors to initialize object as "identity matrix"(main diagonal = 1), orinitializing the array with values of a passed in array, calculating the detriment and class methods to overload operators(+,*,==,!=). Function definitions for overloading operators where lhs is not class object for (*) and (<<) operators.  
****************************************************/
#include <iostream>
#include "Matrix.h"

//******************CLASS CONSTRUCTORS***************
/****************************************************
Default Constructor: Matrix();
Use: Initilizes identity matrix (main diagonal = 1 all others = 0)
Parameters: None
****************************************/
Matrix::Matrix()
{
	//Loop to initialize identity matrix. Main diagonal = 1
	//Outerloop to loop through rows
	for (int r = 0; r < 2; r++)
	{
		//Innerloop to loop through each column of row	
		for (int c = 0; c < 2; c++)
		{	
			//Sets element to one if in diagonal or zero if not.
			if (r == c)
				matrixArray[r][c] = 1;
			else 
				matrixArray[r][c] = 0;
		}
	}
}

/****************************************************
Array Initilization Constructor: Matrix(int[2][2]);
Use: Set elements of class matrix array to parameter matrix array
Parameters: A two-dimensional array of integers with two rows and two columns
****************************************/
Matrix::Matrix(int inMatrix[2][2])
{
	//Loop to copy elements of parameter matrix to class matrix
	//Outerloop to loop through rows
	for (int r = 0; r < 2; r++)
	{
		//Innerloop to loop through each column of row
		for (int c = 0; c < 2; c++)
		{
			//Sets class datamember element to parameters element
			matrixArray[r][c] = inMatrix[r][c];	
		}
	}			
}

//******************MATRIX CLASS METHODS*************
/****************************************************
Method: int determinant() const;
Use: Calculates the determinant of a 2-by-2 matrix. 
	Determinant is defined as  [[a, b], [c, d]] = ad - bc
Parameters: None
Returns: An integer, the determinant of the Matrix object.
****************************************/
int Matrix::determinant() const
{
	//Calculates and returns determinent
	return (matrixArray[0][0] * matrixArray[1][1]) - (matrixArray[1][0] * matrixArray[0][1]);
}

//***************Overloading Operators***************
//***************Methods*****************************
/****************************************************
Method: Matrix operator +(const Matrix&) const;
Use: Calculates the sum of (2) two-by-two matrices. 
Parameters: A reference to a constant Matrix object, representing right operand. 
Left operand is represented by this.
Returns: Matrix object, the result of the matrix addition of the left and right operands
****************************************/
Matrix Matrix::operator +(const Matrix& rhs) const
{
	//Declare and initilize new Matrix object with left operand
	Matrix sum = *this;
	
	//Loop through matrices
	//Outerloop to loop through rows
	for (int r = 0; r < 2; r++)
	{
		//Innerloop to loop through columns
		for (int c = 0; c < 2; c++)
		{
			//Calculates and assigns sum of element matrices to sum object
			sum.matrixArray[r][c] = this->matrixArray[r][c] + rhs.matrixArray[r][c];
		}
	}
	return sum;
}

/****************************************************
Method: Matrix operator *(int) const;
Use: Calculates result through scalar multiplication where the left operand is a Matrix object and the right is an integer
Parameters: An integer representing the right operand of the scalar multiplication. Left operand is represented by this.
Returns: Matrix object, the result of multiplying the elements of the matrix left operand by the integer right operand
****************************************/
Matrix Matrix::operator *(int rhs) const
{
	//Declare and initilize new Matrix object with left operand
	Matrix result = *this;
	
	//Outerloop to loop through rows
	for (int r = 0; r < 2; r++)
	{
		//Innerloop to loop through columns
		for (int c = 0; c < 2; c++)
		{
			//Calculates and assigns multiplication of element by integer to result object
			result.matrixArray[r][c] *= rhs;
		}
	}
	return result;
}

/****************************************************
Method: Matrix operator *(const Matrix&) const;
Use: Calculate the product of (2) two-by-two matrices
Parameters: A reference to a constant Matrix object represented by right operand. Left operand is represented by this.
Returns: Matrix object, the result of multiplying the elements of the matrix left operand by the matrix right operand
****************************************/
Matrix Matrix::operator *(const Matrix& rhs) const
{
	//Declare and initialize Matrix object using values of constructor
	Matrix result;

	//Calculates product of matrices and assigns result to object
	result.matrixArray[0][0] = (this->matrixArray[0][0] * rhs.matrixArray[0][0]) + (this->matrixArray[0][1] * rhs.matrixArray[1][0]);
	result.matrixArray[0][1] = (this->matrixArray[0][0] * rhs.matrixArray[0][1]) + (this->matrixArray[0][1] * rhs.matrixArray[1][1]);
	result.matrixArray[1][0] = (this->matrixArray[1][0] * rhs.matrixArray[0][0]) + (this->matrixArray[1][1] * rhs.matrixArray[1][0]);
	result.matrixArray[1][1] = (this->matrixArray[1][0] * rhs.matrixArray[0][1]) + (this->matrixArray[1][1] * rhs.matrixArray[1][1]);

	return result; 
}

/****************************************************
Method: bool operator ==(const Matrix&) const;
Use: Return true if all elements of the left operand are equal to the corresponding elements of the right operand. Otherwise, the method returns false.
Parameters: Reference to a constant Matrix object represented by right operand. Left operand is represented by this.
Returns: A boolean value
****************************************/
bool Matrix::operator ==(const Matrix& rhs) const
{
	//Outerloop to loop through rows
	for (int r = 0; r < 2; r++)
	{
		//Innerloop to loop through columns
		for (int c = 0; c < 2; c++)
		{
			//Checks if element of each matrix is different
			if (this->matrixArray[r][c] != rhs.matrixArray[r][c])
				return false;
		}
	}	
	return true;
}

/****************************************************
Method: bool operator !=(const Matrix&) const;
Use: Returns false if the left operand equals the right operand. Otherwise, the method should return true. 
Parameters: A reference to a constant Matrix object represented by right operand. Left operand is represented by this.
Returns: A boolean value
****************************************/
bool Matrix::operator !=(const Matrix& rhs) const
{
	//Outerloop to loop through rows
	for (int r = 0; r < 2; r++)
	{
		//Innerloop to loop through columns
		for (int c = 0; c < 2; c++)
		{
			//Checks if element of each matrix is the same
			if (this->matrixArray[r][c] == rhs.matrixArray[r][c])
				return false;
		}
	}	
	return true;
}

//***************Overloading Operators***************
//***************Friend Functions********************
/****************************************************
Function: friend ostream& operator <<(ostream&, const Matrix&);
Use: Overloads the stream insertion operator to be able to print a Matrix object in format [[a,b], [c, d]]
Parameters: 
(1): Reference to a ostream object, representing the left operand of the stream insertion expression. 
(2): Reference to a constant Matrix object, representing the right operand of the expression.
Returns: A reference to an ostream object
****************************************/
ostream& operator <<(ostream& lhs, const Matrix& rhs)
{
	//Creates output in specified format and stores in ostream object
	lhs << "[[" 
		<< rhs.matrixArray[0][0] << ", " 
		<< rhs.matrixArray[0][1] << "], ["
		<< rhs.matrixArray[1][0] << ", " 
		<< rhs.matrixArray[1][1] << "]]";

	return lhs;	//Returns ostream object
}

/****************************************************
Function: friend Matrix operator *(int, const Matrix& rhs);
Use: Calculates the result of multiplying two parameter matrices. 
Parameters:
(1): Integer representing the left operand of the scalar multiplication.
(2): Reference to a constant Matrix object representing the right operand of the scaler mult 
Returns: new Matrix object(result of multiplying the elements of the matrices
****************************************/
Matrix operator *(int lhs, const Matrix& rhs)
{
	//Declare and initialize Matrix object using values of constructor
	Matrix result;
	
	//Outloop to loop through rows	
	for (int r = 0; r < 2; r++)
	{
		//Innerloop to loop through columns
		for (int c = 0; c < 2; c++)
		{
			//Calculates product of scalar multiplication of matrix and integer
			result.matrixArray[r][c] = rhs.matrixArray[r][c] * lhs;
		}
	}
	return result; 
}
