#include<iostream>
#include<climits>
#include "graph.hpp"
using namespace std;

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
	g.addEdge(4, 5);

	g.print();
    cout << "Following is depth First Traversal "
         << "\n";
    g.DFS(0);
    cout << "\nFollowing is breadth First Traversal "
         << " \n";
    g.BFS(0);
	cout << endl;
    return 0;
}
