/*****************************************************************************
		Name: Christian Douglas
	Program : Assignment03_Douglas, Cipher class file, 2143 OOP
	Purpose : A child class of RootCrypt, Cipher uses inheritance to encrypt
	and decrypt the values of the variable message.
	The method encryptMessage calls transform that then takes
	the m variable that is assigned to the message variable and
	encodes it. decryptMessage method then calls the deTransform method, which
	takes the cT variable and decodes it and assigns it to the m
	variable.
******************************************************************************/
#pragma once
//calls string for the message and cryticText variable
#include <string>
#include "RootCrypt.h"
using namespace std;

class Cipher: public RootCrypt
{
public:
	/**************************************************************************
				Cipher
				Purpose: default constructor that inherits from RootCrypt's
				default constructor
	**************************************************************************/
	Cipher();
	/**************************************************************************
				Cipher
				Purpose: parameterized constructor that inherits from
				RootCrypt's parameterized constructor
	**************************************************************************/
	Cipher(string m);
	/**************************************************************************
				Cipher
				Purpose: copy constructor that inherits from RootCrypt's
				copy constructor
	**************************************************************************/
	Cipher(const Cipher& other);
	/**************************************************************************
				~Cipher
				Purpose: destructor
	**************************************************************************/
	~Cipher(){}
	
	/**************************************************************************
				encryptMessage
				Purpose: Calls transform method and returns its value
	**************************************************************************/
	virtual string encryptMessage(string m);
	/**************************************************************************
				decryptMessage
				Purpose: Calls deTransform and returns its value
	**************************************************************************/
	virtual string decryptMessage(string cT);
	
private:
	/**************************************************************************
				transform
				Purpose: goes through each character in the value of the
				m variable assigns it to char letter and increments each
				value and assigns it back to m and returns m
	**************************************************************************/
	virtual string transform(string m);
	/**************************************************************************
				deTransform
				Purpose: goes through each character in the value of the
				cT variable assigns it to char letter and decrements each
				value and assigns it back to cT and returns cT
	**************************************************************************/
	virtual string deTransform(string cT);
};