#include "program3.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> hashTable;
int primaryHash, secondaryHash;
int totalCollisions = 0;

// Testing Function
void generateArray(int arr[]) {
	for (int i = 0; i < ARRAY_SIZE; i++)
		arr[i] = rand() % 101;
}

int primaryHashFunction(int input) {
	int hashIndex;
	switch (primaryHash) {
		case 1:		hashIndex = int((53 * (int(0.2897 * input) % 1)));
					break;
		case 2:		hashIndex = input % hashTable.size();
					break;
		case 3:		hashIndex = input % 53;
					break;
		case 4: 	hashIndex = input % 48;
					break;
		case 5:		hashIndex = 1;
					break;
	}

	return hashIndex;
}

int secondaryHashFunction(int input) {
	int hashIndex;
	switch (secondaryHash) {
		case 1:		hashIndex = int((52 * (int(0.2897 * input) % 1)));
					break;
		case 2:		hashIndex = input % (hashTable.size() - 1);
					break;
		case 3:		hashIndex = input % 52;
					break;
		case 4: 	hashIndex = input % 47;
					break;
		case 5:		hashIndex = 1;
					break;
	}

	return hashIndex;
}

// Sets the size of the hash table.  Returns if it succeeded.
bool SetHashTableSize(int n) {
	if (n <= 0)
		return false;

	hashTable.resize(n, -1);
	hashTable[0] = -1;

	return true;
}

// Sets the primary and secondary hash functions for hashing.  Returns if it succeeded.
bool SetHashFunctions(int f, int s) {
	if (f < 1 || s > 5)
		return false;
	if (f > 5 || s < 1)
		return false;

	primaryHash = f;
	secondaryHash = s;

	return true;
}

// Loads the data from the array into the hash table.  Returns the number of values added.
int LoadData(int a[ARRAY_SIZE]) {
	int numOfVals = 0;
	for(int i = 0; i < hashTable.size(); i++) {
		if(a[i] < 0)
			break;
		bool addBool = AddValue(a[i]);

		if (addBool == true)
			numOfVals += 1;
	}

	return numOfVals;
}

// Adds the key to the hash table.  Returns if it succeeded.
bool AddValue(int key) {
	if (key < 0 || hashTable.size() == 0)
		return false;

	for(int i = 0; i < MAX_COLLISIONS; i++) {
		int hashPos = (primaryHashFunction(key) + (i * secondaryHashFunction(key)));
		
		if (key > hashTable.size())
			hashPos = (primaryHashFunction(key) + (i * secondaryHashFunction(key))) % hashTable.size();
		
		if (hashTable[hashPos] == -1) {
			hashTable[hashPos] = key;
			return true;
		}
		totalCollisions += 1;
	}
	return false;
}

// Removes the key from the hash table.  Returns the index that the key was stored in.
int RemoveValue(int key) {
	if (hashTable.size() == 0)
		return INVALID_CALL;

	int returnIndex;

	for(int i = 0; i <= MAX_COLLISIONS; i++) {
		int hashPos = (primaryHashFunction(key) + (i * secondaryHashFunction(key)));
		
		if (key > hashTable.size())
			hashPos = (primaryHashFunction(key) + (i * secondaryHashFunction(key))) % hashTable.size();
		
		if (hashTable[hashPos] == key) {
			returnIndex = hashPos;
			hashTable[hashPos] == -1;
			return returnIndex;
		}
	}

	return NO_LOCATION;
}

// Finds the key in the hash table and returns its index.
int GetHashTableLocation(int key) {
	if (hashTable.size() == 0)
		return INVALID_CALL;

	for(int i = 0; i <= MAX_COLLISIONS; i++) {
		int hashPos = (primaryHashFunction(key) + (i * secondaryHashFunction(key))) % hashTable.size();
		if (hashTable[hashPos] == key)
			return hashPos;
		if (i == 5)
			break;
	}
	return NO_LOCATION;
}

// Returns the number of collisions that have occurred since the hash table was set up.
int GetNumberOfCollisions() {
	if (hashTable.size() == 0)
		return INVALID_CALL;
	
	return totalCollisions;
}

//#endif