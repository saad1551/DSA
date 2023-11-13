#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = 0;
    }

    void insertAtHead(int new_value)
    {
        if (head == nullptr)
        {
            head = new Node(new_value);
        }
        else
        {
            Node *temp = new Node(new_value);
            temp->next = head;
            head = temp;
        }
    }

    void insertAtLocation(int location, int new_value)
    {
        Node *temp = head;
        for (int i = 1; i < location; i++)
        {
            if (temp->next != nullptr)
            {
                temp = temp->next;
            }
            else
            {
                temp->next = new Node(0);
                temp = temp->next;
            }
        }

        temp->data = new_value;
    }

    void Delete(int del_value)
    {
        if (del_value != 1)
        {
            Node *temp = head;
            for (int i = 1; i < del_value; i++)
            {
                temp = temp->next;
            }
            Node *temp2 = temp->next;
            temp->next = temp->next->next;
            delete (temp2);
        }

        else
        {
            Node *temp = head;
            head = head->next;
            delete (temp);
        }
    }

    void displayList()
    {
        Node *temp = head;
        cout << endl
             << endl
             << endl;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl
             << endl
             << endl;
    }

    void countList()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        cout << "\n\nThere are " << count << " nodes in the list" << endl
             << endl
             << endl;
    }
};

void insertAtPosition(LinkedList list)
{
    int l;
    cout << "Enter the location to insert a value at: ";
    cin >> l;
    int val;
    cout << "Enter the value to insert: ";
    cin >> val;
    list.insertAtLocation(l, val);
}

void deleteFromLocation(LinkedList list)
{
    int l;
    cout << "Enter the location to delete a value from: ";
    cin >> l;
    list.Delete(l);
}

int main()
{
    LinkedList list;

    char i = NULL;

    while (i != '6')
    {
        cout << endl
             << endl
             << endl;
        cout << "Choose a function to call on the linked list" << endl;
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at a location" << endl;
        cout << "3.Delete from a location" << endl;
        cout << "4. Display the entire list" << endl;
        cout << "5. Count the nodes in the list" << endl;
        cout << "End the program" << endl;
        cin >> i;

        switch (i)
        {
        case '1':
            int val;
            cout << "Enter the value to insert: ";
            cin >> val;
            list.insertAtHead(val);
            break;
        case '2':
            insertAtPosition(list);
            break;
        case '3':
            deleteFromLocation(list);
            break;
        case '4':
            list.displayList();
            break;
        case '5':
            list.countList();
            break;
        case '6':
            return 0;
        }
    }
}
