#include <iostream>

using namespace std;

int* MergeSort(int* array, int first, int last) {
    if (first < last) {
        int midpoint = (first + last) / 2;
        int *a1 = MergeSort(array, first, midpoint);
        int *a2 = MergeSort(array, midpoint + 1, last);
        int n1 = midpoint - first + 1;
        int n2 = last - midpoint;
        int i1 = 0, i2 = 0, i3 = 0;
        int *B = new int[n1+n2];
        while (i1 < n1 && i2 < n2) {
            if (a1[i1] < a2[i2]) {
                B[i3++] = a1[i1++];
            } else {
                B[i3++] = a2[i2++];
            }
        }
        while (i1 < n1) {
            B[i3++] = a1[i1++];
        }
        while (i2 < n2) {
            B[i3++] = a2[i2++];
        }
        return B;
    } else {
        return &array[first];
    }
}

int main() {
    int array[] = {19,4,24,12,6,9,0,12};
    int* sorted = MergeSort(array, 0, 7);

    for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
        cout << sorted[i] << endl;
    }
}