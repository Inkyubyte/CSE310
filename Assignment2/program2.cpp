#include "program2.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
using std::vector;

vector<int> countSortTracker(1, -1);

int findMin(int a[]) {
	int min = a[1];
	for(int i = 1; i < a[0] + 1; i++)
    {
        if(min > a[i])
			min = a[i]; 
	}

	return min;
}

int findMax(int a[]) {
	int max = a[1];
	for(int i = 1; i < a[0] + 1; i++)
    {
        if(max < a[i])
			max = a[i]; 
	}

	return max;
}

// Resets the heap to be empty.
int* GetSortedOrder(int a[MAX_ARRAY_SIZE], int sortType, int base) {
	if(sortType != 1 && sortType != 2 && sortType !=3) {
		return nullptr;
	}

	int min, max;

	min = findMin(a);
	max = findMax(a);

	//std::cout << "\n" << min;
	//std::cout << "\n" << max;
	
	if (sortType == 1) {
		vector<int> countArray(max - min + 1);

    	// Cycle through array. Increment values in 
    	// countArray based on a[value].
		for(int value = 1; value < a[0] + 1; value++) {
			countArray[a[value] - min] += 1;
		}
		
		countSortTracker = countArray;

		int countIndex = 1;
		for(int i = 0; i < max - min + 1; i++) {
			while(countArray[i] > 0) {
				a[countIndex] = i + min;
				countArray[i]--;
				countIndex++;
			}
		}
	}

	return a;
}

// Returns the statistic the last time the sort was done using the specified sort type.
int GetStatistic(int sortType, int bucketNumber) {
	switch (sortType) {
		case 1:		if (countSortTracker[0] == -1)
						return NO_SORT;
					
					return countSortTracker[bucketNumber];

		default:	return NO_SORT;

	}

	return 0;
}
