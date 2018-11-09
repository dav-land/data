#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

#include "MovieTree.hpp"

using namespace std;

// declarations for UI/menu helper-functions
void displayMenu();
void handleUserInput(MovieTree& movTree);

int main(int argc, char* argv[])
{
	// Object representing our network of cities.
	// (Linked list representation is in CityNetwork)
	MovieTree movTree;
	ifstream inFile;

	int ranking, releaseYear, quantity, count = 0;
	string title, data, temp;

	inFile.open(argv[1]);
	if (inFile.is_open())
	{
		while(getline(inFile, data))
		{
			count = 0;
			stringstream ss(data);
			while(getline(ss,temp,','))
			{
				count++;
				switch (count)
				{
				case 1:
				{
					ranking = stoi(temp);
				}
				break;

				case 2:
				{
					title = temp;
				}
				break;

				case 3:
				{
					releaseYear = stoi(temp);
				}
				break;

				case 4:
				{
					quantity = stoi(temp);
				}
				}
			}
			movTree.addMovieNode(ranking,title,releaseYear,quantity);
		}
		inFile.close(); //close the file
	}
	// this will loop until user selects quit option
	handleUserInput(movTree);

	cout << "Goodbye!" << endl;
	return 0;
}

void handleUserInput(MovieTree& movTree)
{
	bool quit = false;
	string s_input;
	int input;

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
			string movieTitle;
			cout << "Enter title:" << endl;
			getline(cin, movieTitle);

			movTree.findMovie(movieTitle);
		}
		break;

		case 2:           //Rent a movie
		{
			string movieTitle;
			cout << "Enter title:" << endl;
			getline(cin, movieTitle);

			movTree.rentMovie(movieTitle);
		}
		break;

		case 3:
		{
			movTree.printMovieInventory();
		}
		break;

		case 4:    //delete movie
		{
			string movieTitle;
			cout << "Enter title:" << endl;
			getline(cin, movieTitle);

			movTree.deleteMovie(movieTitle);
		}
		break;

		case 5:    //Count movies
		{
			movTree.countMovies();
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
	cout << "1. Find a movie" << endl;
	cout << "2. Rent a movie" << endl;
	cout << "3. Print the inventory" << endl;
	cout << "4. Delete a movie" << endl;
	cout << "5. Count movies" << endl;
	cout << "6. Quit" << endl;
}
