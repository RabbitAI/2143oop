//---------------------------------------------------------------------------
//
// Name: Rachel Vetter and Christian Douglas
// Date: 11/21/2019
// Course: CMPS 2143, Fall 19, Dr. Stringfellow
//
// Purpose: 
//  The purpose of this program is to meet and join zero to one matrices
//
// The following code is the implementation file for the ZeroOne 
// class of this program:
//
//----------------------------------------------------------------------------

#include "Matrix.h"
#include "ZeroOne.h"
using namespace std;

ZeroOne::ZeroOne() : Matrix(){}
ZeroOne::ZeroOne(int row, int col, int a[100]) { Matrix(row, col, a); }
ZeroOne::ZeroOne(ZeroOne& x) : Matrix(x){}

//Method to override + operator of parent class to join zero one matrices
ZeroOne ZeroOne::operator +(Matrix &x)
{
	ZeroOne ans;
	int m = getRow();
	int n = getColumn();
	int **table = new int*[m];
	for (int i = 0; i < m; i++)
	{
		table[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			table[i][j] = 0;
		}
	}

	if ((m == x.getRow()) && (n == x.getColumn()))
	{
		ZeroOne::ZeroOne(m, x.getColumn(), *table);
		for (int r = 0; r < ans.getRow(); r++)
		{
			for (int c = 0; c < ans.getColumn(); c++)
			{
				if ((table[r][c] == 1) || (x.getValue(r,c) == 1))
					ans.table[r][c] = 1;
				else
					ans.table[r][c] = 0;
			}
		}
	}
	return ans;
}

//Method to overload ^ operator to meet zero one matrices
ZeroOne ZeroOne::operator ^(Matrix &x)
{
	int a[100] = { 0 };
	int m = x.getRow();
	int n = x.getColumn();
	ZeroOne ans; 
	ans = ZeroOne(m, n, a);

	if ((m == x.getRow()) && (n == x.getColumn()))
	{
		for (int r = 0; r < ans.getRow(); r++)
		{
			for (int c = 0; c < ans.getColumn(); c++)
			{
				if ((table[r][c] == 1) && (x.getValue(r,c) == 1))
					ans.table[r][c] = 1;
				else
					ans.table[r][c] = 0;
			}
		}
	}
	return ans;
}