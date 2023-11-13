#include <iostream>

using namespace std;

class QuickSort {
public:
    void Sort(int array[], int l, int h) {
        int pivot = array[l];
        if (l < h) {
            int i = l;
            int j = h;
            while (i < j) {
                do {
                    i++;
                } while (array[i] <= pivot);
                while (array[j] > pivot) {
                    j--;
                }
                if (i < j) {
                    int temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                }
            }
            int temp = array[l];
            array[l] = array[j];
            array[j] = temp;
            Sort(array, l, j);
            Sort(array, j + 1, h);
        }
    }
};

int main(void) {
    int array[] = {48,70,5,85,45,2,1,0,36,14};
    QuickSort Sorter;
    Sorter.Sort(array, 0, sizeof(array) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
        cout << array[i] << endl;
    }
}