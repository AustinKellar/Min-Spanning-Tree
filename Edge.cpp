#include <iostream>
#include"Edge.h"
using namespace std;

//default constructor
Edge::Edge() {
	src = dest = UNDEFINED;
	weight = static_cast<double>(UNDEFINED);
}

//usual constructor for the edge object
Edge::Edge(int s, int d, double w) {
	src = s;
	dest = d;
	weight = w;
}

//returns source vertex of the edge
int Edge::getSrc() {
	return src;
}

//returns destination vertex of the edge
int Edge::getDest() {
	return dest;
}

//returns weight of the edge
double Edge::getWeight() {
	return weight;
}

//sets the weight of the edge
void Edge::setWeight(double w) {
	weight = w;
}

ostream& operator<<(ostream& out, const Edge& e) {
	out << "(" << e.src << " -- " << "[" << e.weight << "]" << " --> " <<e.dest << ")";
	return out;
}
