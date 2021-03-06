#ifndef GRAPH_HPP
#define GRAPH_HPP
#include<list>
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    std::list<int> *adj;
public:
    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

	void print();
    // prints BFS traversal from a given source s
	void BFS_visit(int s, bool visited[]);
    void BFS(int s);
	void DFS_visit(int s, bool visited[]);
    void DFS(int s);
};
#endif
