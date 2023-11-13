#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    char array[50];
    int top;
public:
    Stack() {
        top = 0;
    }
    void Push(char a) {
        if (!isFull()) {
            array[top++] = a;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }
    char Pop() {
        if (!isEmpty()) {
            return array[--top];
        } else {
            cout << "Stack Underflow" << endl;
            return 'u';
        }

    }
    bool isEmpty() {
        return (top == 0);
    }
    bool isFull() {
        return (top == 50);
    }
};

int main(void) {
    Stack stack;
    cout << "Enter a string (of maximum length 20): ";
    string s;
    cin >> s;
    if (s.length() > 50) {
        cout << "The string is too large" << endl;
        return 1;
    }
    for (int i = 0; i < s.length(); i++) {
        stack.Push(s[i]);
    }

    while (!stack.isEmpty()) {
        cout << stack.Pop();
    }
    
}