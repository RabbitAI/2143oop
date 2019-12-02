
//---------------------------------------------------------------------------
//
// Name: Rachel Vetter and Christian Douglas
// Date: 11/21/2019
// Course: CMPS 2143, Fall 19, Dr. Stringfellow
//
// Purpose: 
//  The purpose of this program is to 
//
// The following code is the ZeroOne class header file for this program:
//
//---------------------------------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Matrix.h"
using namespace std;

class ZeroOne : public Matrix
{
public:
	/**************************************************************************
						ZeroOne
						Purpose: default constructor for ZeroOne
	**************************************************************************/
	ZeroOne();
	/**************************************************************************
						ZeroOne
						Purpose: parameterized constructor for ZeroOne
	**************************************************************************/
	ZeroOne(int row, int col, int a[100]);
	/**************************************************************************
						ZeroOne
						Purpose: copy constructor for ZeroOne
	**************************************************************************/
	ZeroOne(ZeroOne& x);
	/**************************************************************************
						operator +
						Purpose: Method to override + operator of parent class
						to join zero one matrices
	**************************************************************************/
	ZeroOne operator +(Matrix &x);
	/**************************************************************************
						operator ^
						Purpose: Method to overload ^ operator to meet zero
						one matrices
	**************************************************************************/
	ZeroOne operator ^(Matrix &x);
	/**************************************************************************
						~ZeroOne
						Purpose: destructor
	**************************************************************************/
	~ZeroOne(){}
};