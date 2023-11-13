#include <iostream>

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
	// creating a Sorter object
	Sorter sorter;

	// implementing Bubble Sort
	cout << "Implementing Bubble Sort" << endl;
	// declaring an array
	int array1[] = {4, 9, 2, 1, 14, 3, 0};
	// storing the size of the array
	int size = sizeof(array1) / sizeof(int);
	// printing the original array
	cout << "The original array is: ";
	for (int i = 0; i < size; i++)
	{
		cout << array1[i] << ", ";
	}
	cout << endl;
	// calling the bubble sort method of the Sorter
	int *sorted = sorter.BubbleSort(array1, size);
	// printing the sorted array
	cout << "sorted using Bubble Sort: ";
	for (int i = 0; i < size; i++)
	{
		cout << array1[i] << ", ";
	}
	cout << endl
		 << endl;

	// implementing Selection Sort
	cout << "Implementing Selection Sort" << endl;
	// declaring an array
	int array2[] = {19, 2, 1, 31, 5, 21, 4};
	// storing the size of the array
	size = sizeof(array2) / sizeof(int);
	// printing the original array
	cout << "The original array is: ";
	for (int i = 0; i < size; i++)
	{
		cout << array2[i] << ", ";
	}
	cout << endl;
	// calling the Selection Sort method of the Sorter
	sorted = sorter.SelectionSort(array2, size);
	// printing the sorted array
	cout << "sorted using Selection Sort: ";
	for (int i = 0; i < size; i++)
	{
		cout << array2[i] << ", ";
	}
	cout << endl
		 << endl;

	// implementing Insertion Sort
	cout << "Implementing Insertion Sort" << endl;
	// declaring an array
	int array3[] = {25, 3, 1, 94, 15, 20, 4, 27};
	// storing the size of the array
	size = sizeof(array3) / sizeof(int);
	// printing the original array
	cout << "The original array is: ";
	for (int i = 0; i < size; i++)
	{
		cout << array3[i] << ", ";
	}
	cout << endl;
	// calling the Insertion Sort method of the Sorter
	sorted = sorter.InsertionSort(array3, size);
	// printing the sorted array
	cout << "sorted using Insertion Sort: ";
	for (int i = 0; i < size; i++)
	{
		cout << array3[i] << ", ";
	}
	cout << endl
		 << endl;

	// implementing Merge Sort
	cout << "Implementing Merge Sort" << endl;
	// declaring an array
	int array4[] = {100,20,15,87,78,95,4,3,12,35};
	// storing the size of the array
	size = sizeof(array4) / sizeof(int);
	// printing the original array
	cout << "The original array is: ";
	for (int i = 0; i < size; i++)
	{
		cout << array4[i] << ", ";
	}
	cout << endl;
	// calling the Merge Sort method of the Sorter
	sorted = sorter.MergeSort(array4, 0, size - 1);
	// printing the sorted array
	cout << "sorted using Merge Sort: ";
	for (int i = 0; i < size; i++)
	{
		cout << sorted[i] << ", ";
	}
	cout << endl
		 << endl;
}