#include "program3.h"

// Sets the size of the hash table.  Returns if it succeeded.
bool SetHashTableSize(int n) {
	return false;
}

// Sets the primary and secondary hash functions for hashing.  Returns if it succeeded.
bool SetHashFunctions(int f, int s) {
	return false;
}

// Loads the data from the array into the hash table.  Returns the number of values added.
int LoadData(int a[ARRAY_SIZE]) {
	return 0;
}

// Adds the key to the hash table.  Returns if it succeeded.
bool AddValue(int key) {
	return false;
}

// Removes the key from the hash table.  Returns the index that the key was stored in.
int RemoveValue(int key) {
	return INVALID_CALL;
}

// Finds the key in the hash table and returns its index.
int GetHashTableLocation(int key) {
	return INVALID_CALL;
}

// Returns the number of collisions that have occurred since the hash table was set up.
int GetNumberOfCollisions() {
	return INVALID_CALL;
}

#endif
