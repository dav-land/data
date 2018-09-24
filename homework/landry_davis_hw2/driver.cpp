// ==========================================
// Created: September 19, 2018
// @Davis Landry
// Homework #2
// Description: Counts unique words in a file
// outputs the top N most common words
// ==========================================

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// struct to store word + count combinations
struct wordItem
{
	string word;
	int count;
};

void getStopWords(const char *ignoreWordFileName, vector<string> &_vecIgnoreWords);

bool isStopWord(string word, vector<string> &_vecIgnoreWords);

int getTotalNumberNonStopWords(wordItem list[], int length);

void arraySort(wordItem list[], int length);

void printTopN(wordItem wordItemList[], int topN);

const int STOPWORD_LIST_SIZE = 50;

const int INITIAL_ARRAY_SIZE = 100;

// ./a.out 10 HW2-HungerGames_edit.txt HW2-ignoreWords.txt
int main(int argc, char *argv[])
{
	vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE);
	wordItem * list = new wordItem[INITIAL_ARRAY_SIZE]; //create a new array of word items
	int size = INITIAL_ARRAY_SIZE, length = 0, numTimesDoubled = 0;

	// verify we have the correct # of parameters, else throw error msg & return
	if (argc != 4)
	{
		cout << "Usage: ";
		cout << argv[0] << " <number of words> <filename.txt> <ignorefilename.txt>";
		cout << endl;
		return 0;
	}

	int numWordsToProcess = stoi(argv[1]); //sets the top n words
	string fileToProcess = argv[2];
	getStopWords(argv[3], vecIgnoreWords); //puts the stop words into the vecIgnoreWords vector

	ifstream inFile;
	string data, word;

	cout << "Opening File: " << fileToProcess << endl;
	inFile.open(fileToProcess); //open the file

	if (inFile.is_open())
	{
		cout << "Opened successfully!" << endl;
		while(inFile >> word)//gets every word in the file
		{
			if(!isStopWord(word, vecIgnoreWords)) //check to see if its a stop word
			{
				if(length == size) //Checks to see if array is full, if it is then it doubles the array
				{
					wordItem * temp;
					temp = list;
					list = new wordItem[size * 2];

					for(int k = 0; k < size; k++)
					{
						list[k] = temp[k];
					}

					delete [] temp;
					size *= 2;
					numTimesDoubled ++;
				}
				//checks to see if the word is already in array
				bool found = false;
				for(int i = 0; i < length && !found; i ++)
				{
					if(word == list[i].word)
					{
						list[i].count = list[i].count + 1;
						found = true;
					}
				}
				//if not it adds the new word
				if(!found)
				{
					wordItem temp;
					temp.word = word;
					temp.count = 1;
					list[length] = temp;
					length ++;
				}
			}
		}


		inFile.close(); //close the file

		arraySort(list, length); //sort the array
		printTopN(list, numWordsToProcess); //print the top N numbers and words

		cout << "#" << endl;
		cout << "Array doubled: " << numTimesDoubled << endl;
		cout << "#" << endl;
		cout << "Unique non-stop words: " << length << endl;
		cout << "#" << endl;
		cout << "Total non-stop words: " << getTotalNumberNonStopWords(list, size) << endl;
	}
	else
	{
		cout << "File unsuccessfully opened!!" << endl;
		return -1;
	}

	return 0;
}

/**
* Function name: getStopWords
* Purpose: read stop word list from file and store into vector
* @param ignoreWordFile - filename (the file storing ignore/stop words)
* @param _vecIgnoreWords - store ignore words from the file (pass by reference)
* @return - none
* Note: The number of words is fixed to 50
*/
void getStopWords(const char *ignoreWordFileName, vector<string> &_vecIgnoreWords)
{
	ifstream inFile;
	string data, word;

	cout << "Opening File: " << ignoreWordFileName << endl;
	inFile.open(ignoreWordFileName);

	if(inFile.is_open())
	{
		cout << "Opened successfully!" << endl;
		for(int i = 0; i < STOPWORD_LIST_SIZE; i ++)
		{
			getline(inFile, data);
			stringstream ss(data);
			ss >> word;
			_vecIgnoreWords.at(i) = word;
		}
		inFile.close(); //close the file
		cout << "Stop words succesfully read into _vecIgnoreWords" << endl;
	}
	else
	{
		cout << "File unsuccessfully opened!!" << endl;
		return;
	}

	return;
}

/**
* Function name: isStopWord
* Purpose: to see if a word is a stop word
* @param word - a word (which you want to check if it is a stop word)
* @param _vecIgnoreWords - the vector type of string storing ignore/stop words
* @return - true (if word is a stop word), or false (otherwise)
*/
bool isStopWord(string word, vector<string> &_vecIgnoreWords)
{
	for(int i = 0; i < STOPWORD_LIST_SIZE; i ++)
	{
		//cout << _vecIgnoreWords.at(i) << endl;
		if(word == _vecIgnoreWords[i])
		{
			return true;
		}
	}
	return false;
}

/**
* Function name: getTotalNumberNonStopWords
* Purpose: compute the total number of words saved in the words array (including repeated words)
* @param list - an array of wordItems containing non-stopwords
* @param length - the length of the words array
* @return - the total number of words in the words array (including repeated words multiple times)
*/
int getTotalNumberNonStopWords(wordItem list[], int length)
{
	int numWords = 0;
	for(int i = 0; i < length; i ++)
	{
		numWords += list[i].count;
	}
	return numWords;
}

/**
* Function name: arraySort
* Purpose: sort an array of wordItems, decreasing, by their count fields
* @param list - an array of wordItems to be sorted
* @param length - the length of the words array
*/
void arraySort(wordItem list[], int length)
{
	int j,i;
	wordItem key;
	for(i = 1; i < length; i ++)
	{
		key = list[i];
		for(j = i-1;j >= 0 && list[j].count < key.count; j--)
		{
			list[j+1] = list[j];
		}
		list[j+1] = key;
	}
}

/**
* Function name: printTopN
* Purpose: to print the top N high frequency words
* @param wordItemList - a pointer that points to a *sorted* array of wordItems
* @param topN - the number of top frequency words to print
* @return none
*/
void printTopN(wordItem wordItemList[], int topN)
{
	cout << "Top Words In List: " << endl;
	wordItem topWordItemList[topN];
	for(int i = 0; i < topN; i ++)
	{
		topWordItemList[i] = wordItemList[i];
		cout << topWordItemList[i].count << " - " << topWordItemList[i].word << endl;
	}
}
