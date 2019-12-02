/******************************************************************************
			   Name: Christian Douglas
			Program: Assignment03_Douglas, OOP 2143
			Purpose: The program uses inheritance to encrypt and
			decrypt messages. First, after the variables have been created,
			the program calls openFiles, which ask the user to enter the name
			of the input file that they would like to use, along with the name
			of the output file that they would like to print to. Then the
			program calls superSecret which uses a local string variable called
			message to be assigned the values from the infile by using the
			getline function, which is a part of the string library, to grab
			multiple words at a time.
			The function encryptMessage is called, which calls the transform
			method,that calls the message by going through each character in 
			the variable and increments each by 1 and assigns it to another 
			variable in the class. The the value of message is then printed out
			after the method call. decryptMessage is called after, which calls
			the deTransform method, that goes through each character of
			message again and decrements each letter by 1 and assigns it to a
			class variable.transform and deTransform are both virtual methods 
			in the RootCrypt class. The message variable is then printed out 
			again. The program loops through until the end of the input file, 
			and calling each action.
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
void printEncrypt(ofstream& outfile, Cipher cryptic, string message);
void printDecrypt(ofstream& outfile, Cipher cryptic, string message); 

int main()
{
	//Object for ifstream
	ifstream infile;
	//Object for ofstream
	ofstream outfile;
	//Object for Cipher
	Cipher cryptic;
	//local string variable used for infile
	string message;
	
	openFiles(infile, outfile);
	outfile << "Christian Douglas\nAssignment03_Douglas\n\n";
	//uses getline function to read each line instead of each word
	//and assigns the values to message. The message is encrypted and 
	//decrypted by each line and printed out
	while (getline(infile, message))
	{
		message = cryptic.encryptMessage(message);
		printEncrypt(outfile, cryptic, message);
		message = cryptic.decryptMessage(message);
		printDecrypt(outfile, cryptic, message);
	}

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
	printEncrypt
	Purpose: Prints out the encrypted message from Cipher's encryptMessage
	method
******************************************************************************/
void printEncrypt(ofstream& outfile, Cipher cryptic, string message)
{
	outfile << "Encrypted: " << message << "\n";
}
/******************************************************************************
	printDecrypt
	Purpose: Prints out the encrypted message from Cipher's encryptMessage
	method
******************************************************************************/
void printDecrypt(ofstream& outfile, Cipher cryptic, string message)
{
	outfile << "Decrypted: " << message << "\n";
}