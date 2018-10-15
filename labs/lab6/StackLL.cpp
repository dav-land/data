#include <iostream>
#include "StackLL.hpp"

using namespace std;

StackLL::StackLL()
{
	stackHead = nullptr;
}

StackLL::~StackLL()
{
	while(stackHead)
	{
		Node * temp = stackHead;
		stackHead = stackHead->next;
		delete temp;
	}
	stackHead = nullptr;
}

bool StackLL::isEmpty()
{
	if(stackHead == nullptr){
		return true;
	}
	else
	{
		return false;
	}
}

void StackLL::push(int key)
{
	Node * temp = new Node;
	temp->key = key;
	temp->next = nullptr;
	if(isEmpty())
	{
		stackHead = temp;
	}
	else
	{
		temp->next = stackHead;
		stackHead = temp;
	}
}

void StackLL::pop()
{
	Node * temp = stackHead;
	if(isEmpty())
	{
		cout << "Stack is empty cannot pop" << endl;
		return;
	}
	else
	{
		stackHead = stackHead->next;
		delete temp;

		//stackHead = nullptr;
	}

}

int StackLL::peek()
{
	if(!isEmpty())
	return stackHead->key;
	return 0;
}
