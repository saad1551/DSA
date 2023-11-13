#include <iostream>
#include <string>

using namespace std;

class Stack {
    private:
    char arr[100];
    int top;
    
    public:
    Stack() {
        top = 0;
    }

    void Push(char element) {
        arr[top++] = element;
    }

    char Pop() {
        return arr[--top];
    }

    bool isEmpty() {
        return (top <= 0);
    }

    bool isFull() {
        return (top > 100);
    }

    void Clear() {
        top = 0;
    }

    char Peak() {
        return arr[top-1];
    }

};

int main() {
    Stack stack;

    string expression;
    cout << "Enter an expression to validate: ";
    getline(cin, expression);

    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            stack.Push(expression[i]);
        }

        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            stack.Pop();
        }
    }

    if (stack.isEmpty()) {
        cout << "The expression is correct\n";
    } else {
        cout << "The expression is incorrect\n";
    }
}