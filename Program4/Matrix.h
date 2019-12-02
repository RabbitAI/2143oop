//---------------------------------------------------------------------------
//
// Name: Rachel Vetter and Christian Douglas
// Date: 11/21/2019
// Course: CMPS 2143, Fall 19, Dr. Stringfellow
//
// Purpose: 
//  The purpose of this program is to 
//
// The following code is the Matrix class header file for this program:
//
//---------------------------------------------------------------------------

#pragma once
#include <string>
using namespace std;

class Matrix
{
public:
	/**************************************************************************
					Matrix
					Purpose: default constructor for class Matrix
	**************************************************************************/
	Matrix();
	/**************************************************************************
					Matrix
					Purpose: parameterized constructor for class Matrix
	**************************************************************************/
	Matrix(int row, int col, int a[100]);
	/**************************************************************************
					Matrix
					Purpose: copy constructor for class Matrix
	**************************************************************************/
	Matrix(const Matrix &x);
	/**************************************************************************
					getRow
					Purpose: returns the value of varible m for row size
	**************************************************************************/
	int getRow();
	/**************************************************************************
					getColumn
					Purpose: returns the value of variable n for column size
	**************************************************************************/
	int getColumn();
	/**************************************************************************
					getValue
					Purpose: sets dynamic 2d array to size to, m for rows
					n for columns, and returns it
	**************************************************************************/
	int getValue(int m, int n);
	/**************************************************************************
					operator +
					Purpose: Method to overload + operator for matrix addition
	**************************************************************************/
	Matrix operator +(Matrix &x);
	/**************************************************************************
					operator *
			Purpose: Method to overload * operator for matrix multiplication
	**************************************************************************/
	Matrix operator *(Matrix &x);
	/**************************************************************************
					transpose
					Purpose: Rotates the matrix
	**************************************************************************/
	Matrix transpose();
	/**************************************************************************
					isSymmetric
					Purpose: checks to see if matrix symmetrix
	**************************************************************************/
	bool isSymmetric();
	/**************************************************************************
					toString
			Purpose: converts a list of ints to a single string and returns
			the string
	**************************************************************************/
	virtual string toString();
	/**************************************************************************
				~Matrix
				Purpose: destructor
	**************************************************************************/
	~Matrix(){}

private:
	//private Matrix variables m is for rows and n is for columns
	int m;
	int n;
protected:
	//protect double pointer set as a dynamic 2d array
	int **table;
};