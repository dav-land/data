#include <iostream>
#include "HW4-Todo-QueueLinkedList.hpp"

using namespace std;

TodoQueueLinkedList::TodoQueueLinkedList()
{
		queueFront = queueEnd = nullptr;
}

TodoQueueLinkedList::~TodoQueueLinkedList()
{
	while(queueFront)
	{
		TodoItem * temp = queueFront;
		queueFront = queueFront->next;
		delete temp;
	}
	queueFront = nullptr;
	queueEnd = nullptr;
}

bool TodoQueueLinkedList::isEmpty()
{
	if(queueFront == nullptr || queueEnd == nullptr)
    return true;
	return false;
}

void TodoQueueLinkedList::enqueue(string todoItem)
{
	TodoItem * temp = new TodoItem;
	temp->todo = todoItem;
	if(queueFront == nullptr)
	{
		queueFront = queueEnd = temp;
	}
	else
	{
		queueEnd->next = temp;
		queueEnd = temp;
	}
}

void TodoQueueLinkedList::dequeue()
{
	TodoItem * temp = new TodoItem;
	if(isEmpty())
	{
		cout << "Queue empty, cannot dequeue an item."<<endl;
		return;
	}
	else
	{
		temp = queueFront;
		queueFront = queueFront->next;
		delete temp;
		if(!queueFront)
		{
			queueEnd = nullptr;
		}
	}
}

TodoItem * TodoQueueLinkedList::peek()
{
	if(!isEmpty())
		return queueFront;
	else
		cout << "Queue empty, cannot peek."<<endl;
  return nullptr;
}
