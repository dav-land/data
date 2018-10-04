#ifndef doublyLL_H
#define doublyLL_H

using namespace std;

struct Node {
	int key;
	Node* previous ;
	Node* next ;
};

class doublyLL {
	private:
		Node* createNode(int,Node*,Node*);
		Node* head ;
		Node* tail ;
	public:
		doublyLL();	//default constructor
		doublyLL(int);	//overloaded constructor
		~doublyLL();	//destructor
		bool insertNodeAtEnd(int);
	//bool deleteNode(int);
    void print_list();
		//bool deleteNode(int);
};

#endif
