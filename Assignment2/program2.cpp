#include "program2.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
using std::vector;

vector<int> countSortTracker(1, -1);
int testDigit = 0;

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

void RadixSort(int a[MAX_ARRAY_SIZE], int exp, int base) {
	// Declare arrays
	int countArray[base]; // Base is the number of possible unique numbers in a system
	int outputArray[a[0] + 1];

	// Intialise C array for adding purposes and avoid errors.
	for (int i = 0; i < base; i++)
		countArray[i] = 0;

	// Counting sort but looking at specific digit determined by #-base.
	for (int i = 1; i < a[0] + 1; i++)
		countArray[(a[i] / exp) % base] += 1;

	// Make countArray = position rather than the number of elements.
	for (int i = 1; i < base; i++)
		countArray[i] += countArray[i - 1];

	// Put numbers in output array according to position in countArray.
	for(int i = a[0]; i >= 1; i--) {
		outputArray[countArray[(a[i] / exp) % base] - 1] = a[i];
		countArray[(a[i] / exp) % base] -= 1;
	}
	
	// Make a[] = outputArray
	for (int i = 1; i < a[0] + 1; i++)
		a[i] = outputArray[i - 1];

}

// Resets the heap to be empty.
int* GetSortedOrder(int a[MAX_ARRAY_SIZE], int sortType, int base) {
	if(sortType != 1 && sortType != 2 && sortType !=3) {
		return nullptr;
	}

	// Check to see if array is valid
	for(int i = 1; i < a[0] + 1; i++)
		if (a[i] <= 0)
			return NULL;

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

		// Count Index is 1 to avoid overwriting value at A[0]
		int countIndex = 1;

		// Make array = to the values store i countArray
		for(int i = 0; i < max - min + 1; i++) {
			while(countArray[i] > 0) {
				a[countIndex] = i + min;
				countArray[i]--;
				countIndex++;
			}
		}
	}

	if (sortType == 2) {

		

		// Wrapper loop to iterate through digits.
		for (int exp = 1; max/exp > 0; exp *= base) {
			RadixSort(a, exp, base);
			testDigit += 1;
		}
	}

	return a;
}

// Returns the statistic the last time the sort was done using the specified sort type.
int GetStatistic(int sortType, int bucketNumber) {
	if (bucketNumber < 0)
		return 0;


	switch (sortType) {
		case 1:		if (countSortTracker[0] == -1 && testDigit == 0)
						return NO_SORT;
					
					return countSortTracker[bucketNumber];

		default:	return NO_SORT;

	}

	return 0;
}
