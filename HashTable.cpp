#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *front;
    Node *back;
    LinkedList()
    {
        front = nullptr;
        back = nullptr;
    }
    void Insert(int number)
    {
        Node *newNode = new Node(number);
        if (front == nullptr)
        {
            front = newNode;
            back = front;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
    }
};

class HashTable
{
public:
    LinkedList table[10];
    int Hash(int number)
    {
        return number % 10;
    }
    void Insert(int number)
    {
        int key = Hash(number);
        table[key].Insert(number);
    }
    void Display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << i << ": ";
            Node* head = table[i].front;
            while (head != nullptr)
            {
                cout << head->data << " ";
                head = head->next;
            }
            cout << endl;
        }
    }
};

int main(void)
{
    int array[] = {534, 415, 465, 459, 869, 442, 840, 180, 450, 265, 23, 946, 657, 3, 29};
    HashTable table;
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        table.Insert(array[i]);
    }
    table.Display();
}