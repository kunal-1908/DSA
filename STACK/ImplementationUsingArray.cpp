#include<iostream>
using namespace std;

class stack {
    public:
    int *arr;
    int top;
    int capacity;

    stack(int size) {
        this->capacity = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if (capacity - top > 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "stack overflow." << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "stack is empty." << endl;
            return;
        } else {
            cout << arr[top] << endl;
            top--;
        }
    }

    int peek() {
        if (top == -1) {
            cout << "stack underflow." << endl;
            return -1;
        } else {
            return arr[top];
        }
    }

    bool isempty() {
        return top == -1;
    }
};

int main() {
    stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    while (!s.isempty()) {
        cout << "Top element: " << s.peek() << endl;
        s.pop();
    }

    return 0;
}
