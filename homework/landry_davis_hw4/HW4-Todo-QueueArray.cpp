#include <iostream>
#include "HW4-Todo-QueueArray.hpp"
using namespace std;

TodoQueueArray::TodoQueueArray()
{
	queueFront = queueEnd = -1;
}

bool TodoQueueArray::isEmpty()
{
	if(queueFront == -1 || queueEnd == -1)
	return true;
	return false;
}

bool TodoQueueArray::isFull()
{
	if((queueFront)%MAX_QUEUE_SIZE == (queueEnd+1)%MAX_QUEUE_SIZE)
		return true;
	return false;
}

void TodoQueueArray::enqueue(std::string todoItem)
{
	TodoItem * temp = new TodoItem;
	temp->todo = todoItem;
	if(!isFull())
	{
		if(queueFront == -1)
		{
			queueFront = queueEnd = 0;
			queue[0] = temp;
		}
		else
		{
			queueEnd = (queueEnd + 1)%MAX_QUEUE_SIZE;
			queue[queueEnd] = temp;
		}
	}
	else
	{
		cout << "Queue full, cannot add new todo item." << endl;
	}
}

void TodoQueueArray::dequeue()
{
	TodoItem * temp = new TodoItem;
	if(isEmpty())
	{
		cout << "Queue empty, cannot dequeue an item."<<endl;
		return;
	}
	else
	{
		temp = queue[queueFront];
		queueFront = (queueFront+1)%MAX_QUEUE_SIZE;
		delete temp;
		if(queueFront%MAX_QUEUE_SIZE == (queueEnd+1)%MAX_QUEUE_SIZE)
		{
			queueFront = queueEnd = -1;
		}
	}
}

TodoItem* TodoQueueArray::peek()
{
	if(!isEmpty())
	{
		return queue[queueFront];
	}
	else
	{
		cout << "Queue empty, cannot peek."<<endl;
	}
	return nullptr;
}
