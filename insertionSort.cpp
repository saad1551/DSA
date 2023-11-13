#include <iostream>

using namespace std;

int* InsertionSort(int array[], int size) {
    for (int i = 0; i < size; i++){
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;

    }
    return array;
}

int main() {
    int array[] = {9,2,14,25,4,19,13};
    int size = sizeof(array) / sizeof(int);
    int *sorted = InsertionSort(array, size);
    for (int i = 0; i < size; i++) {
        cout << sorted[i] << endl;
    }
}