/******************************************************************************
			Name: Christian Douglas
	  Assignment: Program 1  2143 OOP
			      Used similar code from the C++ textbook
		 Purpose: The class uses member functions to build linked list using a
		 struct called StackNode. The push function takes an outside variable
		 and alocates the value with a pointer to top and pushes it onto the 
		 top of the present stack. The pop function checks to see if the stack
		 is empty and if not, it uses a local pointer called temp, that points 
		 the top value and is removed from the current stack. isEmpty checks to
		 see if the top pointer equals NULL.
******************************************************************************/
#pragma once
#ifndef MYSTACKS_H
#define MYSTACKS_H
#include <string>

using namespace std;

class myStacks
{
	struct StackNode
	{
		string value;
		StackNode* next;
		StackNode(string value1, StackNode* next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	StackNode* top;
public:
	myStacks();
	~myStacks();
	bool isEmpty();
	void push(string);
	void pop(string &);
};
#endif