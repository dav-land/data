// ==========================================
// Created: September 19, 2018
// @Davis Landry
//
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

void resizeArray(wordItem *list[]);

const int STOPWORD_LIST_SIZE = 50;

const int INITIAL_ARRAY_SIZE = 100;

// ./a.out 10 HW2-HungerGames_edit.txt HW2-ignoreWords.txt
int main(int argc, char *argv[])
{
    vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE);
		wordItem list[INITIAL_ARRAY_SIZE];

    // verify we have the correct # of parameters, else throw error msg & return
    if (argc != 4)
    {
        cout << "Usage: ";
        cout << argv[0] << " <number of words> <filename.txt> <ignorefilename.txt>";
        cout << endl;
        return 0;
    }

	 	int numWordsToProcess = stoi(argv[1]);
		string fileToProcess = argv[2];
    getStopWords(argv[3], vecIgnoreWords);

		ifstream inFile;
		string data, word;

		cout << "Opening File: " << fileToProcess << endl;
		inFile.open(fileToProcess);

		if (inFile.is_open())
		{
			cout << "Opened successfully!" << endl;
			while(getline(inFile, data))
			{
				stringstream ss(data);
				ss >> word;
				if(!isStopWord(word, vecIgnoreWords))
				{

				}
			}

			inFile.close(); //close the file
			cout << "Stop words succesfully read into _vecIgnoreWords" << endl;
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

	cout << "Opening File: " << *ignoreWordFileName << endl;
	inFile.open(ignoreWordFileName);

	if (inFile.is_open())
	{
		cout << "Opened successfully!" << endl;
		while(getline(inFile, data))
		{
			stringstream ss(data);
			ss >> word;
			_vecIgnoreWords.push_back(word);
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
		if(word == _vecIgnoreWords.at(i))
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
    return 0;
}

/**
* Function name: arraySort
* Purpose: sort an array of wordItems, decreasing, by their count fields
* @param list - an array of wordItems to be sorted
* @param length - the length of the words array
*/
void arraySort(wordItem list[], int length)
{

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

}

void resizeArray(wordItem *list[])
{
	worditem * newList = new wordItem[2 * sizeof(*list)/sizeof(*list[0])];
	
}
