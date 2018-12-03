#include <iostream>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include "Graph.hpp"
using namespace std;

// Driver program to test methods of graph class
int main(int argc, char * argv[]){
	ifstream inFile;
	string data, word;
	bool cityNames = true;
	bool cityName = true;
	string city;
	vector<string> cityList;
	int count = 0;
	bool debug = false;
	if(debug)
		cout << "runs\n";

	Graph cities;

	inFile.open(argv[1]);

	if(debug)
		cout << "opened file\n";
	if(inFile.is_open()) {
		while(getline(inFile, data)) {
			if(debug)
				cout << "parsing lines \n";
			stringstream ss(data);
			cityName = true;
			while(getline(ss,word,',')) {
				if(debug)
					cout << "adding cities\n";
				if(word.compare("cities") == 0) {

				}else if(cityNames) {
					cities.addVertex(word);
					cityList.push_back(word);
				}else if(cityName) {
					city = word;
					cityName = false;
					//cout << " ... Reading in " << city << endl;
				}else{
					do {
						//cout << stoi(word) << endl;
						if(stoi(word) > 0) {
							cout << " ... Reading in " << city << " -- " << cityList.at(count) << " -- " << word << endl;
							cities.addEdge(city, cityList.at(count), stoi(word));
							// cout << city << " " << cityList.at(count) << " " << stoi(word) << endl;
						}
						count++;
					} while(getline(ss,word,','));
					count = 0;
				}
			}
			cityNames = false;
		}
		inFile.close(); //close the file
	}
	cities.assignDistricts();
	cities.displayEdges();
}
