/*****************************************************************************
Name: Christian Douglas
Program : Assignment02_Douglas, Cipher class file, 2143 OOP
Purpose : The class uses getMessage to get the value for the
private variable message.The method encryptMessage then takes
the m variable that is assigned to the message variable and
encodes it and assigns it to the cT variable that is assigned
to the crypticMessage variable and the decryptMessage method
takes the cT variable and decodes it and assigns it to the m
variable.
******************************************************************************/
#pragma once
//calls string for the message and cryticText variable
#include <string>

using namespace std;

class Cipher
{
public:
	//The default constructor to set the message and cryticText variables to 
	//default values
	Cipher();
	//Parameterized constructor that assigns m to message and cT to crypticText
	Cipher(string m, string cT);
	//The destructor for the Cipher class
	~Cipher();
	//Gets the value for the message variable called from an outside source
	string getMessage(string m);
	//Takes the value of m, and encrypts the value and assigns it to cT
	string encryptMessage(string m);
	//Takes the value of cT, and decrypts the value and assigns it to m
	string decryptMessage(string cT);

private:
	string message;
	string crypticText;
};