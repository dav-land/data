#include <iostream>
#include "doublyLL.h"
using namespace std;

doublyLL::doublyLL()
{
	head = tail = nullptr;
}

doublyLL::doublyLL(int nodeID)
{
	//create head node
	head = createNode(nodeID, nullptr,nullptr);
	tail = head;
}

doublyLL::~doublyLL()
{
	while(head)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	head = nullptr;
	tail = nullptr;
}


Node* doublyLL::createNode(int nodeID, Node* nodePrev, Node* nodeNext)
{
	Node* newNode = new Node;
	newNode->key = nodeID;
	newNode->next = nodeNext;
	newNode->previous = nodePrev;
	return newNode;
}

bool doublyLL::insertNodeAtEnd(int nodeID)
{
	if(!head)
	{
		head = createNode(nodeID, nullptr, nullptr);
		tail = head;
	}
	else
	{
		tail->next = createNode(nodeID, tail, nullptr);
		tail = tail->next;
	}
	return true;
}

void doublyLL::print_list()
{
	Node * temp = head;
	while(temp)
	{
		cout << temp->key;
		if(temp->next)
		{
			cout << " <-> ";
		}
		temp = temp->next;
	}
	cout<<endl;
}
/***
This function deletes all the nodes with id nodeID
param: nodeId- the nodeId
returns: true if something deleted
***/
/*bool doublyLL::deleteNode(int nodeID){
//store the head in temp and mark isDelted as false
Node* temp = head;
bool isDeleted = false;
// if the list is empty
if( temp==nullptr )
return false;
// traverse the linked lsit and look for nodes with id= nodeID
while( temp != nullptr)
{
//Found a node with id == nodeID. Three cases
if(temp->id ==  nodeID)
{
//case1: if it is the head. Do the following
//		1. Update head as head->next since we are going to delete the current head
//		2. make temp->next null to segregate it from the list. Delete temp
//		3. We want to continue our traverse for looking other nodes. So make temp = head so that we can continue traversing
if(temp == head)
{
//if(head->next != nullptr)
head->prev = nullptr;
head = head->next;
//
temp->next = nullptr;
delete temp;
temp = head;
}
//case2: if it is found at tail. Do the following
//		1. Update the tail to tail->prev since we will be deleting the tail
//		2. make tail->next = nullptr to mark the end of print_list
//		3. Delte temp. Note we do not need to update temp like case1. Think "why"
else if(temp == tail)
{
//if(tail->prev !=nullptr)
tail = tail->prev;
tail->next = nullptr;
temp->prev = nullptr;
delete temp;
temp = nullptr;
}
//case3: If it is found somewhere in between head and tail.
//		1. Store it in some del nodes
//		2. Update the pointers.
//		3. Segregate the del node from the list and delete it
//      4. make temp = temp->next so that we can continue our traversal
else{
Node* del = temp;
temp->next->prev = temp->prev;
temp->prev->next = temp->next;
temp = temp->next;
del->prev = nullptr;
del->next = nullptr;
delete del;
}
//set is deleted true
isDeleted = true;
}
// if temp->id! = nodeId move on to next node in the list
else
temp = temp->next;
}
return isDeleted;
}*/
