// ==========================================
// Created: November 1, 2018
// @Davis Landry
// Homework #7
// Description: Counts unique words in a file
// outputs the top N most common words
// ==========================================

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "HashTable.hpp"

using namespace std;

int main(int argc, char * argv[])
{
	bool debug = false;
	if(argc != 5)
	{
		cout << "Usage: ";
		cout << argv[0] << " <number of words> <filename.txt> <ignorefilename.txt> <length of hash table>";
		cout << endl;
		return 0;
	}

	if(debug) cout << "initializing hash tables" << endl;
	HashTable stopWordsTable(50);
	HashTable uniqueWordsTable(stoi(argv[4]));

	if(debug) cout << "getStopWords" << endl;
	getStopWords(argv[3], stopWordsTable);

	ifstream inFile;
	string data, word;

	if(debug) cout << "Opening file" << endl;
	inFile.open(argv[2]);
	if(inFile.is_open())
	{
		if(debug) cout << "adding words into hash" << endl;
		while(inFile >> word) {
			if(!isStopWord(word, stopWordsTable))
				uniqueWordsTable.addWord(word);
		}
		if(debug) cout << "closing file" << endl;
		inFile.close();
		if(debug) cout << "Printing top n" << endl;
		uniqueWordsTable.printTopN(stoi(argv[1]));
		cout << "#" << endl;
		cout << "Number of collisions: " << uniqueWordsTable.getNumCollisions() << endl;
		cout << "#" << endl;
		cout << "Unique non-stop words: " << uniqueWordsTable.getNumItems() << endl;
		cout << "#" << endl;
		cout << "Total non-stop words: " << uniqueWordsTable.getTotalNumWords() << endl;
	}
	else
	{
		cout << "File unsuccessfully opened!!" << endl;
		return -1;
	}
}
