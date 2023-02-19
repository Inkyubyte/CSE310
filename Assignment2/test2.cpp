#include <stdlib.h>
#include "program2.h"
#include "program2.cpp"
#include <iostream>

/* You may use this file to test your program.
	This file will not be submitted, as a different test2.cpp will be used. */
int main(int argv, char **argc) {
	int testSort2[11] = {4,6,5,4,3,2,1,3,2,1,0};
	int testSort[5] = {4,11,10,10,14};

	std::cout << "Starting Values: ";
	for(int value = 0; value < 5; value++) {
		std::cout << testSort[value] << " ";
	}

	int countingSortIndex = GetStatistic(1,1);

	std::cout << "\n" << countingSortIndex;



	GetSortedOrder(testSort, 1, 0);

	std::cout << "\nEnding Values: ";
	for(int value = 0; value < 5; value++) {
		std::cout << testSort[value] << " ";
	}

	countingSortIndex = GetStatistic(1,0);

	std::cout << "\n" << countingSortIndex;



	exit(0);
}
