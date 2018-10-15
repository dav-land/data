#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
	queueFront = queueEnd = nullptr;
}

QueueLL::~QueueLL()
{
		while(queueFront)
		{
			Node * temp = queueFront;
			queueFront = queueFront->next;
			delete temp;
		}
		queueFront = nullptr;
		queueEnd = nullptr;
}

bool QueueLL::isEmpty()
{
	if(queueFront == nullptr || queueEnd == nullptr)
    return true;
	return false;
}

void QueueLL::enqueue(int key)
{
	Node * temp = new Node;
	temp->key = key;
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

void QueueLL::dequeue()
{
	Node * temp = new Node;
	if(isEmpty())
	{
		cout << "Queue empty cannot dequeue" << endl;
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

int QueueLL::peek()
{
	if(!isEmpty())
		return queueFront->key;
  return 0;
}
