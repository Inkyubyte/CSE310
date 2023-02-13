#include <iostream>
#include "program1.h"
#include <vector>
#include "math.h"
using std::vector;


struct heapNode {
	int val;
	int priority;
	int jobTracker;
};

typedef heapNode node;

vector<node> heapNodes(22);


// Helper function to find child.
int child(int i, int j) {
	return ((i-1)* 4 + j + 1);
}

// Helper function to find parent.
int parent(int child) {
	return int((child + 4 - 2) / 4);
}

// BuildHeap class to intialize heap before main call.
class BuildHeap {
public:
	//Constructor to call build heap
	BuildHeap() {
		if(!heapNodes.empty())
			buildHeap(4, heapNodes.size() - 1);
	}
	void restoreDown(int index, int numOfChildren, int len) {
		// Root is largest for first go.
		int largest = index;
		while (index <= len) {
			// Find the largest child node
			for(int i = 1; i <= 4; i++) {
					int l = child(index, i);
					if (l > len)
						break;
					if (l <= len && heapNodes.at(l).priority > heapNodes.at(largest).priority) {
						largest = l;
						node temp = heapNodes[index];
						heapNodes[index] = heapNodes[largest];
						heapNodes[largest] = temp;
						restoreDown(index, 4, len);
					}				
			}
			index++;
		}
		return;
	}	
	void buildHeap(int numOfChildren, int len) {
		for(int i = 0; i <= heapNodes.size() - 1; i++) {
			heapNodes[i].val = i;
			heapNodes[i].priority = i;
			heapNodes[i].jobTracker = 0;
		}
		for (int i = 1; i <= numOfChildren; i++) {
			restoreDown(i, numOfChildren, len);
		}
	}
};

BuildHeap heap;

void restoreDown(int index, int numOfChildren, int len) {
	if(index > len || heapNodes.size() == 1 || heapNodes.empty())
	    return;


	// Root is largest for first go.
	int largest = index;

	

	while (index <= len) {
		// Find the largest child node
		for(int i = 1; i <= 4; i++) {
				int l = child(index, i);

				if (l > (heapNodes.size() - 1))
					break;

				if (l <= len && heapNodes[l].priority > heapNodes[largest].priority) {
					largest = l;
					node temp = heapNodes[index];
					heapNodes[index] = heapNodes[largest];
					heapNodes[largest] = temp;
					restoreDown(index, 4, len);
				}
				
		}
		index++;
	}
	return;
}
	
void buildHeap(int numOfChildren, int len) {
	for (int i = 1; i <= numOfChildren; i++) {
		restoreDown(i, numOfChildren, len);
	}
}

void JobTracker() {

	for(int i = 1; i <= heapNodes.size() - 1; i++) {
		heapNodes[i].jobTracker += 1;
		if(heapNodes[i].jobTracker >= 5)
			heapNodes[i].priority += 2;

	}
	restoreDown(1, 4, heapNodes.size() - 1);

}

// Resets the heap to be empty. 
void EmptyHeap() {
	heapNodes.clear();
}

// Adds a job to the heap with the specified priority.
void AddJob(int priority) {

	if(priority <= 0)
		return;

	if(heapNodes.empty()) {
		heapNodes.resize(2);
		heapNodes[0].priority = 0;
		heapNodes[0].val = 0;
		heapNodes[1].priority = priority;
		heapNodes[1].val = priority;
		heapNodes[1].jobTracker = 0;
		return;
	}
	//Change size of vector
	heapNodes.resize(heapNodes.size() + 1);

	int index = heapNodes.size() - 1;

	// Run through the entire tree. If the parent has less priority than child
	// then swap them.
	while (index > 1 && heapNodes[parent(index)].priority < priority) {	
		heapNodes[index] = heapNodes[parent(index)];
		// New index is where previous parent position was.
		index = parent(index);
	}
	heapNodes[index].priority = priority;
	heapNodes[index].val = priority;
	heapNodes[index].jobTracker = 0;
}

// Removes the job at the top of the heap and returns its priority.
int GetJob() {

	if(heapNodes.empty() || heapNodes.size() == 1)
		return NO_JOB;

	// Used for returning job priority
	int topJobHotDog = heapNodes[1].priority;

	
	// Make removed node = last node and sort.
	heapNodes[1] = heapNodes[heapNodes.size() - 1];
	heapNodes.resize(heapNodes.size() - 1);

	restoreDown(1, 4, heapNodes.size() - 1);

	JobTracker();

	return topJobHotDog;
}

// Returns the depth of the first job found with the specified priority.
int GetDepth(int priority) {

	if (heapNodes.size() == 1 || heapNodes.empty() || priority <= 0)
		return NO_DEPTH;
	
	// Return 0 if root node.
	if (priority == heapNodes[1].priority)
		return 0;

	if(parent(priority) == 1)
		return 1;
	
	int parentCounter = 0;

	int index = priority;

	while(index > 1) {
		parentCounter += 1;
		index = parent(index);
	}

	return parentCounter;
}

// Returns the priority of the job with the specified index.
int GetPriority(int index) {
	if (heapNodes.empty() || heapNodes.size() == 1 || index > heapNodes.size() - 1)
		return NO_PRIORITY;
	
	int prio;

	for(int i = 1; i <= heapNodes.size() - 1, i++;)
		if(i == heapNodes[index].priority)
			return heapNodes[index].priority;

	return NO_PRIORITY;
}