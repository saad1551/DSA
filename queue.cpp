#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class Queue {
    private:
    Node* head;
    Node* tail;

    public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int d) {
        Node* newNode = new Node(d);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Empty queue" << endl;
            return -2;
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        int data = temp->data;
        delete temp;
        return data;
    }

    int peak() {
        if(isEmpty()) {
            cout << "Empty queue" << endl;
            return -2;
        }
        return head->data;
    }

    bool isEmpty() {
        if (head == nullptr && tail == nullptr)
        {
            return true;
        }
        return false;
    }
};

int main() {
    Queue queue;

    queue.push(4);
    queue.push(8);
    queue.push(12);
    queue.push(16);

    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.peak() << endl;
    cout << queue.peak() << endl;
    cout << queue.pop() << endl;
    cout << queue.peak() << endl;
}