#include <list>
#include "Graph.hpp"
using namespace std;

/*
     class constructor
     Purpose: perform all operations necessary to instantiate a class object
     Parameters: none
 */
Graph::Graph(){
	//vertices = new vector<vertex>;
}

/*
      class destructor
      Purpose: free all resources that the object has aquired
      Parameters: none
 */
Graph::~Graph(){
	//delete vertices;
}

/*
      Method Name: addEdge
      Purpose: Creates an edge between two vertices (using an adjVertex
      struct)
      Param: v1 - vertex at one end of edge
      Param: v2 - vertex at opposite end of edge
 */
void Graph::addEdge(string v1, string v2, int distance){
	vertex * temp1 = findVertex(v1);
	vertex * temp2 = findVertex(v2);
	adjVertex edge1 {temp2,distance};
	temp1->adj.push_back(edge1);
}

/*
      Method Name: addVertex
      Purpose: Creates a vertex
      Param: name - name of the vertex (city name)
 */
void Graph::addVertex(string name){
	vertex temp;
	temp.name = name;
	temp.ID = vertices.size();
	temp.district = 0;
	temp.visited = false;

	vertices.push_back(temp);
}

/*
     Method Name: displayEdges
     Purpose: print all edges in graph (see writeup for format)
     Parameters: none
 */
void Graph::displayEdges(){
	for (unsigned int i = 0; i < vertices.size(); i++) {
		unsigned int count = 1;
		cout << vertices.at(i).district << ":" << vertices.at(i).name;
		if (vertices.at(i).adj.size() > 0)
			cout << "-->";

		for (unsigned int j = 0; j < vertices.at(i).adj.size(); j++) {
			cout << vertices.at(i).adj.at(j).v->name;
			cout << " (" << vertices.at(i).adj.at(j).distance << " miles)";
			if (vertices.at(i).adj.size() > 1 && count != vertices.at(i).adj.size())
				cout << "***";
			count++;
		}
		cout << endl;
	}
}

/*
     Method Name: assignDistricts
     Purpose: Iterate through the vertices, perform BFT to find connected
     components, and assign to district
     Parameters: none
 */
void Graph::assignDistricts(){
	int count = 1;
	for(unsigned int i = 0; i < vertices.size(); i++) {
		if(!vertices.at(i).visited) {
			BFTraversalLabel(vertices.at(i).name, count);
			count++;
		}
	}
}

/*
     Method Name: findVertex
     Purpose: Find and return the vertex of the specified city
     Param: name - name of the city vertex to be returned
     returns pointer to a vertex
 */
vertex * Graph::findVertex(string name){
	for(unsigned int i = 0; i < vertices.size(); i++) {
		if(name.compare(vertices.at(i).name) == 0)
			return &vertices.at(i);
	}
	return nullptr;
}


/*
     Method Name: BFTraversalLabel
     Purpose: Call BFTraversalLabel from within assignDistricts to label
     the districts. This method should implement a breadth first
     traversal from the startingCity and assign all cities
     encountered the distID value
     Param: name - name of starting city for breadth first traversal
 */
void Graph::BFTraversalLabel(string startingCity, int distID){
	list<vertex*> queue;
	vertex * temp = findVertex(startingCity);
	temp->district = distID;
	queue.push_back(temp);
	//cout << temp->district << endl;
	while(!queue.empty()) {
		temp = queue.front();
		queue.pop_front();
		for(auto & node: temp->adj) {
			if(!node.v->visited) {
				node.v->district = distID;
				//cout << node.v->district << endl;
				node.v->visited = true;
				queue.push_back(node.v);
			}
		}
	}
}
