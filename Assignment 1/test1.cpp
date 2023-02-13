#include "program1.h"
#include "program1.cpp"
#include <iostream>
#include <vector>
#include <string>
#include "Heap.cpp"
using std::vector;

/* You may use this file to test your program.
	This file will not be submitted, as a different test1.cpp will be used. */


int main(int argv, char **argc) {
	//vector<int> heap = {0, 21, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};

	//Heap myHeap;
	//myHeap.heap = myHeap.buildHeap(heap, 4, heap.size() - 1);
	//myHeap.printHeap();

	std::cout << "\n";
	for(int i = 1; i <= heapNodes.size() - 1; i++) {
		std::cout << heapNodes[i].val << " ";
	}

	AddJob(17);
	std::cout << "\n";
	for(int i = 1; i <= heapNodes.size() - 1; i++) {
		std::cout << heapNodes[i].val << " ";
	}
	AddJob(12);
	std::cout << "\n";
	for(int i = 1; i <= heapNodes.size() - 1; i++) {
		std::cout << heapNodes[i].val << " ";
	}
	AddJob(12);
	std::cout << "\n";
	for(int i = 1; i <= heapNodes.size() - 1; i++) {
		std::cout << heapNodes[i].val << " ";
	}
	AddJob(9);
	std::cout << "\n";
	for(int i = 1; i <= heapNodes.size() - 1; i++) {
		std::cout << heapNodes[i].val << " ";
	}
	AddJob(22);
	std::cout << "\n";
	for(int i = 1; i <= heapNodes.size() - 1; i++) {
		std::cout << heapNodes[i].val << " ";
	}

	int depth = GetDepth(22);

	std::cout << "\n";
	std::cout << depth << " ";


	return 0;
}