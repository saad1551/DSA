#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>

using namespace std;

// the sorter class to implement the algorithms
class Sorter {
private:
	// method to partition the array based on a pivot
	int Partition(int arr[], int first, int last) {
		// assigning the first number as the pivot
		int pivot = arr[first];
		// the low pointer to traverse from the beginning
		int low = first;
		// the high pointer to traverse from the end
		int high = last;
		while (low < high) {
			// increment the low pointer until you find a number greater than the pivot
			do {
				low++;
			} while (low < last && arr[low] <= pivot);
			// decrement the high pointer until you find a number less than the pivot
			while (arr[high] >= pivot && high > first) {
				high--;
			}
			// swap the elements on the low and high pointers provided low is still to the left of high
			if (low < high) {
				int temp = arr[low];
				arr[low] = arr[high];
				arr[high] = temp;
			}
		}
		// swap the element at the high pointer with the pivot
		int temp = arr[high];
		arr[high] = pivot;
		arr[first] = temp;
		// return the partitioning point
		return high;
	}
public:
	// the method to implemenet quick sort on an array
	void QuickSort(int arr[], int first, int last) {
		if (first < last) {
			int midpoint = Partition(arr, first, last);
			QuickSort(arr, first, midpoint);
			QuickSort(arr, midpoint + 1, last);
		}
	}

	// the method to implement counting sort on an array
	void CountingSort(int array[], int size) {
		// the code to find the maximum element (range) of the array
		int max = array[0];
		for (int i = 1; i < size; i++) {
			if (array[i] > max) {
				max = array[i];
			}
		}

		// declaring an array to store the number of occurences of each element from 0 till max in the orginal array
		int* count = new int[max + 1];

		//setting all the counts to 0
		for (int i = 0; i <= max; i++) {
			count[i] = 0;
		}

		//iterating through the original array and updating the counts in the count array
		for (int i = 0; i < size; i++) {
			count[array[i]]++;
		}

		// updating the count array so that it now stores the cumulative frequencies
		for (int i = 1; i <= max; i++) {
			count[i] += count[i - 1];
		}

		//declaring an output array equal to the size of the original array
		int* output = new int[size];

		// iterating through the original array from the end and storing each element in its position in the output array
		for (int i = size - 1; i >= 0; i--) {
			output[--count[array[i]]] = array[i];
		}

		// copying the output array back into the original array
		for (int i = 0; i < size; i++) {
			array[i] = output[i];
		}

	}
};

int main() {
	// initializing the random number generator with the current time seed
    srand(time(0));

    // declaring the size of the random arrays
    const int size = 100000;

    cout << "Testing the algorithms against random arrays of size " << size << endl
         << endl;

    // creating a Sorter object
    Sorter sorter;

    // implementing Quick Sort
    cout << "Implementing Quick Sort took ";
    // declaring an array
    int array1[size];
    for (int i = 0; i < size; i++)
    {
        array1[i] = rand() % 100;
    }
     // sorting the array in ascending order for the best case
    sort(array1, array1 + size);
    // calling the quick sort method of the Sorter and computing the time it takes to sort the array in the best case
    clock_t startTime = clock();
   	sorter.QuickSort(array1, 0, size - 1);
    cout << double(clock() - startTime) / CLOCKS_PER_SEC * 1000 << " milliseconds in the best case, ";

    // sorting the array in descending order for the worst case
    sort(array1, array1 + size, (greater<int>()));
    // calling the quick sort method of the Sorter and computing the time it takes to sort the array in the worst case
    startTime = clock();
    sorter.QuickSort(array1, 0, size - 1);
    cout << double(clock() - startTime) / CLOCKS_PER_SEC * 1000 << " milliseconds in the worst case" << endl;

	// implementing Counting Sort
    cout << "Implementing Counting Sort took ";
    // declaring an array
    int array2[size];
    for (int i = 0; i < size; i++)
    {
        array2[i] = rand() % 100;
    }
     // sorting the array in ascending order for the best case
    sort(array2, array2 + size);
    // calling the counting sort method of the Sorter and computing the time it takes to sort the array in the best case
    startTime = clock();
   	sorter.CountingSort(array2, size);
    cout << double(clock() - startTime) / CLOCKS_PER_SEC * 1000 << " milliseconds in the best case, ";

    // sorting the array in descending order for the worst case
    sort(array1, array1 + size, (greater<int>()));
    // calling the counting sort method of the Sorter and computing the time it takes to sort the array in the worst case
    startTime = clock();
    sorter.CountingSort(array2, size);
    cout << double(clock() - startTime) / CLOCKS_PER_SEC * 1000 << " milliseconds in the worst case" << endl;
}