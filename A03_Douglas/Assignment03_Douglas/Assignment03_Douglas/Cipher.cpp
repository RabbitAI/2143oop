/******************************************************************************
					Name: Christian Douglas
					Assignment: Assignment03_Douglas, Cipher.cpp, 2143 OOP
					Purpose: defines the methods of the Cipher.h file
******************************************************************************/
#include "Cipher.h"
#include "RootCrypt.h"
#include <string>

using namespace std;
/**************************************************************************
				Cipher
				Purpose: default constructor that inherits from RootCrypt's
				default constructor
**************************************************************************/
Cipher::Cipher() : RootCrypt()
{
}

/**************************************************************************
				Cipher
				Purpose: parameterized constructor that inherits from
				RootCrypt's parameterized constructor
**************************************************************************/
Cipher::Cipher(string m = "") : RootCrypt(m = "")
{
}

/**************************************************************************
				Cipher
				Purpose: copy constructor that inherits from RootCrypt's
				copy constructor
**************************************************************************/
Cipher::Cipher(const Cipher& other) : RootCrypt(other)
{
}

/**************************************************************************
				encryptMessage
				Purpose: Calls transform method and returns its value
**************************************************************************/
string Cipher::encryptMessage(string m)
{
	return transform(m);
}

/**************************************************************************
				decryptMessage
				Purpose: Calls deTransform and returns its value
**************************************************************************/
string Cipher::decryptMessage(string cT)
{
	return deTransform(cT);
}

/**************************************************************************
				transform
				Purpose: goes through each character in the value of the
				m variable assigns it to char letter and increments each
				value and assigns it back to m and returns m
**************************************************************************/
string Cipher::transform(string m)
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
				deTransform
				Purpose: goes through each character in the value of the
				cT variable assigns it to char letter and decrements each
				value and assigns it back to cT and returns cT
**************************************************************************/
string Cipher::deTransform(string cT)
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