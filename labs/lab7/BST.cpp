#include <iostream>
#include "BST.hpp"
using namespace std;

/**
Create a node with key as data
**/

Node* BST:: createNode(int data)
{
	Node* newNode = new Node;
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BST::BST()
{
	root = nullptr;
}

/**
parameterized constructor. It will create the root and put the data in the root.
**/

BST::BST(int data)
{
	root = createNode(data);
}

/**
Destructor
**/

BST::~BST(){
	destroyNode(root);
}

/**
This function will destroy the subtree rooted at currNode.
Think about in what order should you destroy. POSTORDER. or right-left-root
**/

void BST:: destroyNode(Node *currNode)
{
	if(currNode!=NULL)
	{
		destroyNode(currNode->left);
		destroyNode(currNode->right);
		delete currNode;
		currNode = NULL;
	}
}

//--------------------------------------------INSERT NODE IN THE TREE--------------------------------------

/**
This function will add the data in the tree rooted at currNode.
We will call this function from addNode.
NOTE: root is a private member of BST. Hence addNode function can not diretly access it.
So we need this helper function. Implement your code for inserting a node in this function.
**/

Node* BST::addNodeHelper(Node* currNode, int data)
{
	if(currNode == nullptr)
	{
		return createNode(data);
	}
	if(currNode->key > data)
	{
		currNode->left = addNodeHelper(currNode->left, data);
	}
	else if(currNode->key < data)
	{
		currNode->right = addNodeHelper(currNode->right, data);
	}
	return currNode;
}

/**
This function will insert the data in the tree. As this function can not access the rooted
it will call the addNodeHelper function.
**/

void BST::addNode( int data)
{
	if(!root)
	{
		root = createNode(data);
	}
	else
	{
		addNodeHelper(root,data);
	}
}

//--------------------------------------------GET NUMBER OF NODES-------------------------------------------

int BST::getSizeHelper(Node* currNode)
{
	if(!currNode)
	{
		return 0;
	}
	else
	{
		return 1 + getSizeHelper(currNode->left) + getSizeHelper(currNode->right);
	}
}

int BST::getSize()
{
	return getSizeHelper(root);
}
//-------------------------------------------GET MINIMUM VALUE FROM THE TREE---------------------------------

/**
Find the minimum in the subtree rooted ar currNode
Go to the left most node of this subtree.
**/

int BST::getMinValueHelper(Node* root)
{
	if(!root)
	{
		return -1;
	}
	else
	{
	if(root->left == nullptr)
	{
			return root->key;
	}
	else
	{
		return getMinValueHelper(root->left);
	}
}
}

int BST::getMinValue()
{
	return getMinValueHelper(root);
}

//--------------------------------------------GET MAXIMUM DEPTH OF THE TREE----------------------------------

int BST::getMaxDepthHelper(Node* currNode)
{
	if(!currNode)
	{
		return 0;
	}
	else
	{
		int leftDepth = getMaxDepthHelper(currNode->left);
		int rightDepth = getMaxDepthHelper(currNode->right);
		if(leftDepth > rightDepth)
			return leftDepth + 1;
		else
			return rightDepth + 1;
	}
}

int BST::getMaxDepth()
{
	return getMaxDepthHelper(root);
}

void BST:: printTreeHelper(Node* curNode)
{
	if(curNode)
	{
		printTreeHelper( curNode->left);
		cout << " "<< curNode->key;
		printTreeHelper( curNode->right);
	}
}
void BST:: printTree(){
	printTreeHelper(root);
	cout<<endl;
}
