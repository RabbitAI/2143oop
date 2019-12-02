/******************************************************************************
          Name: Christian Douglas
	Assignment: Program 1  2143 OOP	
	   Purpose: The program uses a programmer defined class call myStacks to 
	   create an array of stacks in the function initDeck. openFiles allows the
	   user to open any input file that they want to use. The play function 
	   holds all the functions but openfiles it uses a while loop that goes 
	   through the top element of each stack and uses conditional statements
	   to compare variable three spaces away and one space away, if one of the
	   conditions are true it will call the the function moveThree or moveOne
	   which pops the value off of its stack and puts it on the other stack.
	   checkOne and checkThree are the functions that check whether the values
	   one away and three away are true or not my popping off the the top 
	   values and comparing each character in the value if the value of one of 
	   the characters is true, the function will return true and call moveThree
	   or moveOne else it goes to the next memory location on the array. If the 
	   memory location that is moved in moveOne or moveThree is empty after the
	   move the function closeGap moves the values from the other stack over.

******************************************************************************/
#include <iostream>
#include <fstream>
#include "myStacks.h"

using namespace std;

void initDeck(myStacks mystack, ifstream& infile,
	myStacks deck[52][52], string cardType);
bool checkOne(int index, string str, myStacks deck[52][52]);
void moveOne(int index, myStacks deck[52][52]);
bool checkThree(int index, string str, myStacks deck[52][52]);
void moveThree(int index, myStacks deck[52][52]);
void closeGap(int index, int size, myStacks deck[52][52]);
void openFiles(ifstream& infile, ofstream& oufile);
void play(int size, myStacks mystack, ifstream& infile, ofstream& outfile,
	myStacks deck[52][52], string cardType, string str);

int main()
{
	
	ifstream infile;
	ofstream outfile;
	int size = 52;
	string str, cardType = "";
	myStacks mystack,
	deck[52][52];

	openFiles(infile, outfile);
	outfile << "Name: Christian Douglas\n"
		<< "Assignment: Program 1\n";
	play(size, mystack, infile, outfile, deck, cardType, str);
	
	infile.close();
	outfile.close();
	return 0;
}

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

void initDeck(myStacks mystack, ifstream& infile,
	myStacks deck[52][52], string cardType)
{
	int index = 0;
	while (infile >> cardType)
	{
		if (cardType != "#")
		{
			deck[index][0].push(cardType);
			index++;
		}
		
	}
	
}

bool checkOne(int index, string str, myStacks deck[52][52])
{
	char num;
	string cardType1, cardType2;
	deck[index][0].pop(cardType1);
	deck[index + 1][0].pop(cardType2);
	for (num = 0; num < 2; num++)
	{
		cardType1.at(num);
		cardType2.at(num);
		if (cardType1.at(0) == cardType2.at(0))
		{
			return true;
		}
		else if (cardType1.at(1) == cardType2.at(1))
		{
			return true;
		}

		else
		{
			return false;
		}	
	}
}

void moveOne(int index, myStacks deck[52][52])
{
	string cardType;
	deck[index + 1][0].pop(cardType);
	deck[index][0].push(cardType);
		
}

bool checkThree(int index, string str, myStacks deck[52][52])
{
	char num;
	string cardType1, cardType2;
	deck[index][0].pop(cardType1);
	deck[index + 3][0].pop(cardType2);
	for (num = 0; num < 2; num++)
	{
		cardType1.at(num);
		cardType1.at(num);
		if (cardType1.at(0) == cardType2.at(0))
		{
			return true;
		}
		else if (cardType1.at(1) == cardType2.at(1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void moveThree(int index, myStacks deck[52][52])
{
	string cardType;
	deck[index + 3][0].pop(cardType);
	deck[index][0].push(cardType);
}

void closeGap(int index, int size, myStacks deck[52][52])
{
	if (deck[index][0].isEmpty())
	{
		for (int i = 0; i < size; i++)
		{
			while (index != size-1)
			{
				deck[index][i] = deck[index + 1][i];
				index++;
			}
		}
		
	}
}

void play(int size, myStacks mystack, ifstream& infile, ofstream& outfile,
	myStacks deck[52][52], string cardType, string str)
{
	int index = 0;
	initDeck(mystack, infile, deck, cardType);
	while (index != size)
	{
		if (checkThree(index, str, deck) == true)
		{
			moveThree(index, deck);
			closeGap(index + 3, size, deck);
		}
		else if (checkOne(index, str, deck) == true)
		{
			moveOne(index, deck);
			closeGap(index + 1, size, deck);
		}
		else
		{
			deck[index + 1][0];
		}
	}
	
}