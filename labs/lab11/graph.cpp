#include <iostream>
#include <climits>
#include <list>
#include "graph.hpp"
using namespace std;

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::print(){
	for(int s = 0; s < V; s++) {
		cout <<"[" << s<< "]->";
		list<int>:: iterator itr;
		for(itr = adj[s].begin(); itr != adj[s].end(); ++itr) {
			cout << *itr << " ";
		}
		cout << endl;
	}
}

void Graph::BFS_visit(int s, bool visited[]){
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	cout << "in BFT\n";
	while(!queue.empty()) {
		s = queue.front();
		cout << s;
		queue.pop_front();
		cout << " ||" << adj[s].size() << "||";

		for(auto node: adj[s]) {
			if(!visited[node]) {
				visited[node] = true;
				queue.push_back(node);
			}
			cout << "|" <<node << "|";
		}
	}
	cout << endl;
}

void Graph::BFS(int s)
{
	bool visited[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;

	for(int s = 0; s < V; s++) {
		if(!visited[s])
			BFS_visit(s,visited);
	}
}

void Graph::DFS_visit(int s, bool visited[]){
	list<int> stack;
	visited[s] = true;
	stack.push_back(s);

	while(!stack.empty()) {
		s = stack.back();
		cout << s;
		stack.pop_back();

		cout << " ";

		for(auto node: adj[s]) {
			if(!visited[node]) {
				visited[node] = true;
				stack.push_back(node);
			}
		}
	}
}

void Graph::DFS(int s)
{
	bool visited[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;

	for(int s = 0; s < V; s++) {
		if(!visited[s])
			DFS_visit(s,visited);
	}
}
