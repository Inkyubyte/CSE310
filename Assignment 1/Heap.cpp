#include <iostream>
#include "program1.h"
#include <vector>
using std::vector;

// Attemped seperate Heap Class. Unused in final submission.
class Heap {
	private:
		int heapSize;
		int heapCapacity = 50;
		int numOfChildren;
		int parent(int child) {return int((child + numOfChildren - 2) / 4);}
        int child(int i, int j) {return ((i-1)* 4 + j + 1);
}
	public:
		void restoreDown(vector<int>& heapVector, int index, int numOfChildren, int len);
		vector<int> buildHeap(vector<int>& heapVector, int numOfChildren, int len);
		vector<int> heap;
		void printHeap() {
			for(int i = 1; i<= heap.size() - 1; i++)
				std::cout << heap[i] << " ";
		}
};



void Heap::restoreDown(vector<int>& heapVector, int index, int numOfChildren, int len) {
	// Root is largest for first go.
	int largest = index;

	while (index <= len) {
		// Find the largest child node
		for(int i = 1; i <= 4; i++) {
				int l = child(index, i);

				if (l > len)
					break;

				if (l <= len && heapVector[l] > heapVector[largest]) {
					largest = l;
					int temp = heapVector[index];
					heapVector[index] = heapVector[largest];
					heapVector[largest] = temp;
					restoreDown(heapVector, index, 4, len);
				}
		}
		index++;
	}
	return;
}

vector<int> Heap::buildHeap(vector<int>& heapVector, int numOfChildren, int len) {	
	for (int i = 1; i <= numOfChildren; i++) {
		restoreDown(heapVector, i, numOfChildren, len);
	}

	return heapVector;
}
