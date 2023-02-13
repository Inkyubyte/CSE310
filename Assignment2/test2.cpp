#include <stdlib.h>
#include "program2.h"
#include "program2.cpp"
#include <iostream>

/* You may use this file to test your program.
	This file will not be submitted, as a different test2.cpp will be used. */
int main(int argv, char **argc) {
	int testSort[10] = {7,7,7,7,7,7,7,7,3,2};

	std::cout << "Starting Values: ";
	for(int value = 0; value < MAX_ARRAY_SIZE; value++) {
		std::cout << testSort[value] << " ";
	}


	GetSortedOrder(testSort, 1, 0);

	std::cout << "\nEnding Values: ";
	for(int value = 0; value < MAX_ARRAY_SIZE; value++) {
		std::cout << testSort[value] << " ";
	}

	int countingSortIndex = GetStatistic(1,0);

	std::cout << "\n" << countingSortIndex;


	exit(0);
}
