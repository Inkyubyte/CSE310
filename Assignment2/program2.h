#ifndef PROGRAM2_H
#define PROGRAM2_H

// Constants that should be used when implementing your code.
#define MAX_ARRAY_SIZE	11	// Maximum size of the array
#define MAX_VALUE	100	// Maximum value that can be passed in
#define NO_SORT		-1	// No valid call to GetSortedOrder has been made yet
#define ALL_DIGITS	-2	// Indicates all digits/buckets should be included

// Remove for public release
#define NULL_ARRAY	-50	// Array is null, used only in testing

/*** Below is the list of functions that must be implemented by the program. ***/

// Resets the heap to be empty.
int* GetSortedOrder(int a[MAX_ARRAY_SIZE], int sortType, int base);

// Returns the statistic the last time the sort was done using the specified sort type.
int GetStatistic(int sortType, int bucketNumber);


#endif
