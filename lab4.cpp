#include <iostream>
#include <string>

using namespace std;

class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack()
    {
        top = 0;
    }

    void Push(int element)
    {
        arr[top++] = element;
    }

    char Pop()
    {
        return arr[--top];
    }

    bool isEmpty()
    {
        return (top <= 0);
    }

    bool isFull()
    {
        return (top > 100);
    }

    void Clear()
    {
        top = 0;
    }

    int Peak()
    {
        return arr[top - 1];
    }
};

int main()
{
    Stack stack;

    string expression;
    cout << "Enter an expression to validate: ";
    getline(cin, expression);

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            stack.Push(i);
        }

        else if (expression[i] == ')')
        {
            if (expression[stack.Peak()] == '(') {
                stack.Pop();
            } else {
                cout << "The expression is not correct. Error at character# " << stack.Peak() + 1 << ". '" << expression[stack.Peak()] <<"' not closed";
                return 1;
            }
        }
        else if (expression[i] == '}')
        {
            if (expression[stack.Peak()] == '{') {
                stack.Pop();
            } else {
                cout << "The expression is not correct. Error at character#" << stack.Peak() + 1 << ". '" << expression[stack.Peak()] <<"' not closed";
                return 1;
            }
        }
        else if (expression[i] == ']')
        {
            if (expression[stack.Peak()] == '[') {
                stack.Pop();
            } else {
                cout << "The expression is not correct. Error at character#" << stack.Peak() + 1 << ". '" << expression[stack.Peak()] <<"' not closed";
                return 1;
            }
        }
    }

    if (stack.isEmpty())
    {
        cout << "The expression is correct\n";
    }
}