#include <iostream>
using namespace std;
const int UNDEFINED = -1;

//Edge Class
//This class is supposed to represent an edge (x->y) in a graph
//imagine src is x and dest is y and the edge has weight w

//Please note that each function has a short description inside Edge.cpp

class Edge {
	friend ostream& operator<<(ostream& out, const Edge& e);
	public:
		Edge();
		Edge(int s, int d, double w=UNDEFINED);
		int getSrc();
		int getDest();
		double getWeight();
		void setWeight(double w);
	private:
		int src;
		int dest;
		double weight;
};
