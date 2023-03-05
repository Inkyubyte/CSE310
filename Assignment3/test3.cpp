#include "program3.h"
#include "program3.cpp"

/* You may use this file to test your program.
	This file will not be submitted, as a different test3.cpp will be used. */
int main(int argv, char **argc) {
	int arr[ARRAY_SIZE];
	generateArray(arr);

	SetHashTableSize(5);

	for (int i = 0; i < hashTable.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";

	SetHashFunctions(0, 0);
	LoadData(arr);

	for(auto i : hashTable)
		std::cout << i << " ";

	return 0;
}