//---------------------------------------------------------------------------
//
// Name: Rachel Vetter and Christian Douglas
// Date: 11/21/2019
// Course: CMPS 2143, Fall 19, Dr. Stringfellow
//
// Purpose: 
//  The purpose of this program is to add to matrices, multiply to matrices,
//  transpose a matrix, check for symmetry, and to convert a matrix of ints to
//	a string.
// The following code is the implementation file for the Matrix 
// class of this program:
//
//---------------------------------------------------------------------------

#include "Matrix.h"
#include <string>
using namespace std;

//Default constructor
Matrix::Matrix()
{
	m = n = 0;
	table = new int*[m];
	for (int i = 0; i < m; i++)
	{
		table[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			table[i][j] = 0;
}

//Parameterized constructor
Matrix::Matrix(int row, int col, int a[100])
{
	//if (row > 0)
		m = row;
	//if (col > 0)
		n = col;

	table = new int*[m];
	for (int i = 0; i < m; i++)
	{
		table[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			table[i][j] = a[i];
		}
	}
}

//Copy constructor
Matrix::Matrix(const Matrix &x)
{
	m = x.m;
	n = x.n;
	table = new int*[getRow()];
	for (int i = 0; i < getRow(); i++)
	{
		table[i] = new int[getColumn()];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			table[i][j] = x.table[i][j];
		}
	}
}

//Accessor method for int m
int Matrix::getRow()
{
	return m;
}

//Accessor method for int n
int Matrix::getColumn()
{
	return n;
}

//sets the values for table
int Matrix::getValue(int m, int n)
{
	return table[m][n];
}

//Method to overload + operator for matrix addition
Matrix Matrix::operator +(Matrix &x)
{
	int a[100] = { 0 };
	if ((m == x.m) && (n == x.n))
	{
		Matrix ans = Matrix(m, n, a);
		for (int r = 0; r < ans.m; r++)
			for (int c = 0; c < ans.n; c++)
				ans.table[r][c] = table[r][c] + x.table[r][c];
		return ans;
	}
	else
		return Matrix();
}

//Method to overload * operator for matrix multiplication
Matrix Matrix::operator *(Matrix &x)
{
	//int a[100] = { 0 };
	if (m == x.n)
	{
		Matrix ans = Matrix(m, n, *x.table);
		for (int r = 0; r < m; r++)
			for(int j = 0; j < x.n; j++ )
				for (int c = 0; c < n; c++)
					ans.table[r][j] += (table[r][c] * x.table[c][j]);
		return ans;
	}
	else
		return Matrix();
}

//Transposes matrix
Matrix Matrix::transpose()
{
	int a[100] = { 0 };
	Matrix x = Matrix(n, m, a);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			x.table[j][i] = table[i][j];
	return x;
}

//Determine if matrix is symmetric
bool Matrix::isSymmetric()
{
	bool sym = true;
	if (m == n)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if ((table[i][j] == table[j][i]))
					sym = true;
				else
					sym = false;
			}
	}
	else
		sym = false;
	return sym;
}

//Converts matrix to string so it can be displayed
string Matrix::toString()
{
	string word = "";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			word += to_string(table[i][j]);
			if (j < n - 1)
			{
				word += " ";
			}
			if (j == n - 1)
			{
				word += "\n";
			}
		}
	}
	return word;
}