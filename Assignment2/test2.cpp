#include <stdlib.h>
#include "program2.h"
#include "program2.cpp"
#include <iostream>

/* You may use this file to test your program.
	This file will not be submitted, as a different test2.cpp will be used. */
int main(int argv, char **argc) {
	int testSort[11] = {4,550,1229,41,331,2,1,3,2,1,0};
	int testSort2[6] = {5,5,4,3,2,1};

	std::cout << "Starting Values: ";
	for(int value = 0; value < 6; value++) {
		std::cout << testSort2[value] << " ";
	}

	int countingSortIndex = GetStatistic(1,1);

	std::cout << "\n" << countingSortIndex;



	GetSortedOrder(testSort2, 2, 2);

	std::cout << "\nEnding Values: ";
	for(int value = 0; value < 6; value++) {
		std::cout << testSort2[value] << " ";
	}

	countingSortIndex = GetStatistic(1,0);

	std::cout << "\n" << countingSortIndex;



	exit(0);
}
