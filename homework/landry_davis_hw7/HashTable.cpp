// ==========================================
// Created: November 1, 2018
// @Davis Landry
// Homework #7
// Description: Hash table class to create a hash table from the words.
// ==========================================


#include "HashTable.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

HashTable::HashTable(int hashTableSize)
{
	this->hashTableSize = hashTableSize;
	hashTable = new wordItem * [hashTableSize];
	for(int i = 0; i < hashTableSize; i++)
		hashTable[i] = nullptr;
}

HashTable::~HashTable()
{
	wordItem * temp;
		wordItem * tempNext;
	for(int i = 0; i < hashTableSize; i++)
	{
		temp = hashTable[i];
		while(temp) {
			tempNext = temp->next;
			delete temp;
			temp = tempNext;
		}
		hashTable[i] = nullptr;
	}
	delete[] hashTable;
	hashTable = nullptr;
}

void HashTable::addWord(string word)
{
	if(!isInTable(word))
	{
		//Setting temp node
		wordItem * temp = new wordItem;
		temp->word = word;
		temp->count = 0;
		temp->next = nullptr;
		//get index to put hashed word
		int index = getHash(word);
		if(hashTable[index])
			numCollisions++;
		temp->next = hashTable[index];
		hashTable[index] = temp;
		numItems++;
		incrementCount(word);
	}
	else
	{
		incrementCount(word);
	}
}

bool HashTable::isInTable(string word)
{
	int index = getHash(word);
	wordItem * temp = hashTable[index];
	while(temp && temp->word != word)
		temp = temp->next;
	if(temp)
		return true;
	return false;
}

void HashTable::incrementCount(string word)
{
	int index = getHash(word);
	wordItem * temp = hashTable[index];
	while(word != temp->word)
		temp = temp->next;
	temp->count++;
}

void HashTable::printTopN(int n)
{
	bool debug = false;
	if(debug) cout << "In printTopN" << endl;
	int i,j,k;
	//initalize top n words array
	if(debug) cout << "Initializing array" << endl;
	wordItem ** top = new wordItem * [n];
	for(i = 0; i < n; i++)
		top[i] = nullptr;
	//inserting into top n words
	if(debug) cout << "looping through hash table" << endl;
	for(i = 0; i < hashTableSize; i++)
	{
		wordItem * temp = hashTable[i];
		while(temp)
		{
			for(j = 0; j < n && top[j]; j++)
				if(temp->count > top[j]->count)
					break;
			if(j < n)
			{
				for(k = n-1; k >= j; k--)
					if(k+1 != n)
						top[k+1] = top[k];
				top[j] = temp;
			}
			temp = temp->next;
		}
	}
	if(debug) cout << "printing Array" << endl;

	for(i = 0; i < n; i++)
	{
		wordItem * temp = top[i];
		if(temp)
			cout << temp->count << " - " << temp->word << endl;
	}
	delete[] top;
}

int HashTable::getNumCollisions()
{
	return numCollisions;
}

int HashTable::getNumItems()
{
	return numItems;
}

int HashTable::getTotalNumWords()
{
	int total = 0;
	for(int i = 0; i < hashTableSize; i++)
	{
		wordItem * temp = hashTable[i];
		while(temp)
		{
			total += temp->count;
			temp = temp->next;
		}
	}
	return total;
}

unsigned int HashTable::getHash(string word)
{
	unsigned int hash = 5381;
	for(unsigned int i = 0; i < word.length(); i++)
		hash = hash * 33 + word[i];
	hash = hash % hashTableSize;
	return hash;
}

wordItem * HashTable::searchTable(string word)
{
	int index = getHash(word);
	wordItem * temp = hashTable[index];
	while(temp && temp->word != word)
		temp = temp->next;
	return temp;
}

void getStopWords(char * ignoreWordFileName, HashTable &stopWordsTable)
{
	ifstream inFile;
	string data, word;

	inFile.open(ignoreWordFileName);

	if(inFile.is_open())
	{
		for(int i = 0; i < 50; i++)
		{
			getline(inFile, data);
			stringstream ss(data);
			ss >> word;
			stopWordsTable.addWord(word);
		}
		inFile.close(); //close the file
	}
}

bool isStopWord(string word, HashTable &stopWordsTable)
{
	if(stopWordsTable.isInTable(word))
		return true;
	return false;
}
