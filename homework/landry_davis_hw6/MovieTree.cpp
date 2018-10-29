#include "MovieTree.hpp"
#include <iostream>

using namespace std;

MovieTree::MovieTree()
{
	root = nullptr;
}

void destroyNode(MovieNode *currNode)
{
	if(currNode!=NULL)
	{
		destroyNode(currNode->leftChild);
		destroyNode(currNode->rightChild);
		delete currNode;
		currNode = NULL;
	}
}

MovieTree::~MovieTree()
{
	//aint tested
	destroyNode(root);
}

void printTreeHelper(MovieNode* currNode)
{
	if(currNode)
	{
		printTreeHelper(currNode->leftChild);
		cout << "Movie: " << currNode->title << " " << currNode->quantity << endl;
		printTreeHelper(currNode->rightChild);
	}
}

void MovieTree::printMovieInventory()
{
	printTreeHelper(root);
}

MovieNode * addNodeHelper(MovieNode* currNode, int ranking, string title, int releaseYear,int quantity)
{
	if(currNode == nullptr)
	{
		return new MovieNode(ranking, title, releaseYear, quantity);
	}
	if(title.compare(currNode->title) <= 0)
	{
		currNode->leftChild = addNodeHelper(currNode->leftChild, ranking, title, releaseYear, quantity);
	}
	else if(title.compare(currNode->title) > 0)
	{
		currNode->rightChild = addNodeHelper(currNode->rightChild, ranking, title, releaseYear, quantity);
	}
	return currNode;
}

void MovieTree::addMovieNode(int ranking, string title, int releaseYear,int quantity)
{
	if(!root)
	{
		root = new MovieNode(ranking, title, releaseYear, quantity);
	}
	else
	{
		addNodeHelper(root, ranking, title, releaseYear, quantity);
	}
}

int findMovieHelper(MovieNode* node, std::string title)
{
	if(!node)
	{
		return 0;
	}
	else if(node->title.compare(title) == 0)
	{
		cout << "Movie " << "'"<< node->title <<"' Info:"<< endl;
		cout << "================================" << endl;
		cout << "Ranking : " << node->ranking << endl;
		cout << "Title   : " << node->title << endl;
		cout << "Year    : " << node->year << endl;
		cout << "Quantity: " << node->quantity << endl;
		return 1;
	}
	else
	{
		return findMovieHelper(node->rightChild, title) + findMovieHelper(node->leftChild, title);
	}
}

void MovieTree::findMovie(string title)
{
	if(findMovieHelper(root, title) == 0)
	{
		cout << "Movie not found." << endl;
	}
}

int rentMovieHelper(MovieNode* node,string title)
{
	if(!node)
	{
		return 0;
	}
	else if(node->title.compare(title) == 0)
	{
		if(node->quantity > 0)
		{
			node->quantity = node->quantity - 1;
			cout << "Movie has been rented." << endl;
			cout << "Movie " << "'"<< node->title <<"' Info:"<< endl;
			cout << "================================" << endl;
			cout << "Ranking : " << node->ranking << endl;
			cout << "Title   : " << node->title << endl;
			cout << "Year    : " << node->year << endl;
			cout << "Quantity: " << node->quantity << endl;
			if(node->quantity == 0)
				return 2;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return rentMovieHelper(node->rightChild, title) + rentMovieHelper(node->leftChild, title);
	}
}

void MovieTree::rentMovie(string title)
{
	int check = rentMovieHelper(root, title);
	if(check == 0)
	{
		cout << "Movie not found." << endl;
	}
	else if(check == 2)
	{
		deleteMovie(title);
	}
}

MovieNode* minValHelper(MovieNode * currNode)
{
  if(!currNode->leftChild)
	{
		return currNode;
	}
  return minValHelper(currNode->leftChild);
}

MovieNode * deleteMovieHelper(MovieNode * curNode,string title)
{
	if(!curNode)
		return nullptr;

	if(title.compare(curNode->title) == 0)
	{
		if(!curNode->rightChild && !curNode->leftChild)
		{
			delete curNode;
			return nullptr;
		}
		else if(!curNode->rightChild)
		{
			MovieNode* temp = curNode;
			temp = temp->leftChild;
			delete curNode;
			return temp;
		}
		else if(!curNode->leftChild)
		{
			MovieNode* temp = curNode;
			temp = temp->rightChild;
			delete curNode;
			return temp;
		}
		else
		{
			MovieNode * temp = minValHelper(curNode->rightChild);
			curNode->title = temp->title;
			curNode->ranking = temp->ranking;
			curNode->year = temp->year;
			curNode->quantity = temp->quantity;
			curNode->rightChild = deleteMovieHelper(curNode->rightChild,temp->title);
		}
	}
	else if(title.compare(curNode->title) < 0)
	{
		curNode->leftChild = deleteMovieHelper(curNode->leftChild,title);
	}
	else if(title.compare(curNode->title) > 0)
	{
		curNode->rightChild = deleteMovieHelper(curNode->rightChild,title);
	}
	return curNode;
}

void MovieTree::deleteMovie(string title)
{
	if (root)
		root = deleteMovieHelper(root, title);
  else
		cout << "Movie not found." << endl;
}

int countMoviesHelper(MovieNode* curNode)
{
	if(!curNode)
	{
		return 0;
	}
	return 1 + countMoviesHelper(curNode->rightChild) + countMoviesHelper(curNode->leftChild);
}

void MovieTree::countMovies()
{
	int count = countMoviesHelper(root);
	cout << "Count = " << count << endl;
}
