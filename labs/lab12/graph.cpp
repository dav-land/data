#include "graph.hpp"
#include<iostream>
#include<set>
#include<list>
#include<algorithm>
#include<climits>
using namespace std;


Graph::Graph(int nodeCount) {
   n = nodeCount;
   adjList = new list<node>[n];
}

void Graph::showList(int src, list<node> lt) {
   list<node> :: iterator i;
   node tempNode;

   for(i = lt.begin(); i != lt.end(); i++) {
      tempNode = *i;
      cout << "(" << src << ")---("<<tempNode.dest << "|"<<tempNode.cost<<") ";
   }
   cout << endl;
}



void Graph::addEdge(int source, int dest, int cost)
{
	node edge1;
	edge1.dest = dest;
	edge1.cost = cost;
	adjList[source].push_back(edge1);

	node edge2;
	edge2.dest = source;
	edge2.cost = cost;
	adjList[dest].push_back(edge2);
}

void Graph::displayEdges()
{
   for(int i = 0; i<n; i++)
   {
      list<node> tempList = adjList[i];
      showList(i, tempList);
   }
}

int Graph:: min_element(int dist[], bool visited[])
{
   // Initialize min value
   int min = INT_MAX, min_index = -1;
	 for(int v = 0; v < n; v++){
		 if(visited[v] == false && dist[v] < min){
			 min = dist[v];
			 min_index = v;
		 }
	 }

   return min_index;
}

void Graph::dijkstra( int *dist, int *prev, int start)
{
	bool visited[n];
	for(int i = 0; i < n; i++){
		 visited[i] = false;
		 prev[i] = -1;
		 dist[i] = INT_MAX;
	 }

	 dist[start] = 0;
	 for(int i = 0; i < n-1;i ++){
		 int u = min_element(dist,visited);
		 visited[u] = true;

		 // list<node> :: iterator it;
		 // for(it = adjList[u].begin(); it!= adjList[u].end(); it++){
		 //
		 // }
		 for(auto it : adjList[u]){
			 int v = it.dest;
			 int weight = it.cost;
			 if(dist[u] + weight < dist[v]){
				 dist[v] = dist[u] + weight;
				 prev[v] = u;
			 }
		 }
	 }
}
