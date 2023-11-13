#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Sorter
{
public:
    // sorting the array using Bubble Sort, the function takes an array and the size of the array as parameters
    int *BubbleSort(int *a, int size)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        return a;
    }

    // sorting the array using Selection Sort, the function takes an array and the size of the array as parameters
    int *SelectionSort(int *a, int size)
    {
        for (int i = size - 1; i > 0; i--)
        {
            int max = i;
            for (int j = 0; j < i - 1; j++)
            {
                if (a[j] > a[max])
                {
                    max = j;
                }
            }
            int temp = a[i];
            a[i] = a[max];
            a[max] = temp;
        }
        return a;
    }

    int *InsertionSort(int *a, int size)
    {
        for (int i = 1; i < size; i++)
        {
            int key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > key)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
        return a;
    }

    int *MergeSort(int *a, int first, int last)
    {
        if (first < last)
        {
            int midpoint = (first + last) / 2;
            int *arr1 = MergeSort(a, first, midpoint);
            int *arr2 = MergeSort(a, midpoint + 1, last);
            int n1 = midpoint - first + 1;
            int n2 = last - midpoint;
            int *B = new int[n1 + n2];
            int i1 = 0, i2 = 0, i3 = 0;
            while (i1 < n1 && i2 < n2)
            {
                if (arr1[i1] < arr2[i2])
                {
                    B[i3++] = arr1[i1++];
                }
                else
                {
                    B[i3++] = arr2[i2++];
                }
            }
            while (i1 < n1)
            {
                B[i3++] = arr1[i1++];
            }
            while (i2 < n2)
            {
                B[i3++] = arr2[i2++];
            }
            return &B[0];
        }
        else
        {
            return &a[first];
        }
    }
};

int main()
{
    // initializing the random number generator with the current time seed
    srand(time(0));

    // declaring the size of the random arrays
    const int size = 130000;

    cout << "Testing the algorithms against random arrays of size " << size << endl
         << endl;

    // creating a Sorter object
    Sorter sorter;

    // implementing Bubble Sort
    cout << "Implementing Bubble Sort took ";
    // declaring an array
    int array1[size];
    for (int i = 0; i < size; i++)
    {
        array1[i] = rand() % 100;
    }
    // calling the bubble sort method of the Sorter and computing the time it takes to sort the array
    clock_t startTime = clock();
    int *sorted = sorter.BubbleSort(array1, size);
    cout << double(clock() - startTime) / CLOCKS_PER_SEC * 1000 << " milliseconds" << endl;

    // implementing Selection Sort
    cout << "Implementing Selection Sort took ";
    // declaring an array
    int array2[size];
    for (int i = 0; i < size; i++)
    {
        array2[i] = rand() % 100;
    }
    // calling the Selection Sort method of the Sorter and computing the time it takes to sort the array
    startTime = clock();
    sorted = sorter.SelectionSort(array2, size);
    cout << double(clock() - startTime) / CLOCKS_PER_SEC * 1000 << " milliseconds" << endl;

    // implementing Insertion Sort
    cout << "Implementing Insertion Sort took ";
    // declaring an array
    int array3[size];
    for (int i = 0; i < size; i++)
    {
        array3[i] = rand() % 100;
    }
    // calling the Insertion Sort method of the Sorter and computing the time it takes to sort the array
    startTime = clock();
    sorted = sorter.InsertionSort(array3, size);
    cout << double(clock() - startTime) / CLOCKS_PER_SEC * 1000 << " milliseconds" << endl;

    // implementing Merge Sort
    cout << "Implementing Merge Sort took ";
    // declaring an array
    int array4[size];
    for (int i = 0; i < size; i++)
    {
        array4[i] = rand() % 100;
    }
    // calling the Insertion Sort method of the Sorter and computing the time it takes to sort the array
    startTime = clock();
    sorted = sorter.MergeSort(array4, 0, size - 1);
    cout << double(clock() - startTime) / CLOCKS_PER_SEC * 1000 << " milliseconds" << endl;
}