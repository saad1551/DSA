#include <iostream>

using namespace std;

class Stack {
private:
    int array[50];
    int top;
public:
    Stack() {
        top = 0;
    }
    void Push(int a) {
        if (!isFull()) {
            array[top++] = a;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }
    int Pop() {
        if (!isEmpty()) {
            return array[--top];
        } else {
            cout << "Stack Underflow" << endl;
            return -99;
        }

    }
    bool isEmpty() {
        return (top == 0);
    }
    bool isFull() {
        return (top == 50);
    }
};

bool isOperator(char a) {
    if (a == '+' || a == '-' || a == '*') {
        return true;
    } else {
        return false;
    }
}

int evaluate(int a, int b, char op) {
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return b - a;
    } 
    return a * b;
}

int main() {
    Stack stack;
    string expression = "123+456*-7*+-89*+";
    for (int i = 0; i < expression.length(); i++) {
        if (!isOperator(expression[i])) {
            stack.Push((int(expression[i]) - int('0')));
        } else {
            int a = stack.Pop();
            int b = stack.Pop();
            int result = evaluate(a, b, expression[i]);
            stack.Push(result);
        }
    }

    cout << stack.Pop() << endl;
}