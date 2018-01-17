#include <iostream>
#include <vector>
#include"Graph.h"
using namespace std;

//Priority Queue Class
//This priority queue was made to store edges and use their weights as priority keys
//Please note that each of these functions has a short description inside PQ.cpp

class PQ {
	public:
		PQ();
		PQ(Graph g);
		PQ(vector<Edge> e);
		bool contains(int x, int y);
		void insert(Edge e);
		void changePriority(int x, int y, double w);
		Edge minPriority();
		Edge top();
		int getSize();
		void print();
	private:
		vector<Edge> queue;
		int size;
};
