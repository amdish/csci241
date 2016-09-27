/****************************************************
FILE: Matrix.cpp
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 03.10.16
PURPOSE: 
****************************************************/
#include <iostream>
#include "Matrix.h"

using std::endl;

Matrix::Matrix()
{
	//Loop to initialize identity matrix. Main diagonal = 1
	for (int r = 0; r < 2; r++)
	{	
		for (int c = 0; c < 2; c++)
		{	
			if (r == c)
				matrixArray[r][c] = 1;
			else 
				matrixArray[r][c] = 0;
		}
	}
}

Matrix::Matrix(int inMatrix[2][2])
{
	for (int r = 0; r < 2; r++)
	{
		for (int c = 0; c < 2; c++)
		{
			matrixArray[r][c] = inMatrix[r][c];
		}
	}			
}

int Matrix::determinant() const
{
	return (matrixArray[0][0] * matrixArray[1][1]) - (matrixArray[1][0] * matrixArray[0][1]);
}

ostream& operator<<(ostream& lhs, const Matrix& rhs)
{
	lhs << "[[" 
		<< rhs.matrixArray[0][0] << ", " 
		<< rhs.matrixArray[0][1] << "], ["
		<< rhs.matrixArray[1][0] << ", " 
		<< rhs.matrixArray[1][1] << "]]";

	return lhs;
}

Matrix Matrix::operator+(const Matrix& rhs) const
{
	Matrix sum = *this;
	
	for (int r = 0; r < 2; r++)
	{
		for (int c = 0; c < 2; c++)
		{
			sum.matrixArray[r][c] = this->matrixArray[r][c] + rhs.matrixArray[r][c];
		}
	}
	
	return sum;
}

Matrix Matrix::operator*(const int& rhs) const
{
	Matrix result = *this;
	
	for (int r = 0; r < 2; r++)
	{
		for (int c = 0; c < 2; c++)
		{
			result.matrixArray[r][c] = this->matrixArray[r][c] * rhs;
		}
	}
	return result;
}

Matrix operator*(const int& lhs, const Matrix& rhs)
{
	Matrix result;
	
	for (int r = 0; r < 2; r++)
	{
		for (int c = 0; c < 2; c++)
		{
			result.matrixArray[r][c] = rhs.matrixArray[r][c] * lhs;
		}
	}
	return result; 
}

Matrix Matrix::operator*(const Matrix& rhs) const
{
	Matrix result;

	result.matrixArray[0][0] = (this->matrixArray[0][0] * rhs.matrixArray[0][0]) + (this->matrixArray[0][1] * rhs.matrixArray[1][0]);
	result.matrixArray[0][1] = (this->matrixArray[0][0] * rhs.matrixArray[0][1]) + (this->matrixArray[0][1] * rhs.matrixArray[1][1]);
	result.matrixArray[1][0] = (this->matrixArray[1][0] * rhs.matrixArray[0][0]) + (this->matrixArray[1][1] * rhs.matrixArray[1][0]);
	result.matrixArray[1][1] = (this->matrixArray[1][0] * rhs.matrixArray[0][1]) + (this->matrixArray[1][1] * rhs.matrixArray[1][1]);

	return result; 
}

bool Matrix::operator==(const Matrix& rhs) const
{
	for (int r = 0; r < 2; r++)
	{
		for (int c = 0; c < 2; c++)
		{
			if (this->matrixArray[r][c] == rhs.matrixArray[r][c])
				return true;
		}
	}	
	return false;
}

bool Matrix::operator!=(const Matrix& rhs) const
{
	for (int r = 0; r < 2; r++)
	{
		for (int c = 0; c < 2; c++)
		{
			if (this->matrixArray[r][c] == rhs.matrixArray[r][c])
				return false;
		}
	}	
	return true;
}
