// CPP program to implement hashing with chaining
#include <iostream>
#include "hash.hpp"

using namespace std;

node* HashTable::createNode(string key, node* next)
{
	node* nw = new node;
	nw->key = key;
	nw->next = next;
	return nw;
}

HashTable::HashTable(int bsize)
{
	tableSize = bsize;
	table = new node*[tableSize];
	for(int i = 0; i < tableSize; i++)
		table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(string key)
{
	unsigned int hash = 0;
	for(unsigned int i = 0; i < key.size(); i++)
		hash += key[i];
	return hash % tableSize;
}

//function to search
node* HashTable::searchItem(string key)
{
	unsigned int index = hashFunction(key);
	node * temp = table[index];
	while(temp && temp->key != key)
		temp = temp->next;
	return temp;
}

//function to insert
bool HashTable::insertItem(string key)
{
	if(!searchItem(key))
	{
		node * temp = createNode(key,nullptr);
		int index = hashFunction(key);
		temp->next = table[index];
		table[index] = temp;
		return true;
	}
	cout << "Dublicate Key" << endl;
	return false;
}

// function to delete
bool HashTable::deleteItem(string key)
{
	int index = hashFunction(key);
	node * temp = table[index];
	bool found = false;
	//-- LL is empty--//
	if(!temp) {
		return found;
	}
	if(temp->key == key)
	{
		table[index] = temp->next;
		delete temp;
		temp = nullptr;
		return true;
	}
	else
	{
		while(temp->next && !found)
		{
			if(temp->next->key == key)
			{
				found = true;
				node * delNode = temp->next;
				temp->next = temp->next->next;
				delete(delNode);
				delNode = nullptr;
			}
			else{
				temp = temp->next;
			}
		}
	}
	return found;
}

// function to display hash table
void HashTable::printTable()
{
	for (int i = 0; i < tableSize; i++) {
		cout << i <<"|| ";
		node* temp = table[i];
		while(temp)
		{
			cout<< temp->key;
			if(temp->next!=nullptr)
			{
				cout<<"-->";
			}
			temp = temp->next;
		}
		cout<<endl;

	}
}
