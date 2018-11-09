// ==========================================
// Created: November 7, 2018
// @Davis Landry
// Homework #8
// Description: makes a priority queue for a hospital
// ==========================================

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "PriorityQueue.hpp"

using namespace std;

void handleUserInput(PriorityQueue& list, string filename);
void displayMenu();

int main(int argc, char * argv[])
{
	PriorityQueue list(stoi(argv[1]));

	// this will loop until user selects quit option
	string s = "";
	if(argv[2]) s = argv[2];
	handleUserInput(list,s);
	cout << "Goodbye!";
}

void handleUserInput(PriorityQueue &list, string filename)
{
	bool quit = false;
	string s_input;
	int input;
	int totalWait = 0;

	// loop until the user quits
	while (!quit)
	{
		displayMenu();

		// read in input, assuming a number comes in
		getline(cin, s_input);
		try
		{
			input = stoi(s_input);
		}
		catch (exception& e)
		{
			// non-numeric input. trigger the default switch case.
			input = 7;
		}

		switch (input)
		{
		case 1:           // find a movie
		{
			ifstream inFile;
			string temp, data, name;
			int severity, time;
			inFile.open(filename);
			if (inFile.is_open())
			{
				while(getline(inFile, data))
				{
					int count = 0;
					stringstream ss(data);
					while(getline(ss,temp,' '))
					{
						count++;
						switch (count)
						{
						case 1:
						{
							name = temp;
						}
						break;

						case 2:
						{
							severity = stoi(temp);
						}
						break;

						case 3:
						{
							time = stoi(temp);
						}
						}
					}
					if(list.isFull()) {
						cout << "Priority Queue full. Send remaining patients to another hospital." << endl;
						break;
					}
					list.enqueue(name, severity, time);
				}
				inFile.close(); //close the file
			}
		}
		break;

		case 2:
		{
			if(list.isFull()) {
				cout << "Priority Queue full. Send Patients to another hospital." << endl;
				break;
			}else{
				string n, s, t;
				cout << "Enter Patient Name:" << endl;
				getline(cin, n);
				cout << "Enter Injury Severity:" << endl;
				getline(cin, s);
				cout << "Enter Treatment Time:" << endl;
				getline(cin, t);

				list.enqueue(n, stoi(s), stoi(t));
			}
		}
		break;

		case 3:
		{
			if(list.isEmpty()) cout << "Queue empty." << endl;
			else{
				cout << "Patient Name: " << list.peekName()<< endl;
				cout << "Injury Severity: " << list.peekInjurySeverity() << endl;
				cout << "Treatment Time: " << list.peekTreatmentTime() << endl;
			}
		}
		break;

		case 4:
		{
			if(list.isEmpty()) cout << "Queue empty." << endl;
			else{
				totalWait += list.peekTreatmentTime();
				cout << "Patient Name: " << list.peekName() << " - Total Time Treating Patients: " << totalWait << endl;
				list.dequeue();
			}
		}
		break;

		case 5:    //Count movies
		{
			if(list.isEmpty()) cout << "Queue empty." << endl;
			else{
				while(!list.isEmpty()) {
					cout << "Name: " << list.peekName() << " - Total Wait Time: " << totalWait << endl;
					totalWait += list.peekTreatmentTime();
					list.dequeue();
				}
			}
		}
		break;

		case 6:
		{
			quit = true;
		}
		break;

		default:        // invalid input
			cout << "Invalid Input" << endl;
			break;
		}
	}
}

/*
 * Purpose: displays a menu with options
 * Do not modify.
 */
void displayMenu()
{
	cout << "======Main Menu======" << endl;
	cout << "1. Get Patient Information from File" << endl;
	cout << "2. Add Patient to Priority Queue" << endl;
	cout << "3. Show Next Patient" << endl;
	cout << "4. Admit Next Patient" << endl;
	cout << "5. Process Entire Queue" << endl;
	cout << "6. Quit" << endl;
}
