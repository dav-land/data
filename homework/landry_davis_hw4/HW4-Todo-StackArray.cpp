//Davis Landry | HW #4 | Elizabeth Boese
#include <iostream>
#include "HW4-Todo-StackArray.hpp"

using namespace std;

//initializes top of stack
TodoStackArray::TodoStackArray()
{
	stackTop = -1;
}

//checks to see if stack is empty
bool TodoStackArray::isEmpty()
{
	if(stackTop == -1)
		return true;
	return false;
}

//checks to see if stack is full
bool TodoStackArray::isFull()
{
	if(stackTop == MAX_STACK_SIZE-1)
		return true;
	return false;
}

//pushes element onto the top of the stack
void TodoStackArray::push(string todoItem)
{
	TodoItem * temp = new TodoItem;
	temp->todo = todoItem;
	if(!isFull())
	{
		if(stackTop == -1)
		{
			stackTop = 0;
			stack[stackTop] = temp;
		}
		else
		{
			stackTop++;
			stack[stackTop] = temp;
		}
	}
	else
	{
		cout << "Stack full, cannot add new todo item." << endl;
	}
}

//pops element off of the stack
void TodoStackArray::pop()
{
	TodoItem * temp = stack[stackTop];
	if(isEmpty())
	{
		cout << "Stack empty, cannot pop an item." << endl;
		return;
	}
	else
	{
		stackTop--;
		delete temp;
	}
}

//returns element on top of stack
TodoItem* TodoStackArray::peek()
{
	if(!isEmpty())
		return stack[stackTop];
	cout << "Stack empty, cannot peek." << endl;
	return nullptr;
}
