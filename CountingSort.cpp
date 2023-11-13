#include <iostream>

using namespace std;

void CountingSort(int arr[], int size) {
    // finding the max element of the array
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int* count = new int[max + 1];

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }
    

    int *output = new int[size];

    //storing the count of occurences of each element in the array
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    //storing the cumulative counts of each element
    for (int i = 1; i <= max; i++) {
        count[i] += count[i-1];
    }

    //traversing the array from back and storing each element at its posititon in the output array
    for (int i = size - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    //copying the output array into the original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

int main(void) {
    int arr[12] = {12,3,6, 9, 4, 2, 1, 14, 8, 3, 2, 0};
    int size = 12;

    CountingSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}