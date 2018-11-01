#include "HashTable.hpp"
#include <iostream>

using namespace std;

HashTable::Hashtable(int hashTableSize)
{
    this->hashTableSize = hashTableSize;
    hashTable = new wordItem * [hashTableSize];
    for(int i = 0; i < hashTableSize;i++)
        table[i] = nullptr;
}

HashTable::~HashTable()
{

}

void HashTable::addWord(string word)
{

}

bool HashTable::isInTable(string word)
{

}

void HashTable::incrementCount(string word)
{

}

void HashTable::printTopN(int n)
{

}

int HashTable::getNumCollisions()
{

}

int HashTable::getNumItems()
{

}

int HashTable::getTotalNumWords()
{

}

unsigned int HashTable::getHash(string word)
{

}

wordItem * HashTable::searchTable(string word)
{

}

void getStopWords(char * ignoreWordFileName, HashTable &stopWordsTable)
{

}

bool isStopWord(string word, HashTable &stopWordsTable)
{
	
}
