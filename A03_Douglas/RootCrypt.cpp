/******************************************************************************
					Name: Christian Douglas
					Assignment: Assignment03_Douglas, RootCrypt.cpp, 2143 OOP
					Purpose: defines the methods of the RootCrypt.h file
******************************************************************************/
#include "RootCrypt.h"
#include <string>

using namespace std;

/******************************************************************************
				Cipher
				Purpose: default constructor that initializes message to an
				empty string
******************************************************************************/
RootCrypt::RootCrypt()
{
	message = "";
}
/******************************************************************************
				Cipher
				Purpose: parameterized constructor that initializes message to
				to string variable m
******************************************************************************/
RootCrypt::RootCrypt(string m = "")
{
	message = m;
}
/******************************************************************************
				Cipher
				Purpose: copy constructor that initializes message to variable
				other.message
******************************************************************************/
RootCrypt::RootCrypt(const RootCrypt& other)
{
	message = other.message;
}

/**************************************************************************
				encryptMessage
				Purpose: Calls transform method and returns its value
**************************************************************************/
string RootCrypt::encryptMessage(string m)
{
	return transform(m);
}
/**************************************************************************
				decryptMessage
				Purpose: Calls deTransform and returns its value
**************************************************************************/
string RootCrypt::decryptMessage(string cT)
{
	return deTransform(cT);
}