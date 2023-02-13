#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using std::vector;

class CountingSort {
    private:
        vector<int> classVector;
    public:
        CountingSort(vector<int> classVector) {
            this->classVector = classVector;
        }
        vector<int> getVector();
        vector<int> sort();

};

vector<int> CountingSort::sort() {
    int min = *min_element(classVector.begin(), classVector.end());
    int max = *max_element(classVector.begin(), classVector.end());

    vector<int> countArray(max - min + 1, 0);

    // Cycle through vector. Increment values in 
    // countArray based on vector[value].
    for(int value : classVector) {
        countArray[value - min] += 1;
    }
    int countIndex = 0;
    for(int i = 0; i < max - min + 1; i++) {
        while(countArray[i] > 0) {
            classVector[countIndex] = i + min;
            countArray[i]--;
            countIndex++;
        }
    }

    return classVector;
}

vector<int> CountingSort::getVector() {
    return classVector;
}