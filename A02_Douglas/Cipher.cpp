/******************************************************************************
Name: Christian Douglas
Assignment: Assignment02_Douglas, Cipher.cpp, 2143 OOP
Purpose: defines the methods of the Cipher.h file
******************************************************************************/
#include "Cipher.h"
#include <string>


/**************************************************************************
Cipher
Purpose: default constructor that initializes message and
crypticText to blank strings
**************************************************************************/
Cipher::Cipher()
{
	message = "";
	crypticText = "";
}

/**************************************************************************
Cipher
Purpose: parameterized constructor that initializes message
to m and crypticText to cT
**************************************************************************/
Cipher::Cipher(string m = "", string cT = "")
{
	message = m;
	crypticText = cT;
}

/**************************************************************************
~Cipher
Purpose: destructor
**************************************************************************/
Cipher::~Cipher()
{}

/**************************************************************************
getMessage
Purpose: assigns an outside value to m variable
**************************************************************************/
string Cipher::getMessage(string m)
{
	return m;
}
/**************************************************************************
encryptMessage
Purpose: goes through each character in the value of the
m variable assigns it to char letter and increments each
value and assigns it back to m and returns m
**************************************************************************/
string Cipher::encryptMessage(string m)
{
	char letter;

	for (int i = 0; i < m.length(); i++)
	{
		letter = m.at(i);
		++letter;
		m.at(i) = letter;
	}
	return m;
}
/**************************************************************************
decryptMessage
Purpose: goes through each character in the value of the
cT variable assigns it to char letter and decrements each
value and assigns it back to cT and returns cT
**************************************************************************/
string Cipher::decryptMessage(string cT)
{
	char letter;
	for (int i = 0; i < cT.length(); i++)
	{
		letter = cT.at(i);
		--letter;
		cT.at(i) = letter;
	}
	return cT;
}