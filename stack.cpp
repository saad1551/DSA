#include <iostream>

using namespace std;

class Stack {
    private:
    int data[100];
    int counter;

    public:
    Stack() {
        counter = 0;
    }
    void push(int d) {
        if (isFull()) {
            cout << "Stack overflow";
            return;
        }
        data[counter++] = d;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow";
            return -999;
        }
        return data[--counter];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack underflow";
            return -999;
        }
        return data[counter - 1];
    }

    bool isEmpty() {
        return counter <= 0;
    }

    bool isFull () {
        return counter >= 100;
    }
};


int main() {
    Stack stack;

    stack.push(5);
    stack.push(9);
    stack.push(15);

    cout << "The most recently added item in the stack is " << stack.pop() << endl;
    cout << "The item at the top of the stack is " << stack.pop() << endl;
    cout << "The item at the top of the stack is " << stack.pop();
    cout << "The item at the top of the stakc is " << stack.pop();
}

