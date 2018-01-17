#include <iostream>
#include <vector>
#include"Edge.h"
using namespace std;

//Please note that all of these functions have a short commented description inside Graph.cpp

class Graph {
	friend ostream& operator<<(ostream& out, const Graph& g);
	public:
		Graph();
		Graph(int n);
		Graph(vector<Edge> e); //conversion constructor from a vector of edges.
		int neighborCount(int n);
		void add(int x, int y, double w=static_cast<double>(UNDEFINED));
		void remove(int x, int y);
		double getEdgeWeight(int x, int y);
		void setEdgeWeight(int x, int y, double w);
		vector<int> getNeighbors(int n);
		bool adjacent(int x, int y);
		vector<Edge> getEdges();
		int V();
		int E();
		Edge getEdge(int x, int y);
		double getGraphWeight();
	private:
		vector<vector<int>> adj;
		vector<Edge> edges;
		int numEdges;
		int numVerts;
};
