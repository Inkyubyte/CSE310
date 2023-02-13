#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using std::vector;

class RadixSort {
    private:
        vector<int> classVector;
        void actualSort(int digit);
    public:
        RadixSort(vector<int> classVector) {
            this->classVector = classVector;
        }
        vector<int> getVector();
        vector<int> sort();
        void actualsort();
};

vector<int> RadixSort::getVector() {
    return classVector;
}

void RadixSort::actualSort(int digit) {
    // Create count array with 0's
    vector<int> countArray(10, 0);

    // Cycle through vector. For each value store it in the
    // corresponding index in the countArray;
    for(int value : classVector) {
        countArray[(value / digit) % 10] += 1;
    }

    for(int i : countArray) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    int countIndex = 0;
    for(int i = 0; i < 10 ; i++) {
        while(countArray[i] > 0) {
            classVector[countIndex] = i;
            countArray[(classVector[i] / digit) % 10]--;
            countIndex++;
        }
    }

}

// Radix sort for Positive integer elements
vector<int> RadixSort::sort() {
    int max = *max_element(classVector.begin(), classVector.end());
    for(int digit = 1; max/digit > 0; digit *= 10)
        actualSort(digit);
    return classVector;
}

