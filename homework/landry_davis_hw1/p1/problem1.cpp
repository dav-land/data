#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int insertIntoSortedArray(int myArray[], int numEntries, int newValue);
int printArr(int myArray[100], int arrCount);


int main(int argc, char* argv[]){

	ifstream inFile;
	string data;
	int arr[100];
	int arrCount = 0;
	int search;

	if(argc != 2){
		cout << "Usage: " << argv[0] << " <fileName>" << endl;
		return 0;
	}

	cout << "Opening File: " << argv[1] << endl;

	inFile.open(argv[1]);
	if (inFile.is_open())
	{
		cout << "Opened successfully!" << endl;
		while(getline(inFile, data))
		{
			stringstream ss(data);
			int num;
			ss >> num;
			arrCount = insertIntoSortedArray(arr, arrCount, num);
			printArr(arr, arrCount);
		}
		inFile.close(); //close the file
		cout << "Number of elements read: " << arrCount << endl;

		cout << "Please enter a number to find in the list." << endl;
		getline(cin, data);
		stringstream ss(data);
		ss >> search;
		for(int i = 0; i < arrCount; i ++){
			if(search == arr[i]){
				cout << search << " is at index " << i << endl;
				break;
			}else if(i == arrCount - 1) {
				cout << search << " is not in the array." << endl;
			}
		}

	}
	else
	{
		cout << "File unsuccessfully opened" << endl;
		return 0;
	}

	return 1;

}


int insertIntoSortedArray(int myArray[], int numEntries, int newValue){
	int i, j;

	if(numEntries == 0){
		myArray[0] = newValue;
		return 1;
	}
	if(numEntries >= 99){
		cout << "Array Full!!" << endl;
		return numEntries;
	}

	for(i = 0; i < numEntries; i ++){
		if(newValue < myArray[i]){
			break;
		}
	}
	for(j = numEntries-1; j >= i; j--){
		myArray[j+1] = myArray[j];
	}
	myArray[i] = newValue;

	return numEntries + 1;
}


int printArr(int myArray[100], int arrCount){

	for(int i = 0; i < arrCount-1; i ++){
		cout << myArray[i] << ", ";
	}
	cout << myArray[arrCount-1] << endl;

	return 0;
}
