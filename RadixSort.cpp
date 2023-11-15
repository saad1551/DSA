#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class RadixSort {
private:
    vector <int> Bins[10];
    int power(int base, int exp) {
        int ans = 1;
        for (int i = 0; i < exp; i++) {
            ans *= base;
        }
        return ans;
    }

public:
    void Sort(int arr[], int size, int k) {
        for (int i = 0; i < k; i++) {
            int n = power(10, i);
            for (int j = 0; j < size; j++) {
                Bins[(arr[j] / n) % 10].push_back(arr[j]);
            }
            int index = 0;
            for (int j = 0; j < 10; j++) {
                for (int l = 0; l < Bins[j].size(); l++) {
                    arr[index++] = Bins[j][l];
                }
                Bins[j].clear();
            }
        }
    }
};

int main(void) {
    int array[7] = {12,41,13,5,9,6,3};
    RadixSort sorter;
    sorter.Sort(array, 7, 3);
    for (int i = 0; i < 7; i++) {
        cout << array[i] << endl;
    }
}