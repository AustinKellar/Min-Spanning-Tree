#include <iostream>
#include <vector>
#include"PQ.h"
using namespace std;

//helper function for priority queue object
//sorts a vector of edges by their weight values
void sortQueue(vector<Edge>& queue) {
	int i, j, minIndex;
	int size = static_cast<int>(queue.size());
	for(i=0; i<size; i++) {
		minIndex = i;
		for(j=i+1; j<size; j++) {
			if(queue[j].getWeight() < queue[minIndex].getWeight()) {
				minIndex = j;
			}
		}
		Edge temp = queue[i];
		queue[i] = queue[minIndex];
		queue[minIndex] = temp;
	}
}

//default constructor
PQ::PQ() {
	size = 0;
}

//conversion constructor: create a priority queue out of the edge set of a graph
PQ::PQ(Graph g) {
	queue = g.getEdges();
	size = g.E();
	sortQueue(queue);
}

//conversion constructor: create priority queue out of a set of edges
PQ::PQ(vector<Edge> e) {
	queue = e;
	size = static_cast<int>(e.size());
	sortQueue(queue);
}

//returns true if the queue contains edge x->y
bool PQ::contains(int x, int y) {
	for(int i=0; i<size; i++) {
		if((queue[i].getSrc() == x && queue[i].getDest() == y) || (queue[i].getSrc() == y && queue[i].getDest() == x)) {
			return true;
		}
	}
	return false;
}

//insert edge e into the priority queue
void PQ::insert(Edge e) {
	queue.push_back(e);
	sortQueue(queue);
	size++;
}

//change the priority (weight) of edge x->y to weight w
void PQ::changePriority(int x, int y, double w) {
	for(int i=0; i<size; i++) {
		if((queue[i].getSrc() == x && queue[i].getDest() == y) || (queue[i].getSrc() == y && queue[i].getDest() == x)) {
			queue[i].setWeight(w);
		}
	}
	sortQueue(queue);
}

//returns and deletes the element of lowest priority in the queue
Edge PQ::minPriority() {
	Edge e = queue[0];
	queue.erase(queue.begin());
	size--;
	return e;
}

//returns the element of lowest priority in the queue
Edge PQ::top() {
	return queue[0];
}

//returns the number of elements in the queue
int PQ::getSize() {
	return size;
}

//prints the queue. only used this for quick testing
void PQ::print() {
	for(int i=0; i<size; i++) {
		if(i < size-1) {
			cout << queue[i] << ", ";
		} else {
			cout << queue[i] << endl;
		}
	}
}
