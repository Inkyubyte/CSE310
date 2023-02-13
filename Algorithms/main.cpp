#include <iostream>
#include <vector>
#include "CountingSort.cpp"
#include "RadixSort.cpp"
using std::vector;


int main() {
    vector<int> testSortList = {555,245,133,121,10,25,221,199,944,206,103,955};

    testSortList = CountingSort(testSortList).sort();

    std::cout << "\n";
    for(int i : testSortList) {
        std::cout << i << " ";
    }
    

    return 0;
}