//------------------------------------------------------------------------------------------------------------
//
// Name: Rachel Vetter and Christian Douglas
// Date: 11/21/2019
// Course: CMPS 2143, Fall 19, Dr. Stringfellow
//
// Purpose: Reads in a file with an int that tells how many matrices are in the file the number of columns and
// rows in each matrix. Then creates the matrices adds them and multiplies them, transposes them, and checks
// for symmetry. The ZeroOne class meets and joins the matrices in its class.
// 
// 
//
// The following code is the client code for this program:
//
//-----------------------------------------------------------------------------------------------------------

#include "Matrix.h"
#include "ZeroOne.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void header(ofstream &outfile);
void openFiles(ifstream &infile, ofstream &outfile);
Matrix matrix(int row, int col, int a[100]);
ZeroOne zeroOne(int row, int col, int a[100]);
void display(Matrix &x, ofstream &outfile);

int main()
{
	//Variable Declarations
	ifstream infile;
	ofstream outfile;
	string input, output;
	char mType;
	int numMatrices, row1, col1, row2, col2, a1[100], a2[100];
	Matrix matrix1, matrix2, matrix3;
	ZeroOne zeroOne1, zeroOne2, zeroOne3;

	openFiles(infile, outfile);
	//Read in number of matrices
	infile >> numMatrices;
	//Load matrices
	for (int i = 0; i < numMatrices; i++)
	{
		infile >> mType;
		infile >> row1 >> col1;
		for (int j = 0; j < (row1*col1); j++)
		{
			infile >> a1[j];
		}
		infile >> row2 >> col2;
		for (int j = 0; j < (row2*col2); j++)
		{
			infile >> a2[j];
		}
		switch (mType)
		{
		case 'R':
			matrix1 = matrix(row1, col1, a1);
			matrix2 = matrix(row2, col2, a2);
			matrix3 = matrix1 + matrix2;
			outfile << "Results of addition: \n";
			display(matrix3, outfile);
			matrix3 = matrix1 * matrix2;
			outfile << "Results of multiplication: \n";
			display(matrix3, outfile);
			break;
		case 'Z':
			zeroOne1 = zeroOne(row1, col1, a1);
			zeroOne2 = zeroOne(row2, col2, a2);
			zeroOne3 = zeroOne1 ^ zeroOne2;
			outfile << "Results of meet: \n";
			display(zeroOne3, outfile);
			zeroOne3 = zeroOne1 + zeroOne2;
			outfile << "Results of join: \n";
			display(zeroOne3, outfile);
			break;
		}
	}

	//Close files
	infile.close();
	outfile.close();
	system("pause");
	return 0;
}

//Header function
//Input: outfile
//Output: none
void header(ofstream &outfile)
{
	outfile << "Rachel Vetter and Christian Douglas\n"
		<< "CMPS 2143 - Dr. Stringfellow\n"
		<< "Program 4: Matrices\n\n";
}


//Open files function
//Input: outfile and infile
//Output: none
void openFiles(ifstream &infile, ofstream &outfile)
{
	char infileName[40], outfileName[40];
	cout << "Please enter the input file name: ";
	cin >> infileName;
	infile.open(infileName);

	cout << "Please enter the output file name: ";
	cin >> outfileName;
	outfile.open(outfileName);

	//Header
	header(outfile);
}

Matrix matrix(int row, int col, int a[100])
{
	Matrix x;
	x.Matrix::Matrix(row, col, a);
	return x;
}

ZeroOne zeroOne(int row, int col, int a[100])
{
	ZeroOne z;
	z.ZeroOne::ZeroOne(row, col, a);
	return z;
}

void display(Matrix &x, ofstream &outfile)
{
	Matrix m = Matrix();
	string matrix = x.toString();
	outfile << matrix;
	if (x.isSymmetric())
	{
		outfile << "\nThis matrix is symmetric.\n";
	}
	else
		outfile << "\nThis matrix is not symmetric.\n";
	m = x.transpose();
	outfile << "Transposed matrix:\n\n"
		<< m.toString() << endl;
}