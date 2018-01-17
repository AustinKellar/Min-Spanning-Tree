#include <iostream>
#include <vector>
#include"PQ.h"
using namespace std;
#include<ctime>

const double MIN_DISTANCE = 0.0;
const double MAX_DISTANCE = 10.0;
const int N = 100;

//overload the << operator for vector<Edge>
ostream& operator<<(ostream& out, const vector<Edge>& v) {
	int len = static_cast<int>(v.size());
	for(int i=0; i<len; i++) {
		if(i  < len-1) {
			out << v[i] << ", ";
		} else {
			out << v[i];
		}
	}
	return out;
}

//returns a random double between the 2 input values
inline double randomInRange(double min, double max) {
	return (max - min) * ( static_cast<double>(rand()) / static_cast<double>(RAND_MAX) ) + min;
}


//generates a graph based on input density with distances between min and max
inline Graph generateGraph(double density, double max, double min) {
	Graph g(N);
	double weight;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(i < j) {
				if(randomInRange(0.0, 1.0) < density) {
					weight = randomInRange(min, max);
					g.add(i, j, weight);
				}
			}
		}
	}
	return g;
}

//helper function for getNextEdges
//returns true if the integer value target is inside the inputed vector
bool contains(vector<int> v, int target) {
	for(int i=0; i<static_cast<int>(v.size()); i++) {
		if(v[i] == target) {
			return true;
		}
	}
	return false;
}

//helper function for Prim's algo.
//given a list of edges already visited, return the set of next avaiable edges in graph g
vector<Edge> getNextEdges(vector<Edge> start, Graph g) {
	vector<int> startVerts;
	vector<Edge> result;
	int verts = 0;
	int len = static_cast<int>(start.size());
	for(int i=0; i<len; i++) {
		if(!contains(startVerts, start[i].getSrc())) {
			startVerts.push_back(start[i].getSrc());
			verts++;
		}
		if(!contains(startVerts, start[i].getDest())) {
			startVerts.push_back(start[i].getDest());
			verts++;
		}
	}
	for(int i=0; i<verts; i++) {
		vector<int> neighbors = g.getNeighbors(startVerts[i]);
		for(int j=0; j<static_cast<int>(neighbors.size()); j++) {
			Edge e = g.getEdge(startVerts[i], neighbors[j]);
			if(!(contains(startVerts, e.getSrc()) && contains(startVerts, e.getDest()))) {
				result.push_back(e);
			}
		}
	}
	return result;
}


//Prim's MWST algorithm. Returns a graph object representing a minimum weight spanning tree of the input graph
Graph prim(Graph g, int src=0) {
	//keep track of the edges that are visited and therefore in the MWST as a vector of edges
	vector<Edge> visited;
	//get a list of all available neighbors from the src
	vector<int> startingNeighbors = g.getNeighbors(src);
	vector<Edge> startingEdges;
	for(int i=0; i<static_cast<int>(startingNeighbors.size()); i++) {
		//create a vector of edge objects based on the list of neighbors
		startingEdges.push_back(g.getEdge(src, startingNeighbors[i]));
	}
	//temporary priority queue, just to get the first edge in prims algo
	PQ startPq(startingEdges);
	visited.push_back(startPq.top());
	//core loop of the algorithm
	while(static_cast<int>(visited.size()) < g.V()-1) {
		//get a list of the edges that are available to choose from next
		//this means only the edges that are neighbors of already visited nodes
		//also, any edges that would create a cycle are left out
		vector<Edge> nextAvailableEdges = getNextEdges(visited, g);
		PQ pq(nextAvailableEdges);
		//add the min-valued edge from the available edges to the result and start over
		visited.push_back(pq.top());
	}
	//convert the vector of visited edges into a graph and return
	return static_cast<Graph>(visited);
}

int main() {
	srand(time(0));
	//create my test graph of 10 nodes
	Graph g(10);
	g.add(0, 1, 3.0);
	g.add(1, 2, 5.0);
	g.add(2, 3, 1.0);
	g.add(3, 4, 6.0);
	g.add(4, 9, 2.0);
	g.add(9, 8, 5.0);
	g.add(8, 7, 1.0);
	g.add(7, 6, 2.0);
	g.add(6, 5, 5.0);
	g.add(5, 0, 1.0);
	g.add(0, 6, 4.0);
	g.add(6, 2, 7.0);
	g.add(2, 8, 3.0);
	g.add(8, 4, 4.0);

	//run prim on my test graph
	Graph tree = prim(g);
	cout << "10 Node graph that I created. Expected weight of MWST: 21" << endl;
	cout << "Resulting MWST (adjacency list representation):" << endl;
	cout << tree;
	cout << endl << "Weight of the tree: " << tree.getGraphWeight() << endl << endl;

	//randomly generate 100 node graph and run prims algo on it.
	cout << "Randomly generated 100 node graph with density 0.1 and edge weights between 0.0 and 10.0:" << endl;
	Graph rand = generateGraph(0.1, MAX_DISTANCE, MIN_DISTANCE);
	Graph tree2 = prim(rand);
	cout << "Resulting MWST (adjacency list representation):" << endl;
	cout << tree2;
	cout << endl << "Weight of the tree: " << tree2.getGraphWeight() << endl << endl;
}
