/******************************************************************************
		Name: Christian Douglas
	Program : Assignment03_Douglas, RootCrypt class file, 2143 OOP
	Purpose : A parent class of Cipher, RootCrypt is an abstract class that 
	provides resources to Cipher
	The method encryptMessage calls transform that then takes
	the m variable that is assigned to the message variable and
	encodes it in the Cipher class and returns the value.
	decryptMessage method then calls the deTransform method, which
	takes the cT variable and decodes it in the Cipher class and assigns it to
	the m variable and returns it. transform and deTransform are both pure 
	virtual methods in RootCrypt and are changed in the Cipher class.
******************************************************************************/
#pragma once
#include <string>
using namespace std;

class RootCrypt
{
public:
	/**************************************************************************
				RootCrypt
				Purpose: default constructor that initializes message to an
				empty string
	**************************************************************************/
	RootCrypt();
	/**************************************************************************
				RootCrypt
				Purpose: parameterized constructor that initializes message to
				to string variable m
	**************************************************************************/
	RootCrypt(string m);
	/**************************************************************************
				RootCrypt
				Purpose: copy constructor that initializes message to variable
				other.message
	**************************************************************************/
	RootCrypt(const RootCrypt& other);
	/**************************************************************************
				~RootCrypt
				Purpose: RootCrypt's destructor
	**************************************************************************/
	~RootCrypt(){}

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
	//private variable that holds a value at a time for the program
	string message;
	/**************************************************************************
				transform & deTransform
				Purpose: Pure virtual methods
	**************************************************************************/
	virtual string transform(string m) = 0;
	virtual string deTransform(string cT) = 0;
};

 