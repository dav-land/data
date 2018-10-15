#include <iostream>
#include "HW4-Todo-StackLinkedList.hpp"

using namespace std;

TodoStackLinkedList::TodoStackLinkedList()
{
	stackHead = nullptr;
}

TodoStackLinkedList::~TodoStackLinkedList()
{
	while(stackHead)
	{
		TodoItem * temp = stackHead;
		stackHead = stackHead->next;
		delete temp;
	}
	stackHead = nullptr;
}

bool TodoStackLinkedList::isEmpty()
{
	if(stackHead == nullptr){
		return true;
	}
	else
	{
		return false;
	}
}

void TodoStackLinkedList::push(string todoItem)
{
	TodoItem * temp = new TodoItem;
	temp->todo = todoItem;
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

void TodoStackLinkedList::pop()
{
	TodoItem * temp = stackHead;
	if(isEmpty())
	{
		cout << "Stack empty, cannot pop an item." << endl;
		return;
	}
	else
	{
		stackHead = stackHead->next;
		delete temp;
	}
}

TodoItem * TodoStackLinkedList::peek()
{
	if(!isEmpty())
		return stackHead;
	cout << "Stack empty, cannot peek." << endl;
	return nullptr;
}
