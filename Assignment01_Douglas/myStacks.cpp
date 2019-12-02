#include "myStacks.h"
#include <iostream>

/******************************************************************************
			myStacks
			purpose: nonparameterized constructor that sets the top pointer to 
			null.
******************************************************************************/
myStacks::myStacks()
{	
	top = NULL;
}

/******************************************************************************
			~myStacks
			purpose: destructor that deallocates the top
******************************************************************************/
myStacks::~myStacks()
{
	StackNode* garbage = top;
	while (garbage != NULL)
	{
		top = top->next;
		garbage->next = NULL;
		delete garbage;
		garbage = top;
	}
}

/******************************************************************************
		isEmpty
		purpose: Lets the user know that top equals null
******************************************************************************/
bool myStacks::isEmpty()
{
	return top == NULL;
}
/******************************************************************************
		push
		purpose: takes outside value and assigns it with the top pointer to top
******************************************************************************/
void myStacks::push(string card)
{
	this->top = new StackNode(card,top);
}
/******************************************************************************
		pop
		purpose: creates a pointer called temp, checks to see if the stack is
		empty, if not temp is assigned the value at the top of the stack and is
		removed from the stack
******************************************************************************/
void myStacks::pop(string &card)
{
	StackNode* temp;

	if (isEmpty())
	{
		cout << "Can't pop an empty list\n";
	}
	else
	{
		card = top->value;
		temp = top;
		top = top->next;
		delete temp;
	}
}
