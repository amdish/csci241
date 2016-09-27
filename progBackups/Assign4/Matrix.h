#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using std::ostream;

class Matrix
{
	friend ostream& operator<<(ostream&, const Matrix&);	
	friend Matrix operator*(const int&, const Matrix&);

	public:	
	Matrix operator+(const Matrix& rhs) const;
	Matrix operator*(const int& rhs) const;
	Matrix operator*(const Matrix& rhs) const;
	bool operator==(const Matrix& rhs) const;
	bool operator!=(const Matrix& rhs) const;

	private:
		int matrixArray[2][2] = {{5,7},{3,2}};
	
	public:
		Matrix();		//identity constructor
		Matrix(int[2][2]);	//array initialization constructor	

		int determinant() const;
};


#endif








