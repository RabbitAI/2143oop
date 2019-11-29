/******************************************************************************
		Name: Christian Douglas
	Program : Assignment02_Douglas, OOP 2143
	Purpose : The program uses a class called Cipher to encrypt and
	decrypt messages.First, after the variables have been created,
	the program calls openFiles, which ask the user to enter the name
	of the input file that they would like to use, along with the name
	of the output file that they would like to print to.Then the
	program calls superSecret which uses a local string variable called
	message to be assigned the values from the infile by using the
	getline function, which is a part of the string library, to grab
	multiple words at a time.getMessage is then called, which is a
	defined in the Cipher class, to get the value from message and
	assign it to the variable in the Cipher class called message.
	The function encryptMessage is called, which encrypts the message
	by going through each character in the variable and increments each
	by 1 and assigns it to another variable in the class.The the value
	of message is then printed out after the method call.
	decryptMessage is called after, which goes through character of
	message again and decrements each letter by 1 and assigns it to a
	class variable.The message variable is then printed out again.
	The program loops through until the end of the input file, and
	calling each action.
******************************************************************************/
//The Cipher class which encrypts and decrypts string values
#include "Cipher.h"
	//Allows the  use of cin and cout
#include <iostream>
	//Allows the program to read input files and print output files
#include <fstream>
	//Used for type string and getline function
#include <string>

using namespace std;

void openFiles(ifstream& infile, ofstream& outfile);
void superSecret(ifstream& infile, ofstream& outfile, Cipher cryptic);

int main()
{
	//Object for ifstream
	ifstream infile;
	//Object for ofstream
	ofstream outfile;
	//Object for Cipher
	Cipher cryptic;

	openFiles(infile, outfile);
	superSecret(infile, outfile, cryptic);

	//closes the streams
	infile.close();
	outfile.close();
	return 0;
}

/******************************************************************************
openFiles
Purpose: Function created by Dr. Stringfellow that prompts the
user to enter the name for the input file and the outputfile and
opens the files.
******************************************************************************/
void openFiles(ifstream& infile, ofstream& outfile)
{
	char inFileName[40];
	char outFileName[40];


	cout << "Enter the input file name: ";
	cin >> inFileName;
	infile.open(inFileName);  //open input file


	cout << "Enter the output file name: ";
	cin >> outFileName;
	outfile.open(outFileName);//open out putfile
}

/******************************************************************************
superSecret
Purpose: Creates a local variable called message that gets assigned
values from infile using the getline function and uses methods from
the Cipher class to encrypt and decrypt the value's characters each
by one letter and prints out the values to the outfile. But it is
super secret.
******************************************************************************/
void superSecret(ifstream& infile, ofstream& outfile, Cipher cryptic)
{
	string message;
	outfile << "Christian Douglas\n";
	while (getline(infile, message))
	{
		outfile << "Original: " << message << "\n";
		cryptic.getMessage(message);
		message = cryptic.encryptMessage(message);
		outfile << "Encrypted: " << message << "\n";
		message = cryptic.decryptMessage(message);
		outfile << "Decrypted: " << message << "\n\n";
	}
}