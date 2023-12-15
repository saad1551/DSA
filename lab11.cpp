#include <iostream>
#include <math.h>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

class Heap
{
public:
    int values[30];
    int size;

public:
    Heap()
    {
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == 30;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Heap is empty!\n";
            return -1;
        }
        else
        {
            return values[1];
        }
    }

    void push(int value)
    {
        // print the error if the heap is full
        if (size >= 30)
        {
            cout << "Heap is full\n";
            return;
        }
        // increment the size by 1 and place the newly entered value in the array
        values[++size] = value;
    }

    void heapify(int index)
    {
        if (index <= size / 2)
        {
            // set the swapping index to the left child of the current node
            int swapIndex = 2 * index;
            // if the left child is greater than the right child, then set the swapping index to right child
            if (values[swapIndex + 1] < values[swapIndex])
            {
                swapIndex++;
            }
            // if the value of the node is greater than the smaller of its children, then swap the values of the two nodes and start maintaining the heap from the swapped index again
            if (values[index] > values[swapIndex])
            {
                swap(values[index], values[swapIndex]);
                heapify(swapIndex);
            }
        }
    }

    void buildheap()
    {
        for (int i = size / 2; i >= 1; i--)
        {
            heapify(i);
        }
    }
    void buildheapfromarray(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
            push(arr[i]);
        buildheap();
    }

    void deleteMin()
    {
        // replace the element at the top with the last element of the heap
        values[1] = values[size--];
        // repair the heap property
        buildheap();
    }

    int pop(int index)
    {
        if (index < 1 || index > size)
        {
            cout << "Invalid index!\n";
            return -1;
        }
        else
        {
            // storing the top element in a temp variable
            int temp = values[index];
            if (index == 1)
            {
                deleteMin();
                return temp;
            }
            // delete the top element
            values[index] = values[size--];
            // repair the heap property
            buildheap();
            // return the popped element
            return temp;
        }
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Heap is empty!\n";
            return;
        }
        for (int i = 1; i <= size; i++)
        {
            cout << values[i] << " ";
            if (i == 1 || i == 3 || i == 7 || i == 15)
                cout << endl;
        }
        cout << endl;
    }

    int getSize()
    {
        return size;
    }
    int getHeight()
    {
        // return -1 as the height if the tree is empty
        if (size == 0)
        {
            return -1;
        }
        // the height of a non empty complete binary tree is the log base 2 of the number of nodes in the tree
        return floor(log2(size));
    }
};

int main()
{
    Heap myHeap = Heap();
    const int arraySize = 15;
    int array[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = (rand() % 100) + 1;
        cout << array[i] << " ";
    }
    cout << endl;
    myHeap.buildheapfromarray(array, arraySize);
    // Create a Menu for all functions
    int choice = 0;
    while (choice != 8)
    {
        cout << "Select an operation to perform on the heap\n1. View the heap\n2. View the top element of the heap\n3. Pop from the top of the heap\n4. Pop from a particular index in the heap\n5. Push into the heap\n6. View the size of the heap\n7. View the height of the heap\n8. Exit\n";

        cin >> choice;

        cout << endl
             << endl;

        switch (choice)
        {
        case 1:
            myHeap.print();
            cout << endl;
            break;
        case 2:
            cout << "The element at the top of the heap is " << myHeap.top() << endl
                 << endl;
            break;
        case 3:
            cout << myHeap.pop(1) << endl
                 << endl;
            break;
        case 4:
            int popIndex;
            cout << "Enter the index to pop the element from : ";
            cin >> popIndex;
            cout << myHeap.pop(popIndex);
            cout << endl << endl;
            break;
        case 5:
            int elementToPush;
            cout << "Enter the element to push into the heap: ";
            cin >> elementToPush;
            myHeap.push(elementToPush);
            myHeap.buildheap();
            cout << endl;
            break;
        case 6:
            cout << "The size of the heap is: " << myHeap.getSize() << endl
                 << endl;
            break;
        case 7:
            cout << "The height of the heap tree is: " << myHeap.getHeight() << endl
                 << endl;
            break;
        case 8:
            break;
        default:
            cout << "Wrong choice\n";
            break;
        }
    }
    return 0;
}
