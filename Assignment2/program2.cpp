#include "program2.h"
#include <vector>
#include <iostream>
using std::vector;

int countSortCountIndex = -1;

// Resets the heap to be empty.
int* GetSortedOrder(int a[MAX_ARRAY_SIZE], int sortType, int base) {
	if(sortType != 1 && sortType != 2 && sortType !=3) {
		return nullptr;
	}
	
	if (sortType == 1) {
		vector<int> countArray(MAX_ARRAY_SIZE + 1, 0);

    	// Cycle through array. Increment values in 
    	// countArray based on a[value].
		for(int value = 0; value < 11; value++) {
			countArray[a[value]] += 1;
		}

		int countIndex = 0;
		for(int i = 0; i < MAX_ARRAY_SIZE - 1; i++) {
			while(countArray[i] > 0) {
				a[countIndex] = i;
				countArray[i]--;
				countIndex++;
			}
		}

		countSortCountIndex = countIndex;
	}

	return a;
}

// Returns the statistic the last time the sort was done using the specified sort type.
int GetStatistic(int sortType, int bucketNumber) {
	switch (sortType) {
		case 1:		if (countSortCountIndex == -1)
						return NO_SORT;
					return countSortCountIndex;

		default:	return NO_SORT;

	}

	return 0;
}
