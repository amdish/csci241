#ifndef MATRIX_H
#define MATRIX_H
/**********************************
FILE: Matrix.h
AUTHOR: Amol Shah
LOGON ID: z1723133
DUE DATE: 03/10/2016
PURPOSE: Declaration for the Matrix class, which contains a private data member(two by two int array) and constructor prototypes to initialize object as "identity matrix"(main diagonal = 1), initializing the array with values of a passed in array. Class method prototypes to calculate the determinent and overloading operators(+,*,==,!=). Friend function prototypes are included for operators where the left operand is not a Matrix object. For scalar multiplication(int * Matrix object) and insertion operator(<<).  
******************************************/
using std::ostream;

//Matrix class declaration
class Matrix
{
	//Friend function prototypes for overloading operators
	friend ostream& operator <<(ostream&, const Matrix&);	//Overload stream insertion operator	
	friend Matrix operator *(int, const Matrix&);		//Overload (*) operator

	private:
		//two-by-two matrix of integers
		int matrixArray[2][2];

	public:
		Matrix operator +(const Matrix& rhs) const;	//Overload (+) operator
		Matrix operator *(int) const;			//Overload (*) operator
		Matrix operator *(const Matrix&) const;		//Overload (*) operator
		bool operator ==(const Matrix&) const;		//Overload (==) operator
		bool operator !=(const Matrix&) const;		//Overload (!=) operator

		//Constructors
		Matrix();		//default constructor(identity matrix)
		Matrix(int[2][2]);	//array initialization constructor	

		//Determinant method prototype
		int determinant() const;
};
#endif








