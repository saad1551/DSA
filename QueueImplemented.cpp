#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* back;
public:
    Queue () {
        front = nullptr;
        back = nullptr;
    }
    void Enqueue(int d) {
        Node* newNode = new Node;
        newNode->data = d;
        newNode->next = nullptr;
        if (front == nullptr) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
    }

    int Dequeue() {
        int d = front->data;
        Node* obsoleteNode = front;
        front = front->next;
        delete obsoleteNode;
        return d;
    }

    int Peek () {
        int d = front->data;
        return d;
    }
};

int main() {
    Queue queue;
    queue.Enqueue(4);
    queue.Enqueue(15);
    queue.Enqueue(7);

    cout << queue.Dequeue() << endl;
    cout << queue.Dequeue() << endl;
    cout << queue.Dequeue() << endl;

    queue.Enqueue(3);
    queue.Enqueue(6);
    queue.Enqueue(19);

    cout << queue.Dequeue() << endl;
    cout << queue.Dequeue() << endl;

    queue.Enqueue(41);

    cout << queue.Dequeue() << endl;
    cout << queue.Dequeue() << endl;

}

