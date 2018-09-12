#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;
struct student;
void addUser(vector<student> &gradeList, string name, float _gpa, int _age);
void printList(const vector<student> &gradeList);

int main(int argc, char* argv[]){

	ifstream inFile;
	string data;
	vector<student> students;
	string name;
	float gpa;
	int age;

	if(argc != 2){
		cout << "Usage: " << argv[0] << " <fileName>" << endl;
		return 0;
	}

	inFile.open(argv[1]);
	if (inFile.is_open())
	{
		cout << "Opened successfully!" << endl;
		while(getline(inFile, data))
		{
			stringstream ss(data);
			string token;
			getline(ss,token,',');
			name = token;
			getline(ss,token,',');
			gpa = stof(token);
			getline(ss,token,',');
			age = stoi(token);
			addUser(students, name, gpa, age);
		}
		inFile.close(); //close the file
		printList(students);
	}else{

		cout << "File unsuccessfully opened" << endl;
		return 0;
	}

	return 1;
}

struct student{
	string username;
	float gpa;
	int age;
};
void addUser(vector<student> &gradeList, string name, float _gpa, int _age){
	student newStud;
	newStud.username = name;
	newStud.gpa = _gpa;
	newStud.age = _age;
	gradeList.push_back(newStud);
}

void printList(const vector<student> &gradeList){
	for(int i = 0; i < gradeList.size(); i ++){
		cout << gradeList.at(i).username << " [" << gradeList.at(i).gpa << "] age: " << gradeList.at(i).age << endl;
	}
}
